#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
const int N = 205;
const int L = 10;
const int M = 1000000007;
int prob[N][N];
int up[N][L];
bitset<N> used;
int d[N];
int par[N];
vector<int> g[N];

void dfs(int v, int p) {
  used[v] = true;
  par[v] = p;
  for (auto u : g[v]) {
    if (!used[u]) {
      d[u] = d[v] + 1;
      dfs(u, v);
    }
  }
}

int lca(int a, int b) {
  if (d[a] > d[b]) swap(a, b);
  int dif = d[b] - d[a];
  for (int l = L - 1; l >= 0; l--) {
    if (dif >= (1 << l)) {
      dif -= (1 << l);
      b = up[b][l];
    }
  }
  if (a == b) {
    return a;
  }
  for (int l = L - 1; l >= 0; l--) {
    if (up[a][l] != up[b][l]) {
      a = up[a][l];
      b = up[b][l];
    }
  }
  return par[a];
}

int binpow(int a, int x) {
  int ans = 1;
  while (x) {
    if (x % 2) {
      ans *= a;
      ans %= M;
    }
    a *= a;
    a %= M;
    x /= 2;
  }
  return ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  for (int x = 1; x < N; x++) {
    for (int y = 1; y < N; y++) {
      if (x == 1 && y == 1) {
        prob[x][y] = binpow(2, M - 2);
      } else if (x == 1) {
        prob[x][y] = binpow(2, M - 2) * (1 + prob[x][y - 1]) % M;
      } else if (y == 1) {
        prob[x][y] = (binpow(2, M - 2) * prob[x - 1][y]) % M;
      } else {
        prob[x][y] = (binpow(2, M - 2) * (prob[x - 1][y] + prob[x][y - 1] % M)) % M;
      }
    }
  }
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].pb(b);
    g[b].pb(a);
  }
  int ans = 0;
  for (int v = 0; v < n; v++) {
    used.reset();
    d[v] = 0;
    dfs(v, v);
    for (int x = 0; x < n; x++) {
      up[x][0] = par[x];
    }
    for (int l = 1; l < L; l++) {
      for (int x = 0; x < n; x++) {
        up[x][l] = up[up[x][l - 1]][l - 1];
      }
    }
    int bim = 0;
    bim += v;
    for (int a = 0; a < n; a++) {
      for (int b = a + 1; b < n; b++) {
        if (a != v && b != v) {
          int l = lca(a, b);
          int da = d[a] - d[l], db = d[b] - d[l];
          if (db == 0) {
            bim++;
          } else if (da != 0) {
            bim += prob[db][da];
          }
        }
      }
    }
    bim %= M;
    bim *= binpow(n, M - 2);
    bim %= M;
    ans += bim;
  }

  ans %= M;
  cout << ans << '\n';
}