#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;  
  vector<vector<int>> side(n, vector<int>(m, 0));
  vector<vector<char>> a(n, vector<char>(m, '#'));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (char ch = 'A'; ch <= 'S' && side[i][j] == 0; ch++) {
        if (a[i][j] != '#') continue;
        if (i + 1 < n && a[i + 1][j] == ch) continue;
        if (j + 1 < m && a[i][j + 1] == ch) continue;
        if (i > 0 && a[i - 1][j] == ch) continue;
        if (j > 0 && a[i][j - 1] == ch && i + side[i][j - 1] >= n) continue;

        int sd = (a[i][j - 1] == ch ? side[i][j - 1] + 1 : 1);
        side[i][j] = sd;
        a[i][j] = ch;

        int xx = j;
        int yy = i;
        for (int t = 0; t < sd - 1; t++) {
          yy++;
          a[yy][xx] = ch;
          side[yy][xx] = sd;
        }
        for (int t = 0; t < sd - 1; t++) {
          xx--;
          a[yy][xx] = ch;
          side[yy][xx] = sd;
        }
        break;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << a[i][j];
    }
    cout << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
#ifdef SERT
  t = 3;
#endif
  while (t--) solve();
}