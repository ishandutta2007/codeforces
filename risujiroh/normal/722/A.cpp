#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string type;
  cin >> type;
  string s;
  cin >> s;
  int mn = 5;
  string res;
  if (type == "12") {
    for (int i = 1; i <= 12; ++i) {
      for (int j = 0; j < 60; ++j) {
        auto t = to_string(j);
        while (size(t) < 2) {
          t = "0" + t;
        }
        t = to_string(i) + ":" + t;
        while (size(t) < size(s)) {
          t = "0" + t;
        }
        int cur = 0;
        for (int k = 0; k < 5; ++k) {
          cur += s[k] != t[k];
        }
        if (cur < mn) {
          mn = cur;
          res = t;
        }
      }
    }
  } else {
    for (int i = 0; i < 24; ++i) {
      for (int j = 0; j < 60; ++j) {
        auto t = to_string(j);
        while (size(t) < 2) {
          t = "0" + t;
        }
        t = to_string(i) + ":" + t;
        while (size(t) < size(s)) {
          t = "0" + t;
        }
        int cur = 0;
        for (int k = 0; k < 5; ++k) {
          cur += s[k] != t[k];
        }
        if (cur < mn) {
          mn = cur;
          res = t;
        }
      }
    }
  }
  cout << res << '\n';
}