#include <bits/stdc++.h>

using namespace std;

const int md = (int) 1e9 + 7;

inline void add(int &x, int y) {
  x += y;
  if (x >= md) {
    x -= md;
  }
}

inline void sub(int &x, int y) {
  x -= y;
  if (x < 0) {
    x += md;
  }
}

inline int mul(int x, int y) {
  return (long long) x * y % md;
}

inline int power(int x, int y) {
  int res = 1;
  for (; y; y >>= 1, x = mul(x, x)) {
    if (y & 1) {
      res = mul(res, x);
    }
  }
  return res;
}

inline int inv(int a) {
  a %= md;
  if (a < 0) {
    a += md;
  }
  int b = md, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  if (u < 0) {
    u += md;
  }
  return u;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  vector<int> fact(max(n, m)), inv_fact(max(n, m));
  fact[0] = fact[1] = inv_fact[0] = inv_fact[1] = 1;
  for (int i = 2; i < max(n, m); ++i) {
    fact[i] = mul(fact[i - 1], i);
    inv_fact[i] = mul(md - md / i, inv_fact[md % i]);
  }
  for (int i = 2; i < max(n, m); ++i) {
    inv_fact[i] = mul(inv_fact[i - 1], inv_fact[i]);
  }
  vector<int> power_n(n), power_m(n);
  power_n[0] = power_m[0] = 1;
  for (int i = 1; i < n; ++i) {
    power_n[i] = mul(power_n[i - 1], n);
    power_m[i] = mul(power_m[i - 1], m);
  }
  int ans = 0;
  for (int i = 1; i < n && i <= m; ++i) {
    int coef = 1;
    coef = mul(coef, mul(fact[m - 1], mul(inv_fact[i - 1], inv_fact[m - i])));
    coef = mul(coef, mul(fact[n - 2], inv_fact[n - i - 1]));
    if (i < n - 1) {
      coef = mul(coef, mul(i + 1, power_n[n - i - 2]));
    }
    coef = mul(coef, power_m[n - i - 1]);
    add(ans, coef);
  }
  cout << ans << "\n";
  return 0;
}