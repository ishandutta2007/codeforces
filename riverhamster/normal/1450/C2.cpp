#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 305;
char s[N][N];
int cnt[2][3];

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> s[i];
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        if (s[i][j] == 'X') ++cnt[0][(i + j) % 3];
        else if (s[i][j] == 'O') ++cnt[1][(i + j) % 3];
      }
    int x = 0, o = 1;
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
        if (i != j && cnt[0][i] + cnt[1][j] < cnt[0][x] + cnt[1][o])
          x = i, o = j;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (s[i][j] == 'X') {
          if ((i + j) % 3 == x) cerr << i << ' ' << j << endl;
          cout.put((i + j) % 3 == x ? 'O' : 'X');
        }
        else if (s[i][j] == 'O') {
          if ((i + j) % 3 == o) cerr << i << ' ' << j << endl;
          cout.put((i + j) % 3 == o ? 'X' : 'O');
        }
        else
          cout.put('.');
      }
      cout.put('\n');
    }
  }
  return 0;
}