#include <bits/stdc++.h>

int const N = 1234567;

using namespace std;

int a[N], ds[N], dp[N], from[N], path[N], ans[N];

vector<int> cn[N];

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int mul(int a, int b, int m) {
  return (int) ((long long) a * b % m);
}

int modpow(int a, int b, int m) {
  int ret = 1;
  while (b > 0) {
    if (b & 1) ret = mul(ret, a, m);
    a = mul(a, a, m);
    b >>= 1;
  }
  return ret;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    a[x] = true;
  }
  int phi = 0;
  for (int i = 0; i < m; i++) {
    int g = gcd(i, m);
    if (g == 1) ++phi;
    if (a[i]) continue;
    cn[g].push_back(i);
  }
  int cc = 0;
  for (int i = 1; i * i <= m; i++) {
    if (m % i == 0) {
      ds[cc++] = i;
      if (i * i != m) {
        ds[cc++] = m / i;
      }
    }
  }
  std::sort(ds, ds + cc);
  for (int i = 0; i < cc; i++) {
    int x = (int) cn[ds[i]].size();
    dp[i] = x;
    from[i] = -1;
    for (int j = 0; j < i; j++) {
      if (ds[i] % ds[j] == 0) {
        if (dp[i] < dp[j] + x) {
          dp[i] = dp[j] + x;
          from[i] = j;
        }
      }
    }
  }
  printf("%d\n", dp[cc - 1]);
  int pn = 0;
  for (int i = cc - 1; ; i = from[i]) {
    path[pn++] = ds[i];
    if (i == 0) break;
  }
  std::reverse(path, path + pn);
  int cur = 1;
  int ac = 0;
  for (int i = 0; i < pn; i++) {
    for (int to : cn[path[i]]) {
      int g1 = gcd(cur, m);
      int g2 = gcd(to, m);
      if (g2 == m) {
        ans[ac++] = 0;
      } else {
        ans[ac++] = mul(to / g1, modpow(cur / g1, phi - 1, m), m);
      }
      cur = to;
    }
  }
  // assert(ac == dp[cc - 1]);
  for (int i = 0; i < ac; i++) {
    if (i > 0) putchar(' ');
    printf("%d", ans[i]);
  }
  puts("");
}