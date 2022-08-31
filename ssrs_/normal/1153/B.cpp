#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m, h;
  cin >> n >> m >> h;
  vector<int> a(m);
  for (int i = 0; i < m; i++){
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++){
    cin >> b[i];
  }
  vector<vector<int>> c(n, vector<int>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> c[i][j];
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (c[i][j] == 1){
        cout << min(b[i], a[j]);
      } else {
        cout << 0;
      }
      if (j < m - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}