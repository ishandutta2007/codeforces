#include <bits/stdc++.h>

using namespace std;

const int md = 998244353;

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
  return (int) ((long long) x * y % md);
}

inline int power(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) {
      res = mul(res, x);
    }
    x = mul(x, x);
    y >>= 1;
  }
  return res;
}

inline int inv(int a) {
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
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, x, y, z;
  cin >> n >> m >> x >> y >> z;
  vector<int> foo(1 << m), bar(1 << m), baz(1 << m);
  int xor_all = 0;
  for (int i = 0; i < n; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    a ^= c;
    b ^= c;
    xor_all ^= c;
    ++foo[a];
    ++bar[b];
    ++baz[a ^ b];
  }
  auto fwt = [&](vector<int> &a) {
    for (int i = 1; i < 1 << m; i <<= 1) {
      for (int j = 0; j < 1 << m; j += i << 1) {
        for (int k = 0; k < i; ++k) {
          int u = a[j + k], v = a[j + k + i];
          a[j + k] = a[j + k + i] = u;
          add(a[j + k], v);
          sub(a[j + k + i], v);
        }
      }
    }
  };
  fwt(foo);
  fwt(bar);
  fwt(baz);
  vector<int> ans(1 << m);
  for (int i = 0; i < 1 << m; ++i) {
    add(foo[i], n);
    add(bar[i], n);
    add(baz[i], n);
    int a = mul(foo[i], (md + 1) / 2);
    int b = mul(bar[i], (md + 1) / 2);
    int c = mul(baz[i], (md + 1) / 2);
    int d = (a + b + c - n) / 2;
    int e = a - d;
    int f = b - d;
    int g = c - d;
    ans[i] = 1;
    ans[i] = mul(ans[i], power(((x + y) % md + z) % md, d));
    ans[i] = mul(ans[i], power(((x + md - y) % md + z) % md, e));
    ans[i] = mul(ans[i], power(((md - x + y) % md + z) % md, f));
    ans[i] = mul(ans[i], power(((md - x + md - y) % md + z) % md, g));
  }
  fwt(ans);
  int inv_n = inv(1 << m);
  for (int i = 0; i < 1 << m; ++i) {
    if (i) {
      cout << " ";
    }
    cout << mul(inv_n, ans[xor_all ^ i]);
  }
  cout << "\n";
  return 0;
}