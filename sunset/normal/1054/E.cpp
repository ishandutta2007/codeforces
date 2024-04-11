#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  vector<vector<queue<char>>> s(n, vector<queue<char>> (m)), t(n, vector<queue<char>> (m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      string str;
      cin >> str;
      for (int k = str.length() - 1; ~k; --k) {
        s[i][j].push(str[k]);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      string str;
      cin >> str;
      for (int k = 0; k < str.length(); ++k) {
        t[i][j].push(str[k]);
      }
    }
  }

  auto solve = [&](vector<vector<queue<char>>> board) {
    vector<vector<int>> answer;

    auto move = [&](int x1, int y1, int x2, int y2) {
      answer.push_back({x1, y1, x2, y2});
      board[x2][y2].push(board[x1][y1].front());
      board[x1][y1].pop();
    };

    while (!board[0][0].empty()) {
      char c = board[0][0].front();
      if (c == '0') {
        move(0, 0, 0, m - 1);
      } else {
        move(0, 0, n - 1, 0);
      }
    }
    while (!board[n - 1][m - 1].empty()) {
      char c = board[n - 1][m - 1].front();
      if (c == '0') {
        move(n - 1, m - 1, 0, m - 1);
      } else {
        move(n - 1, m - 1, n - 1, 0);
      }
    }

    for (int iter = 0; iter < 2; ++iter) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (!i && !j) {
            continue;
          }
          if (i == n - 1 && j == m - 1) {
            continue;
          }
          while (!board[i][j].empty()) {
            char c = board[i][j].front();
            if (c == '0') {
              if (i) {
                move(i, j, 0, j);
              } else {
                move(i, j, i, 0);
              }
            } else {
              if (i != n - 1) {
                move(i, j, n - 1, j);
              } else {
                move(i, j, i, m - 1);
              }
            }
          }
        }
      }
    }

    return answer;
  };

  vector<vector<int>> answer_s = solve(s), answer_t = solve(t);
  reverse(answer_t.begin(), answer_t.end());
  cout << answer_s.size() + answer_t.size() << endl;
  for (auto p : answer_s) {
    printf("%d %d %d %d\n", p[0] + 1, p[1] + 1, p[2] + 1, p[3] + 1);
  }
  for (auto p : answer_t) {
    printf("%d %d %d %d\n", p[2] + 1, p[3] + 1, p[0] + 1, p[1] + 1);
  }
  return 0;
}