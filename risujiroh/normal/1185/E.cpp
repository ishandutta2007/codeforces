#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

void solve() {
  int n, m; cin >> n >> m;
  V<string> s(n);
  V<> c(26);
  for (auto&& e : s) {
    cin >> e;
    for (char f : e) if (f != '.') ++c[f - 'a'];
  }
  V< set<int> > row(26), col(26);
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (s[i][j] != '.') {
    row[s[i][j] - 'a'].insert(i);
    col[s[i][j] - 'a'].insert(j);
  }
  for (int k = 0; k < 26; ++k) if (row[k].size() >= 2 and col[k].size() >= 2) {
    cout << "NO" << '\n';
    return;
  }
  VV<> res;
  bool be = false;
  for (int k = 25; k >= 0; --k) {
    if (!be and !c[k]) continue;
    be = true;
    if (!c[k]) {
      res.emplace_back(V<>{res.back()[0], res.back()[1], res.back()[0], res.back()[1]});
      continue;
    }
    if (row[k].size() == 1) {
      int i = *begin(row[k]);
      V<> a(m + 1), b(m + 1);
      for (int j = 0; j < m; ++j) {
        a[j + 1] = a[j] + (s[i][j] == 'a' + k or s[i][j] == '*');
        b[j + 1] = b[j] + (s[i][j] == 'a' + k);
      }
      bool ok = false;
      [&] { for (int tj = 0; tj <= m; ++tj) for (int sj = 0; sj < tj; ++sj) {
        if (a[tj] - a[sj] < tj - sj) continue;
        if (b[tj] - b[sj] < c[k]) continue;
        ok = true;
        res.emplace_back(V<>{i, sj, i, tj - 1});
        for (int j = sj; j < tj; ++j) {
          s[i][j] = '*';
        }
        return;
      } }();
      if (!ok) {
        cout << "NO" << '\n';
        return;
      }
    } else {
      assert(col[k].size() == 1);
      int j = *begin(col[k]);
      V<> a(n + 1), b(n + 1);
      for (int i = 0; i < n; ++i) {
        a[i + 1] = a[i] + (s[i][j] == 'a' + k or s[i][j] == '*');
        b[i + 1] = b[i] + (s[i][j] == 'a' + k);
      }
      bool ok = false;
      [&] { for (int ti = 0; ti <= n; ++ti) for (int si = 0; si < ti; ++si) {
        if (a[ti] - a[si] < ti - si) continue;
        if (b[ti] - b[si] < c[k]) continue;
        ok = true;
        res.emplace_back(V<>{si, j, ti - 1, j});
        for (int i = si; i < ti; ++i) {
          s[i][j] = '*';
        }
        return;
      } }();
      if (!ok) {
        cout << "NO" << '\n';
        return;
      }
    }
  }
  cout << "YES" << '\n';
  cout << res.size() << '\n';
  reverse(begin(res), end(res));
  for (const auto& v : res) {
    cout << v[0] + 1 << ' ' << v[1] + 1 << ' ' << v[2] + 1 << ' ' << v[3] + 1 << '\n';
  }
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int T; cin >> T;
  while (T--) {
    solve();
  }
}