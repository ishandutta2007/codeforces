#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3005;
const int mod = 1e9 + 7;

int n, m, a[N], b[N], sum[N], ifac[N], f[N][N];
vector<int> adj[N];

int add(int x, int y) {
  x += y;
  if (x >= mod) {
    x -= mod;
  }
  return x;
}

int sub(int x, int y) {
  x -= y;
  if (x < 0) {
    x += mod;
  }
  return x;
}

int mul(int x, int y) {
  return (ll)x * y % mod;
}

void dfs(int x) {
  for (int i = 0; i <= n; ++i) {
    f[x][i] = 1;
  }
  for (auto y : adj[x]) {
    dfs(y);
    for (int i = 0; i <= n; ++i) {
      sum[i] = f[y][i];
      if (i) {
        sum[i] = add(sum[i], sum[i - 1]);
      }
    }
    for (int i = 0; i <= n; ++i) {
      f[x][i] = mul(f[x][i], sum[i]);
    }
  }
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  scanf("%d %d", &n, &m);
  --m;
  for (int i = 2; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    adj[x].push_back(i);
  }
  dfs(1);
  for (int i = 0; i <= n; ++i) {
    sum[i] = f[1][i];
    if (i) {
      sum[i] = add(sum[i], sum[i - 1]);
    }
  }
  ifac[0] = ifac[1] = 1;
  for (int i = 2; i <= n; ++i) {
    ifac[i] = mul(mod - mod / i, ifac[mod % i]);
  }
  for (int i = 2; i <= n; ++i) {
    ifac[i] = mul(ifac[i], ifac[i - 1]);
  }
  for (int i = 0, coef = 1; i <= n; ++i) {
    a[i] = coef;
    coef = mul(coef, sub(m, i));
  }
  for (int i = 0, coef = 1; i <= n; ++i) {
    b[i] = coef;
    coef = mul(coef, sub(sub(n, m), i));
  }
  int answer = 0;
  for (int i = 0; i <= n; ++i) {
    answer = add(answer, mul(mul(mul(a[i], b[n - i]), mul(ifac[i], ifac[n - i])), sum[i]));
  }
  printf("%d\n", answer);
  return 0;
}