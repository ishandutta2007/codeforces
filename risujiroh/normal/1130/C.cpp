#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  int r0, c0; cin >> r0 >> c0, --r0, --c0;
  int r1, c1; cin >> r1 >> c1, --r1, --c1;
  V<string> s(n); for (auto&& e : s) cin >> e;
  constexpr array<int, 4> dr = {1, 0, -1, 0}, dc = {0, 1, 0, -1};
  auto in = [&](int r, int c) -> bool { return 0 <= r and r < n and 0 <= c and c < n; };
  auto f = [&](int r0, int c0) -> VV<bool> {
    VV<bool> res(n, V<bool>(n));
    queue< pair<int, int> > que;
    res[r0][c0] = true;
    que.emplace(r0, c0);
    while (!que.empty()) {
      int r, c;
      tie(r, c) = que.front(); que.pop();
      for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (!in(nr, nc) or s[nr][nc] == '1' or res[nr][nc]) continue;
        res[nr][nc] = true;
        que.emplace(nr, nc);
      }
    }
    return res;
  };
  auto b0 = f(r0, c0);
  auto b1 = f(r1, c1);
  int res = 1e9;
  for (int rs = 0; rs < n; ++rs) for (int cs = 0; cs < n; ++cs) if (b0[rs][cs]) {
    for (int rt = 0; rt < n; ++rt) for (int ct = 0; ct < n; ++ct) if (b1[rt][ct]) {
      res = min(res, (rt - rs) * (rt - rs) + (ct - cs) * (ct - cs));
    }
  }
  cout << res << '\n';
}