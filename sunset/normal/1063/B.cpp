#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;
const vector<int> dx = {0, 0, -1, 1};
const vector<int> dy = {-1, 1, 0, 0};

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m, x, y, left, right;
  cin >> n >> m >> x >> y >> left >> right;
  --x;
  --y;
  vector<string> board(n);
  for (int i = 0; i < n; ++i) {
    cin >> board[i];
  }
  vector<vector<int>> dist(n, vector<int> (m, inf));
  deque<pair<int, int>> q;
  dist[x][y] = 0;
  q.emplace_back(x, y);
  while (!q.empty()) {
    int x = q.front().first, y = q.front().second;
    q.pop_front();
    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == '.') {
        if (i) {
          if (dist[nx][ny] > dist[x][y]) {
            dist[nx][ny] = dist[x][y];
            q.emplace_front(nx, ny);
          }
        } else {
          if (dist[nx][ny] > dist[x][y] + 1) {
            dist[nx][ny] = dist[x][y] + 1;
            q.emplace_back(nx, ny);
          }
        }
      }
    }
  }
  int answer = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (dist[i][j] != inf) {
        int l = dist[i][j], r = j - y + l;
        if (left >= l && right >= r) {
          ++answer;
        }
      }
    }
  }
  cout << answer << endl;
  return 0;
}