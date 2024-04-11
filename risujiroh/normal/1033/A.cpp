#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n; cin >> n;
  int ax, ay; cin >> ax >> ay, ax--, ay--;
  int bx, by, cx, cy; cin >> bx >> by >> cx >> cy, bx--, by--, cx--, cy--;
  VV<> a; assign(a, n, n);
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
    if (i == ax or j == ay or i + j == ax + ay or i - j == ax - ay) a[i][j] = -1;
  }
  const V<> dx = {1, 1, 0, -1, -1, -1, 0, 1}, dy = {0, 1, 1, 1, 0, -1, -1, -1};
  queue< pair<int, int> > que;
  if (a[bx][by] == -1) return cout << "NO" << '\n', 0;
  a[bx][by] = 1; que.emplace(bx, by);
  while (!que.empty()) {
    int x, y; tie(x, y) = que.front(); que.pop();
    for (int k = 0; k < 8; k++) {
      int nx = x + dx[k], ny = y + dy[k];
      if (nx < 0 or nx >= n or ny < 0 or ny >= n or a[nx][ny]) continue;
      a[nx][ny] = 1; que.emplace(nx, ny);
    }
  }
  cout << (a[cx][cy] == 1 ? "YES" : "NO") << '\n';
}