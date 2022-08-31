#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<string> initial(n);
    for (int i = 0; i < n; ++i) {
      cin >> initial[i];
    }
    int ans = n * n;
    vector<string> res = initial;
    for (int c0 = 0; c0 <= 2; ++c0) {
      for (int c1 = 0; c1 <= 2; ++c1) {
        for (int c2 = 0; c2 <= 2; ++c2) {
          if (c0 != c1 && c0 != c2 && c1 != c2) {
            vector<string> board = initial;
            int changed = 0;
            for (int i = 0; i < n; ++i) {
              for (int j = 0; j < n; ++j) {
                if ((i + j) % 3 == 0) {
                  if (c0 == 0 && board[i][j] == 'X') {
                    board[i][j] = 'O';
                    changed++;
                  }
                  if (c0 == 1 && board[i][j] == 'O') {
                    board[i][j] = 'X';
                    changed++;
                  }
                } else if ((i + j) % 3 == 1) {
                  if (c1 == 0 && board[i][j] == 'X') {
                    board[i][j] = 'O';
                    changed++;
                  }
                  if (c1 == 1 && board[i][j] == 'O') {
                    board[i][j] = 'X';
                    changed++;
                  }
                } else if ((i + j) % 3 == 2) {
                  if (c2 == 0 && board[i][j] == 'X') {
                    board[i][j] = 'O';
                    changed++;
                  }
                  if (c2 == 1 && board[i][j] == 'O') {
                    board[i][j] = 'X';
                    changed++;
                  }
                }
              }
            }
            if (changed < ans) {
              ans = changed;
              res = board;
            }
          }
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      cout << res[i] << "\n";
    }
  }
  return 0;
}