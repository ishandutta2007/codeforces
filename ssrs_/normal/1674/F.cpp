#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<char>> c(n, vector<char>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> c[i][j];
    }
  }
  int cnt1 = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (c[i][j] == '*'){
        cnt1++;
      }
    }
  }
  int cnt2 = 0;
  for (int i = 0; i < cnt1; i++){
    if (c[i % n][i / n] == '*'){
      cnt2++;
    }
  }
  for (int i = 0; i < q; i++){
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    if (x + y * n  < cnt1){
      if (c[x][y] == '*'){
        cnt2--;
      } else {
        cnt2++;
      }
    }
    if (c[x][y] == '*'){
      c[x][y] = '.';
      cnt1--;
      if (c[cnt1 % n][cnt1 / n] == '*'){
        cnt2--;
      }
    } else {
      c[x][y] = '*';
      if (c[cnt1 % n][cnt1 / n] == '*'){
        cnt2++;
      }
      cnt1++;
    }
    cout << cnt1 - cnt2 << "\n";
  }
}