#include <bits/stdc++.h>

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
const int M = 998244353;
const int N = 200500;
int lcd[N];
vector<int> fact[N];
vector<array<int, 3>> g[N];
int ss = 0;
int inv[N];
map<int, int> max_prime, bal;
bitset<N> used;
int val = 1;

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

void dfs(int v) {
  ss += val;
  used[v] = true;
  for (auto u: g[v]) {
    if (!used[u[0]]) {

      for (auto p: fact[u[1]]) {
        bal[p]++;
      }

      for (auto p: fact[u[2]]) {
        bal[p]--;
        max_prime[p] = min(max_prime[p], bal[p]);
      }

      val *= u[1];
      val %= M;
      val *= inv[u[2]];
      val %= M;

      dfs(u[0]);

      val *= u[2];
      val %= M;
      val *= inv[u[1]];
      val %= M;

      for (auto p: fact[u[1]]) {
        bal[p]--;
      }

      for (auto p: fact[u[2]]) {
        bal[p]++;
      }

    }
  }
}

void solve() {
  int n;
  cin >> n;
  for (int v = 0; v < n; v++) {
    g[v] = {};
  }
  for (int _ = 0; _ < n - 1; _++) {
    int i, j, x, y;
    cin >> i >> j >> x >> y;
    i--;
    j--;
    int gg = gcd(x, y);
    x /= gg;
    y /= gg;
    g[i].pb({j, y, x});
    g[j].pb({i, x, y});
  }
  ss = 0;
  max_prime = {};
  used.reset();
  val = 1;
  dfs(0);
  ss %= M;
  int e = 1;
  for (auto pr: max_prime) {
    if (pr.second < 0) {
      for (int _ = 0; _ < -pr.second; _++) {
        e *= pr.first;
        e %= M;
      }
    }
  }
  e *= ss;
  e %= M;
  cout << e << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  lcd[1] = 1;
  for (int v = 2; v < N; v++) {
    if (lcd[v] == 0) {
      for (int u = v; u < N; u += v) {
        lcd[u] = v;
      }
    }
  }

  for (int v = 2; v < N; v++) {
    fact[v].pb(lcd[v]);
    for (auto x: fact[v / lcd[v]]) {
      fact[v].pb(x);
    }
  }

  for (int v = 1; v < N; v++) {
    inv[v] = binpow(v, M - 2);
  }

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}