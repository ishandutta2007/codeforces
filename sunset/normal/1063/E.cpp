#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
    b[a[i]] = i;
  }
  int left = -1;
  for (int i = n - 1; ~i; --i) {
    if (a[i] != i) {
      left = i;
    }
  }
  vector<string> board(n, string(n, '.'));
  if (!~left) {
    cout << n << endl;
    for (int i = 0; i < n; ++i) {
      cout << board[i] << endl;
    }
    return 0;
  }
  vector<bool> visit(n);
  vector<int> trash;
  int row = n - 1;
  for (int i = 0; i < n; ++i) {
    if (a[i] != i && !visit[i]) {
      vector<int> cycle;
      for (int x = i; !visit[x]; x = b[x]) {
        visit[x] = true;
        cycle.push_back(x);
      }
      if (i != left) {
        board[row][left] = '\\';
        for (int j = 1; j < cycle.size(); ++j) {
          if (cycle[j] > cycle[j - 1]) {
            board[row][cycle[j]] = '\\';
            board[row][cycle[j - 1]] = '\\';
          } else {
            board[row][cycle[j]] = '/';
            board[row][cycle[j - 1]] = '/';
          }
          --row;
        }
        board[row][left] = '/';
        board[row][cycle.back()] = '/';
        --row;
      } else {
        trash = cycle;
      }
    }
  }
  for (int i = 1; i < trash.size(); ++i) {
    if (trash[i] > trash[i - 1]) {
      board[row][trash[i]] = '\\';
      board[row][trash[i - 1]] = '\\';
    } else {
      board[row][trash[i]] = '/';
      board[row][trash[i - 1]] = '/';
    }
    --row;
  }
  cout << n - 1 << endl;
  for (int i = 0; i < n; ++i) {
    cout << board[i] << endl;
  }
  return 0;
}