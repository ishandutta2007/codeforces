#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    b[--a[i]] = i;
  }
  vector<pair<int, int>> queries(m);
  for (int i = 0; i < m; ++i) {
    cin >> queries[i].first >> queries[i].second;
    queries[i].first--;
    queries[i].second--;
  }
  vector<pair<int, int>> sets(n);
  function<vector<int>(int, int, vector<pair<int, int>>)> solve = [&](int l, int r, vector<pair<int, int>> queries) {
    int m = queries.size();
    vector<pair<int, int>> cpy;
    for (auto p : queries) {
      if (p.first <= p.second) {
        cpy.push_back(p);
      }
    }
    sort(cpy.begin(), cpy.end());
    cpy.erase(unique(cpy.begin(), cpy.end()), cpy.end());
    vector<int> id(m, -1);
    for (int i = 0; i < m; ++i) {
      if (queries[i].first <= queries[i].second) {
        id[i] = lower_bound(cpy.begin(), cpy.end(), queries[i]) - cpy.begin();
      }
    }
    int q = cpy.size();
    vector<int> res(q, -1);
    if (l == r) {
      for (int i = 0; i < q; ++i) {
        res[i] = b[l];
      }
    } else {
      int y = (l + r) >> 1;
      vector<int> preL(n), preR(n);
      vector<int> nxtL(n), nxtR(n);
      for (int i = 0; i < n; ++i) {
        if (l <= a[i] && a[i] <= y) {
          preL[i] = i;
          preR[i] = i ? preR[i - 1] : -1;
        } else if (y < a[i] && a[i] <= r) {
          preL[i] = i ? preL[i - 1] : -1;
          preR[i] = i;
        } else {
          preL[i] = i ? preL[i - 1] : -1;
          preR[i] = i ? preR[i - 1] : -1;
        }
      }
      for (int i = n - 1; ~i; --i) {
        if (l <= a[i] && a[i] <= y) {
          nxtL[i] = i;
          nxtR[i] = i + 1 < n ? nxtR[i + 1] : n;
        } else if (y < a[i] && a[i] <= r) {
          nxtL[i] = i + 1 < n ? nxtL[i + 1] : n;
          nxtR[i] = i;
        } else {
          nxtL[i] = i + 1 < n ? nxtL[i + 1] : n;
          nxtR[i] = i + 1 < n ? nxtR[i + 1] : n;
        }
      }
      vector<pair<int, int>> queriesL(q), queriesR(q);
      for (int i = 0; i < q; ++i) {
        queriesL[i] = make_pair(nxtL[cpy[i].first], preL[cpy[i].second]);
        queriesR[i] = make_pair(nxtR[cpy[i].first], preR[cpy[i].second]);
      }
      vector<int> resL = solve(l, y, queriesL);
      vector<int> resR = solve(y + 1, r, queriesR);
      for (int i = 0; i < q; ++i) {
        if (resL[i] == -1) {
          res[i] = resR[i];
        } else if (resR[i] == -1) {
          res[i] = resL[i];
        } else {
          res[i] = sets.size();
          sets.emplace_back(resL[i], resR[i]);
        }
      }
    }
    vector<int> ans(id.size(), -1);
    for (int i = 0; i < (int) id.size(); ++i) {
      if (id[i] != -1) {
        ans[i] = res[id[i]];
      }
    }
    return ans;
  };
  vector<int> ans = solve(0, n - 1, queries);
  cout << sets.size() << "\n";
  for (int i = n; i < (int) sets.size(); ++i) {
    cout << sets[i].first + 1 << " " << sets[i].second + 1 << "\n";
  }
  for (int i = 0; i < m; ++i) {
    if (i) {
      cout << " ";
    }
    cout << ans[i] + 1;
  }
  cout << "\n";
  return 0;
}