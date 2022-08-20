#include <bits/stdc++.h>

using namespace std;

class dsu {
 public:
  vector<long long> mx, mn;
  vector<int> p;
  long long ans;
  int n;

  dsu(int n, vector<long long> a): n(n) {
    p.resize(n);
    for (int i = 0; i < n; ++i) {
      p[i] = i;
    }
    mx = mn = a;
    ans = 0;
  }

  inline int find(int x) {
    while (x != p[x]) {
      x = p[x] = p[p[x]];
    }
    return x;
  }

  inline void unite(int x, int y) {
    x = find(x);
    y = find(y);
    ans -= mx[y] - mn[y];
    ans -= mx[x] - mn[x];
    mx[y] = max(mx[y], mx[x]);
    mn[y] = min(mn[y], mn[x]);
    ans += mx[y] - mn[y];
    p[x] = y;
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
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<pair<long long, int>> diffs(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    diffs[i] = make_pair(a[i + 1] - a[i], i);
  }
  sort(diffs.begin(), diffs.end());
  int m;
  cin >> m;
  vector<pair<long long, int>> queries(m);
  for (int i = 0; i < m; ++i) {
    long long l, r;
    cin >> l >> r;
    queries[i] = make_pair(r - l + 1, i);
  }
  sort(queries.begin(), queries.end());
  int ptr = 0;
  vector<long long> ans(m);
  dsu d(n, a);
  for (auto p : queries) {
    while (ptr < n - 1 && diffs[ptr].first < p.first) {
      d.unite(diffs[ptr].second, diffs[ptr].second + 1);
      ++ptr;
    }
    ans[p.second] = d.ans + p.first * (n - ptr);
  }
  for (int i = 0; i < m; ++i) {
    if (i) {
      cout << " ";
    }
    cout << ans[i];
  }
  cout << "\n";
  return 0;
}