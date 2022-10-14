#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
const int N = 100500;
int L[N], R[N];
vector<int> g[N];
bitset<N> used;
int dpl[N], dpr[N];

void dfs(int v) {
  used[v] = true;
  for (auto u : g[v]) {
    if (!used[u]) {
      dfs(u);
      dpl[v] += max(dpl[u] + abs(L[u] - L[v]), dpr[u] + abs(R[u] - L[v]));
      dpr[v] += max(dpl[u] + abs(L[u] - R[v]), dpr[u] + abs(R[u] - R[v]));
    }
  }
}

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> L[i] >> R[i];
    g[i] = {};
    dpl[i] = 0;
    dpr[i] = 0;
  }
  used.reset();
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].pb(b);
    g[b].pb(a);
  }
  dfs(0);
  cout << max(dpl[0], dpr[0]);
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}