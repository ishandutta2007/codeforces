#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  V<string> s(n); for (int i = 0; i < n; i++) cin >> s[i];
  VV<> dpa; assign(dpa, n, n);
  dpa[0][0] = s[0][0] == 'a';
  for (int x = 1; x < n; x++) dpa[x][0] = dpa[x - 1][0] + (s[x][0] == 'a');
  for (int y = 1; y < n; y++) dpa[0][y] = dpa[0][y - 1] + (s[0][y] == 'a');
  for (int x = 1; x < n; x++) for (int y = 1; y < n; y++) dpa[x][y] = max(dpa[x][y - 1], dpa[x - 1][y]) + (s[x][y] == 'a');
  int mxa = 0;
  for (int x = 0; x < n; x++) for (int y = 0; y < n; y++) if (dpa[x][y] + k >= x + y + 1) mxa = max(mxa, x + y + 1);
  if (mxa == 2 * n - 1) return cout << string(2 * n - 1, 'a') << '\n', 0;
  string res(2 * n - 1, '{');
  for (int i = 0; i < mxa; i++) res[i] = 'a';
  queue< pair<int, int> > que;
  VV<bool> vis; assign(vis, n, n);
  if (!mxa) {
    res[0] = s[0][0];
    que.emplace(0, 0);
    vis[0][0] = true;
  } else {
    for (int x = 0; x < n; x++) {
      int y = mxa - 1 - x;
      if (0 <= y and y < n and dpa[x][y] + k >= x + y + 1) {
        s[x][y] = 'a';
        que.emplace(x, y);
        vis[x][y] = true;
      }
    }
  }
  while (!que.empty()) {
    int x, y; tie(x, y) = que.front(); que.pop();
    if (s[x][y] > res[x + y]) continue;
    if (x + 1 < n and !vis[x + 1][y] and s[x + 1][y] <= res[x + 1 + y]) {
      res[x + 1 + y] = min(res[x + 1 + y], s[x + 1][y]);
      que.emplace(x + 1, y);
      vis[x + 1][y] = true;
    }
    if (y + 1 < n and !vis[x][y + 1] and s[x][y + 1] <= res[x + 1 + y]) {
      res[x + y + 1] = min(res[x + y + 1], s[x][y + 1]);
      que.emplace(x, y + 1);
      vis[x][y + 1] = true;
    }
  }
  cout << res << '\n';
}