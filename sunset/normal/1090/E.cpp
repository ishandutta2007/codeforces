#include <bits/stdc++.h>

using namespace std;

const int N = 8;
const vector<int> dx = {1, 2, 2, 1, -1, -2, -2, -1};
const vector<int> dy = {-2, -1, 1, 2, 2, 1, -1, -2};

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector<bool> knight(N * N);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    knight[(s[1] - '1') * 8 + s[0] - 'a'] = true;
  }
  vector<pair<int, int>> answer;
  for (int i = 0; i < n; ++i) {
    vector<int> dist(N * N, N * N);
    vector<int> prev(N * N, -1);
    queue<int> q;
    dist[i] = 0;
    q.push(i);
    while (!q.empty()) {
      int x = q.front() / N, y = q.front() % N;
      q.pop();
      for (int i = 0; i < 8; ++i) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx >= 0 && xx < N && yy >= 0 && yy < N && dist[xx * N + yy] > dist[x * N + y] + 1) {
          dist[xx * N + yy] = dist[x * N + y] + 1;
          prev[xx * N + yy] = x * N + y;
          q.push(xx * N + yy);
        }
      }
    }
    int j = i;
    while (!knight[j]) {
      ++j;
    }
    knight[j] = false;
    while (j != i) {
      vector<int> path;
      do {
        path.push_back(j);
        j = prev[j];
      } while (knight[j]);
      path.push_back(j);
      for (int k = path.size() - 1; k; --k) {
        answer.emplace_back(path[k - 1], path[k]);
      }
    }
    knight[j] = true;
  }
  printf("%d\n", answer.size());
  for (auto p : answer) {
    printf("%c%d-%c%d\n", p.first % N + 'a', p.first / N + 1, p.second % N + 'a', p.second / N + 1);
  }
  return 0;
}