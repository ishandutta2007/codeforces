#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<int>> board(4, vector<int> (n));
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &board[i][j]);
    }
  }
  vector<pair<int, pair<int, int>>> answer;  
  for (int i = 0; i < n; ++i) {
    if (board[0][i] && board[0][i] == board[1][i]) {
      answer.push_back(make_pair(board[0][i], make_pair(0, i)));
      board[1][i] = 0;
      --m;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (board[3][i] && board[3][i] == board[2][i]) {
      answer.push_back(make_pair(board[3][i], make_pair(3, i)));
      board[2][i] = 0;
      --m;
    }
  }
  if (m == n << 1) {
    puts("-1");
    return 0;
  }
  while (m) {
    for (int i = 0; i < n << 1; ++i) {
      int x = i / n + 1, y = x == 1 ? i : (n << 1) - i - 1;
      if (board[x][y]) {
        if (board[x][y] == board[x ^ 1][y]) {
          answer.push_back(make_pair(board[x][y], make_pair(x ^ 1, y)));
          board[x][y] = 0;
          --m;
        } else {
          int j = i ? i - 1 : (n << 1) - 1, u = j / n + 1, v = u == 1 ? j : (n << 1) - j - 1;
          if (!board[u][v]) {
            answer.push_back(make_pair(board[x][y], make_pair(u, v)));
            swap(board[u][v], board[x][y]);
          }
        }
      }
    }
  }
  printf("%d\n", answer.size());
  for (auto p : answer) {
    printf("%d %d %d\n", p.first, p.second.first + 1, p.second.second + 1);
  }
  return 0;
}