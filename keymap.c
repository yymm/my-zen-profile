#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  RGBRST
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------.              .-----------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |              |   6  |   7  |   8  |   9  |   0  |  -_  |
   * |------+------+------+------+------+------|              |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |              |   Y  |   U  |   I  |   O  |   P  |  =+  |
   * |------+------+------+------+------+------|              |------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |              |   H  |   J  |   K  |   L  |   ;  |  "'  |
   * |------+------+------+------+------+------|              |------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |              |   N  |   M  |   ,  |   .  |   /  | Tab  |
   * |------+------+------+------+------+------+------..------+------+------+------+------+------+------|
   * | GUI  | Alt  |RGBRST|RGBTOG| Alt  |RAISE |Space ||Bksp  |Enter | Left | DOWN |  Up  | RGHT |RAISE |
   * `------------------------------------------------''------------------------------------------------'
   */
  [_QWERTY] = LAYOUT( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,   KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,   KC_U,    KC_I,    KC_O,   KC_P,    KC_EQL,  \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,   KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,   KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_TAB,  \
    KC_LGUI, KC_LALT, RGBRST,  RGB_TOG, KC_LALT, RAISE, LT(_LOWER,KC_SPC), KC_BSPC,  KC_ENT, KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, KC_RALT  \
  ),

  /* LOWER
   * ,-----------------------------------------.             .-----------------------------------------.
   * |      |  !   |  @   |  #   |  $   |  %   |             |  ^   |  &   |  *   |  (   |  )   |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  |  F10 |  F11 | F12  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |  `~  |  \|  |             | Left | Down |  Up  | Rght |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |  [{  |             |  ]}  |      |      |      |      |      |
   * |------+------+------+------+------+------+------..-----+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      ||     |      |      |      |      |      |      |
   * `------------------------------------------------''-----------------------------------------------'
   */
  [_LOWER] = LAYOUT( \
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
    _______, _______, _______, _______, KC_GRV,  KC_BSLS,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,  _______, \
    _______, _______, _______, _______, _______, KC_LBRC,                   KC_RBRC, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
  ),

  /* RAISE
   * ,-----------------------------------------.             .-----------------------------------------.
   * |      |  !   |  @   |  #   |  $   |  %   |             |  ^   |  &   |  *   |  (   |  )   |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |RGBMOD|RGBHUI|RGBVAI|RGBSAI|      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |RGBRMD|RGBHUD|RGBVAD|RGBSAD|  `~  |  \|  |             | MS_L | MS_D | MS_U | MS_R | MSWU | MSWD |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |  [{  |             | MSCL | MSCR |      | Pause| Back | Next |
   * |------+------+------+------+------+------+------..-----+------+------+------+------+------+------|
   * | RESET|      |      |      |      |      |      ||     |      |      |      | Mute | VOLUP| VOLDN|
   * `------------------------------------------------''-----------------------------------------------'
   */
  [_RAISE] = LAYOUT( \
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
    RGB_MOD, RGB_HUI, RGB_VAI, RGB_SAI, _______, _______,                 _______, _______, _______, _______, _______, _______, \
    RGB_RMOD,RGB_HUD, RGB_VAD, RGB_SAD, KC_GRV,  KC_BSLS,                   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_WH_U, KC_WH_D, \
    _______, _______, _______, _______, _______, KC_LBRC,                   KC_BTN1, KC_BTN2, _______, KC_MPLY, KC_MPRV, KC_MNXT, \
    RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLU, KC_VOLD  \
  ),

};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
      if (record->event.pressed) {
        eeconfig_update_rgblight_default();
        rgblight_enable();
      }
      #endif
      break;
    // case ADJUST:
    //     if (record->event.pressed) {
    //       layer_on(_ADJUST);
    //     } else {
    //       layer_off(_ADJUST);
    //     }
    //     return false;
    //     break;
  }
  return true;
}
