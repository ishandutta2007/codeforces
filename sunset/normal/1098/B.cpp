#include <bits/stdc++.h>

using namespace std;

const string gene = "AGCT";

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> board(n);
  for (int i = 0; i < n; ++i) {
    cin >> board[i];
  }
  vector<string> pattern(n, string(m, '.'));
  int ans = n * m + 1;
  for (int rot = 0; rot < 2; ++rot) {
    vector<int> p(4);
    for (int i = 0; i < 4; ++i) {
      p[i] = i;
    }
    do {
      vector<int> w(n);
      int res = 0;
      for (int i = 0; i < n; ++i) {
        int foo = 0, bar = 0;
        for (int j = 0; j < m; ++j) {
          char cfoo = gene[p[(i % 2) * 2 + (j % 2)]];
          char cbar = gene[p[(i % 2) * 2 + !(j % 2)]];
          if (board[i][j] != cfoo) {
            ++foo;
          }
          if (board[i][j] != cbar) {
            ++bar;
          }
        }
        if (foo < bar) {
          res += foo;
          w[i] = (i % 2) * 2;
        } else {
          res += bar;
          w[i] = (i % 2) * 2 + 1;
        }
      }
      if (res < ans) {
        ans = res;
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < m; ++j) {
            char c = gene[p[w[i] ^ (j % 2)]];
            if (rot) {
              pattern[j][i] = c;
            } else {
              pattern[i][j] = c;
            }
          }
        }
      }
    } while (next_permutation(p.begin(), p.end()));
    vector<string> new_board(m, string(n, '.'));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        new_board[j][i] = board[i][j];
      }
    }
    swap(board, new_board);
    swap(n, m);
  }
  for (int i = 0; i < n; ++i) {
    cout << pattern[i] << "\n";
  }
  return 0;
}