#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector<vector<string>> board(3, vector<string> (n * 3, string(n * 3, '#')));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n * 3; ++j) {
      board[0][i * 3][j] = board[2][j][i * 3] = '.';
    }
    board[1][i * 3][i * 3 + 1] = board[1][i * 3 + 1][i * 3 + 1] = board[2][i * 3 + 1][i * 3 + 1] = '.';
    for (int j = 0; j < n; ++j) {
      int can;
      cin >> can;
      if (can) {
        for (int k = 0; k < 3; ++k) {
          board[k][j * 3 + 1][i * 3 + 1] = '.';
        }
      }
    }
    board[0][i * 3][n * 3 - 1] = i + '1';
  }
  cout << n * 3 << " " << n * 3 << " " << 3 << endl;
  for (int i = 2; ~i; --i) {
    for (int j = 0; j < n * 3; ++j) {
      cout << board[i][j] << endl;
    }
    if (i) {
      cout << endl;
    }
  }
  return 0;
}