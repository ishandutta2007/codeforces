#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 500500;
const int MOD1 = 1E9 + 7;
const int MOD2 = 1E9 + 7;

typedef pair<ll, ll> pll;
pll hsh[MAXN];
pll rehash(pll a, ll b) {
  return pll((a.first * 69453 + b) % MOD1, (a.second * 53767 + b) % MOD2);
}

ll ar[MAXN];
vector<int> ed[MAXN];

ll gg(ll a, ll b) {
  if (a == 0) return b;
  return gg(b % a, a);
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      ed[i].clear();
      cin >> ar[i];
    }
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      --u; --v;
      ed[v].push_back(u);
    }
    map<pll, ll> sums;
    for(int i = 0; i < n; ++i) {
      vector<int> v = ed[i];
      sort(v.begin(), v.end());
      hsh[i] = pll(0, 0);
      for (int k: v) {
        hsh[i] = rehash(hsh[i], k + 1);
      }
      if (v.size() == 0) continue;
      sums[hsh[i]] += ar[i];
    }

    ll ans = 0;
    for (auto k: sums) {
      ans = gg(ans, k.second);
    }
    cout << ans << "\n";
  }
}