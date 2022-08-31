#include <bits/stdc++.h>

using namespace std;

const int n = 30;
const string copy_u = "u10dtd";
const string copy_d = "d10utu";
const string copy_l = "l10rtr";

void make_leading_zeros(string x, string y) {
  cout << x << x << "0" << x << "1" << y << y << "10" << y << "t";
  cout << x << x << "t" << x << "e" << x << "e" << y << y;
  cout << y << "10" << x << "t" << x << "e" << y;
}

void make_add_to_up() {
  cout << "u" << copy_u << "u" << copy_u << "dd" << copy_u << "u" << copy_u << "u" << copy_l;
  cout << "010utlt" << copy_d << "dd";
  cout << "0ulrtd";
  cout << "u" << copy_u << "u" << copy_u << "dd" << copy_u << "u" << copy_u << "u" << copy_l;
  cout << "010utlt" << copy_d << "dd";
  cout << "lltr";
}

void make_add_single_bit() {
  cout << "u" << copy_u << "u" << copy_l << "ll0l1rrr";
  make_add_to_up();
  cout << "dd" << copy_u << "u" << copy_u << "u" << copy_l;
  make_add_to_up();
  cout << "dd";
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  for (int i = 0; i < n; ++i) {
    make_leading_zeros("d", "u");
    cout << "l";
  }
  cout << "u";
  for (int i = 0; i < n; ++i) {
    cout << "r";
    make_leading_zeros("u", "d");
  }
  cout << "uu";
  for (int i = 0; i <= n; ++i) {
    cout << "0l";
  }
  for (int i = 0; i <= n; ++i) {
    cout << "r";
  }
  cout << "ddd";
  for (int i = 0; i < n; ++i) {
    make_add_single_bit();
    cout << "l";
  }
  cout << "uuu";
  cout << endl;
  return 0;
}