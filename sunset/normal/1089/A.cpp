#include <bits/stdc++.h>

using namespace std;

const int N = 3;
const int MAX = 200;
const int FIRST = 25;
const int LAST = 15;
const int DIFF = 2;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  vector<vector<pair<int, int>>> dp((N + 1) * (N + 1), vector<pair<int, int>> ((MAX + 1) * (MAX + 1), make_pair(-1, -1)));
  vector<pair<int, int>> a_win_first, a_win_last;
  vector<pair<int, int>> b_win_first, b_win_last;
  for (int i = 0; i <= MAX; ++i) {
    for (int j = 0; j <= MAX; ++j) {
      if (abs(i - j) == DIFF) {
        if (max(i, j) >= FIRST) {
          if (i > j) {
            a_win_first.emplace_back(i, j);
          } else {
            b_win_first.emplace_back(i, j);
          }
        }
        if (max(i, j) >= LAST) {
          if (i > j) {
            a_win_last.emplace_back(i, j);
          } else {
            b_win_last.emplace_back(i, j);
          }
        }
      } else if (abs(i - j) > DIFF) {
        if (max(i, j) == FIRST) {
          if (i > j) {
            a_win_first.emplace_back(i, j);
          } else {
            b_win_first.emplace_back(i, j);
          }
        }
        if (max(i, j) == LAST) {
          if (i > j) {
            a_win_last.emplace_back(i, j);
          } else {
            b_win_last.emplace_back(i, j);
          }
        }
      }
    }
  }
  dp[0][0] = make_pair(0, 0);
  for (int win_a = 0; win_a < N; ++win_a) {
    for (int win_b = 0; win_b < N; ++win_b) {
      for (int score_a = 0; score_a <= MAX; ++score_a) {
        for (int score_b = 0; score_b <= MAX; ++score_b) {
          if (~dp[win_a * (N + 1) + win_b][score_a * (MAX + 1) + score_b].first) {
            vector<pair<int, int>> a_win = win_a == N - 1 && win_b == N - 1 ? a_win_last : a_win_first;
            vector<pair<int, int>> b_win = win_a == N - 1 && win_b == N - 1 ? b_win_last : b_win_first;
            for (auto p : a_win) {
              int new_score_a = score_a + p.first;
              int new_score_b = score_b + p.second;
              if (new_score_a <= MAX && new_score_b <= MAX) {
                int index_win = (win_a + 1) * (N + 1) + win_b;
                int index_score = new_score_a * (MAX + 1) + new_score_b;
                dp[index_win][index_score] = p;
              }
            }
            for (auto p : b_win) {
              int new_score_a = score_a + p.first;
              int new_score_b = score_b + p.second;
              if (new_score_a <= MAX && new_score_b <= MAX) {
                int index_win = win_a * (N + 1) + (win_b + 1);
                int index_score = new_score_a * (MAX + 1) + new_score_b;
                dp[index_win][index_score] = p;
              }
            }
          }
        }
      }
    }
  }
  auto print = [&](int win_a, int win_b, int score_a, int score_b) {
    vector<pair<int, int>> match;
    printf("%d:%d\n", win_a, win_b);
    while (win_a || win_b) {
      pair<int, int> p = dp[win_a * (N + 1) + win_b][score_a * (MAX + 1) + score_b];
      match.push_back(p);
      if (p.first > p.second) {
        --win_a;
      } else {
        --win_b;
      }
      score_a -= p.first;
      score_b -= p.second;
    }
    for (int i = match.size() - 1; ~i; --i) {
      printf("%d:%d%c", match[i].first, match[i].second, i ? ' ' : '\n');
    }
  };
  auto solve = [&](int score_a, int score_b) {
    for (int win_a = N; win_a <= N; ++win_a) {
      for (int win_b = 0; win_b < N; ++win_b) {
        if (~dp[win_a * (N + 1) + win_b][score_a * (MAX + 1) + score_b].first) {
          print(win_a, win_b, score_a, score_b);
          return;
        }
      }
    }
    for (int win_a = N - 1; ~win_a; --win_a) {
      for (int win_b = N; win_b <= N; ++win_b) {
        if (~dp[win_a * (N + 1) + win_b][score_a * (MAX + 1) + score_b].first) {
          print(win_a, win_b, score_a, score_b);
          return;
        }
      }
    }
    puts("Impossible");
  };
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int score_a, score_b;
    scanf("%d %d", &score_a, &score_b);
    solve(score_a, score_b);
  }
  return 0;
}