#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  V<> di{1, 0, -1, 0}, dj{0, 1, 0, -1};
  auto in = [&](int i, int j) -> bool { return 0 <= i and i < n and 0 <= j and j < m; };
  VV<bool> b(n, V<bool>(m));
  int si = 0, sj = 0, ti = n - 1, tj = m - 1;
  int sk = 0, tk = 2;
  for (int t = 0; t < n * m; ++t) if (~t & 1) {
    cout << si + 1 << ' ' << sj + 1 << '\n';
    b[si][sj] = true;
    for (int _ = 0; _ < 4; ++_) {
      int ni = si + di[sk], nj = sj + dj[sk];
      if (!in(ni, nj) or b[ni][nj]) {
        sk = sk + 1 & 3;
        continue;
      }
      si = ni, sj = nj;
      break;
    }
  } else {
    cout << ti + 1 << ' ' << tj + 1 << '\n';
    b[ti][tj] = true;
    for (int _ = 0; _ < 4; ++_) {
      int ni = ti + di[tk], nj = tj + dj[tk];
      if (!in(ni, nj) or b[ni][nj]) {
        tk = tk + 1 & 3;
        continue;
      }
      ti = ni, tj = nj;
      break;
    }
  }
}