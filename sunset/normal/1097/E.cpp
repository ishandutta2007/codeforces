#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> f(MAX + 1);
  for (int i = 1, j = 1, k = 3; i <= MAX; ++i) {
    if (i == k) {
      ++j;
      k += j + 1;
    }
    f[i] = j;
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      --a[i];
    }
    vector<bool> removed(n);
    vector<vector<int>> ans;
    vector<int> pre(n);
    auto solve = [&](vector<int> a) {
      vector<vector<int>> res;
      vector<int> ed;
      for (auto x : a) {
        int p = lower_bound(ed.begin(), ed.end(), x) - ed.begin();
        if (p == ed.size()) {
          res.push_back(vector<int>());
          ed.push_back(0);
        }
        pre[x] = p ? ed[p - 1] : -1;
        res[p].push_back(x);
        ed[p] = x;
      }
      if (res.size() <= f[a.size()]) {
        return res;
      }
      res.clear();
      res.push_back(vector<int>());
      for (int x = ed.back(); ~x; x = pre[x]) {
        res.back().push_back(x);
      }
      reverse(res.back().begin(), res.back().end());
      return res;
    };
    while (!a.empty()) {
      vector<vector<int>> res = solve(a);
      for (auto v : res) {
        for (auto x : v) {
          removed[x] = true;
        }
        ans.push_back(v);
      }
      vector<int> new_a;
      for (auto x : a) {
        if (!removed[x]) {
          new_a.push_back(x);
        }
      }
      swap(a, new_a);
    }
    cout << ans.size() << "\n";
    for (auto v : ans) {
      cout << v.size();
      for (auto x : v) {
        cout << " " << x + 1;
      }
      cout << "\n";
    }
  }
  return 0;
}