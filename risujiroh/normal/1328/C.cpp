#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string a, b;
    bool f = false;
    for (char c : s) {
      if (c == '0') {
        a += '0';
        b += '0';
      } else if (c == '1') {
        if (f) {
          a += '0';
          b += '1';
        } else {
          a += '1';
          b += '0';
        }
        f = true;
      } else {
        if (f) {
          a += '0';
          b += '2';
        } else {
          a += '1';
          b += '1';
        }
      }
    }
    cout << a << '\n';
    cout << b << '\n';
  }
}