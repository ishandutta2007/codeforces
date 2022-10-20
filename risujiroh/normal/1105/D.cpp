#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m, p; cin >> n >> m >> p;
  V<lint> a(p); for (auto&& e : a) cin >> e;
  V<string> s(n); for (auto&& e : s) cin >> e;
  constexpr array<int, 4> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
  auto in = [&](int x, int y) { return 0 <= x and x < n and 0 <= y and y < m; };

  V< VV<> > d(p, VV<>(n, V<>(m, -1)));
  V< queue< pair<int, int> > > que(p);
  for (int x = 0; x < n; ++x) for (int y = 0; y < m; ++y) if (isdigit(s[x][y])) {
    int i = s[x][y] - '1';
    d[i][x][y] = 0;
    que[i].emplace(x, y);
  }
  int t = 1;
  while (any_of(begin(que), end(que), [](const auto& e) { return !e.empty(); })) {
    for (int i = 0; i < p; ++i) {
      while (!que[i].empty()) {
        int x, y;
        tie(x, y) = que[i].front();
        if (d[i][x][y] == t * a[i]) break;
        que[i].pop();
        for (int k = 0; k < 4; ++k) {
          int nx = x + dx[k];
          int ny = y + dy[k];
          if (!in(nx, ny) or s[nx][ny] != '.') continue;
          d[i][nx][ny] = d[i][x][y] + 1;
          s[nx][ny] = '1' + i;
          que[i].emplace(nx, ny);
        }
      }
    }
    ++t;
  }
  V<> res(p);
  for (int x = 0; x < n; ++x) for (int y = 0; y < m; ++y) if (isdigit(s[x][y])) {
    ++res[s[x][y] - '1'];
  }
  for (int i = 0; i < p; ++i) {
    cout << res[i] << " \n"[i == p - 1];
  }
  for (const auto& e : s) cerr << e << '\n';
}