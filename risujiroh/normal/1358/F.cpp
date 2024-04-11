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
  int n;
  cin >> n;
  vector<long long> a(n), b(n);
  for (auto&& e : a) cin >> e;
  for (auto&& e : b) cin >> e;
  auto inc = [&] {
    for (int i = 1; i < n; ++i) {
      if (b[i - 1] >= b[i]) {
        return false;
      }
    }
    return true;
  };
  auto dec = [&] {
    for (int i = 1; i < n; ++i) {
      if (b[i - 1] <= b[i]) {
        return false;
      }
    }
    return true;
  };
  string res;
  bool f = false;
  auto t = 0LL;
  while (true) {
    if (a == b) {
      break;
    }
    if (vector(rbegin(a), rend(a)) == b) {
      f = true;
      break;
    }
    if (n == 1) {
      cout << "IMPOSSIBLE\n";
      exit(0);
    }
    if (inc()) {
      if (n == 2) {
        auto q = min((b[1] + b[0] - 1) / b[0] - 1, (b[1] - max(a[0], a[1])) / b[0]);
        q = max(q, 1LL);
        b[1] -= q * b[0];
        if (size(res) + q <= (int)2e5) {
          res += string(q, '<');
        } else {
          t += q;
        }
      } else {
        for (int i = n; i-- > 1; ) {
          b[i] -= b[i - 1];
        }
        res += '<';
      }
    } else if (dec()) {
      if (n == 2) {
        auto q = min((b[0] + b[1] - 1) / b[1] - 1, (b[0] - max(a[0], a[1])) / b[1]);
        q = max(q, 1LL);
        b[0] -= q * b[1];
        if (size(res) + q <= (int)2e5) {
          res += string(q, '>');
        } else {
          t += q;
        }
      } else {
        for (int i = 1; i < n; ++i) {
          b[i - 1] -= b[i];
        }
        res += '>';
      }
    } else {
      cout << "IMPOSSIBLE\n";
      exit(0);
    }
  }
  if (size(res) + t > (int)2e5) {
    cout << "BIG\n";
    cout << size(res) + t << '\n';
    exit(0);
  }
  reverse(begin(res), end(res));
  if (f) {
    for (auto&& e : res) {
      e ^= '<' ^ '>';
    }
  }
  string s;
  bool rev = false;
  for (char c : res) {
    if (c == '<') {
      if (rev) {
        s += 'R';
        rev ^= true;
      }
    } else {
      if (not rev) {
        s += 'R';
        rev ^= true;
      }
    }
    s += 'P';
  }
  res = s;
  if (rev != f) {
    res += 'R';
  }
  cout << "SMALL\n";
  cout << size(res) << '\n';
  cout << res << '\n';
}