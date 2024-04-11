#include <bits/stdc++.h>

using namespace std;

class dsu {
 public:
  vector<int> p;
  int n;

  dsu(int n): n(n) {
    p.resize(n);
    for (int i = 0; i < n; ++i) {
      p[i] = i;
    }
  }

  inline int find(int x) {
    while (x != p[x]) {
      x = p[x] = p[p[x]];
    }
    return x;
  }

  inline bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
      return false;
    } else {
      p[x] = y;
      return true;
    }
  }
};

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int from, to;
    cin >> from >> to;
    --from;
    --to;
    adj[from].push_back(to);
    adj[to].push_back(from);
  }
  vector<tuple<int, int, int, int>> e(n);
  int cnt = 0;
  function<void(int, int)> dfs = [&](int x, int p) {
    int from = cnt;
    for (auto y : adj[x]) {
      if (y != p) {
        dfs(y, x);
      }
    }
    if (x && (int) adj[x].size() == 1) {
      ++cnt;
    }
    int to = cnt;
    e[x] = make_tuple(c[x], x, from, to);
  };
  dfs(0, -1);
  dsu p(cnt + 1);
  sort(e.begin(), e.end());
  vector<int> ans;
  long long sum = 0;
  for (int i = 0, j = 0; i < n; i = j) {
    while (j < n && get<0>(e[j]) == get<0>(e[i])) {
      ++j;
    }
    for (int k = i; k < j; ++k) {
      if (p.find(get<2>(e[k])) != p.find(get<3>(e[k]))) {
        ans.push_back(get<1>(e[k]));
      }
    }
    for (int k = i; k < j; ++k) {
      if (p.unite(get<2>(e[k]), get<3>(e[k]))) {
        sum += get<0>(e[k]);
      }
    }
  }
  cout << sum << " " << ans.size() << "\n";
  sort(ans.begin(), ans.end());
  for (int i = 0; i < (int) ans.size(); ++i) {
    if (i) {
      cout << " ";
    }
    cout << ans[i] + 1;
  }
  cout << "\n";
  return 0;
}