// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second

// =========== Book ============ //

// =========== Solution ============= //

int main()  {
  int n;
  cin >> n;
  vector<int> costs[3];
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < n; ++j) {
      int x;
      cin >> x;
      costs[i].push_back(x);
    }
  }

  vector<int> deg(n), s(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    ++deg[u]; ++deg[v];
    s[u] ^= v;
    s[v] ^= u;
  }

  int root = 0;
  for (int i = 0; i < n; ++i) {
    if (deg[i] >= 3) {
      cout << -1 << "\n";
      return 0;
    }
    if (deg[i] == 1) root = i;
  }

  ll ans[6] = {0};
  int mp[6][3] = {
    { 0, 1, 2 },
    { 0, 2, 1 },
    { 1, 0, 2 },
    { 1, 2, 0 },
    { 2, 0, 1 },
    { 2, 1, 0 },
  };

  int cur = root;
  vector<int> path;
  for (int i = 0; i < n; ++i) {
    path.push_back(cur);
    for(int j = 0; j < 6; ++j) {
      ans[j] += costs[mp[j][i % 3]][cur];
    }
    s[s[cur]] ^= cur;
    cur = s[cur];
  }
  ll mn = ans[0];
  int mni = 0;
  for (int i = 0; i < 6; ++i) {
    if (ans[i] < mn) {
      mn = ans[i];
      mni = i;
    }
  }
  cout << mn << "\n";

  vector<int> out(n);
  for (int i = 0; i < n; ++i) {
    out[path[i]] = mp[mni][i % 3];
  }
  for (int i: out) {
    cout << i + 1 << " ";
  }
  cout << "\n";
}