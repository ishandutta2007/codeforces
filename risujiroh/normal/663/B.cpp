#include <bits/extc++.h>

#ifndef DUMP
#define DUMP(...) (void)0
#endif

using namespace std;

template <class T, class Op = multiplies<T>>
constexpr T power(T a, int64_t n, Op op = Op(), T e = {1}) {
  assert(n >= 0);
  while (n) {
    if (n & 1) e = op(e, a);
    if (n >>= 1) a = op(a, a);
  }
  return e;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    s = s.substr(4);
    int len = size(s), res = 1988;
    for (int i = 0; i < len; ++i) {
      res += power(10, i);
    }
    res -= stoi(s);
    res += power(10, len) - 1;
    res /= power(10, len);
    res *= power(10, len);
    res += stoi(s);
    cout << res << '\n';
  }
}