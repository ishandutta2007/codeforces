#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

const int G = 3;
const int mod = 998244353;
const int N = (1 << 20) + 5;

int rev[N], w[N], inv_n;

int bigmod (int a, int e, int mod) {
  if (e == -1) e = mod - 2;
  int ret = 1;
  while (e) {
    if (e & 1) ret = (ll) ret * a % mod;
    a = (ll) a * a % mod; e >>= 1;
  }
  return ret;
}

void prepare (int n) {
  int sz = abs(31 - __builtin_clz(n));
  int r = bigmod(G, (mod - 1) / n, mod);
  inv_n = bigmod(n, mod - 2, mod), w[0] = w[n] = 1;
  for (int i = 1; i < n; ++i) w[i] = (ll) w[i - 1] * r % mod;
  for (int i = 1; i < n; ++i) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (sz - 1));
}

void ntt (int *a, int n, int dir) {
  for (int i = 1; i < n - 1; ++i) {
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  }
  for (int m = 2; m <= n; m <<= 1) {
    for (int i = 0; i < n; i += m) {
      for (int j = 0; j < (m >> 1); ++j) {
        int &u = a[i + j], &v = a[i + j + (m >> 1)];
        int t = (ll) v * w[dir ? n - n / m * j : n / m * j] % mod;
        v = u - t < 0 ? u - t + mod : u - t;
        u = u + t >= mod ? u + t - mod : u + t;
      }
    }
  } if (dir) for (int i = 0; i < n; ++i) a[i] = (ll) a[i] * inv_n % mod;
}

int f_a[N], f_b[N];

vector <int> multiply (vector <int> a, vector <int> b) {
  int sz = 1, n = a.size(), m = b.size();
  while (sz < n + m - 1) sz <<= 1; prepare(sz);
  for (int i = 0; i < sz; ++i) f_a[i] = i < n ? a[i] : 0;
  for (int i = 0; i < sz; ++i) f_b[i] = i < m ? b[i] : 0;
  ntt(f_a, sz, 0); ntt(f_b, sz, 0);
  for (int i = 0; i < sz; ++i) f_a[i] = (ll) f_a[i] * f_b[i] % mod;
  ntt(f_a, sz, 1); return vector <int> (f_a, f_a + n + m - 1);
}

ll fac[sz], finv[sz], inv[sz];

void prec() {
   inv[0] = inv[1] = 1;
   for(int i=2; i<sz; i++)
      inv[i] = mod - mod / i * inv[mod % i] % mod;
   fac[0] = finv[0] = 1;
   for(int i=1; i<sz; i++) {
      fac[i] = fac[i-1] * i % mod;
      finv[i] = finv[i-1] * inv[i] % mod;
   }
}

inline int cmb(int n, int r) {
   if(n < r) return 0;
   ll d = finv[r] * finv[n-r] % mod;
   return fac[n] * d % mod;
}

int main() {
   prec();
   int n;
   cin >> n;
   vector <int> now(1, 1);
   for(int i=0; i<n; i++) {
      int a, b, k = now.size();
      scanf("%d %d", &a, &b);
      if(k >= b) {
         int z = a + b;
         vector <int> cc(z + 1);
         for(int i=0; i<=z; i++) cc[i] = cmb(z, i);
         now = multiply(now, cc);
         for(int i=0, j=b; j<now.size()-b; i++, j++) now[i] = now[j];
         now.resize(now.size() - 2 * b);
      }
      else {
         vector <int> cc(a - b + 2 * k);
         for(int i=0; i<cc.size(); i++) cc[i] = cmb(a + b, b - k + i);
         now = multiply(now, cc);
         int z = k + a - b;
         for(int i=0, j=k; i<z; i++, j++) now[i] = now[j];
         now.resize(z);
      }
   }
   int ans = 0;
   for(int x : now) ans += x, ans %= mod;
   cout << ans;
}