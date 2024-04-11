#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> a[i][j];
    }
  }
  vector<int> diff;
  for (int i = 0; i < n; i++){
    bool flg = true;
    for (int j = 0; j < m; j++){
      if (a[i][j] != a[i][0]){
        flg = false;
      }
    }
    if (!flg){
      diff.push_back(i);
    }
  }
  if (diff.empty()){
    int ans = 0;
    for (int i = 0; i < n; i++){
      ans ^= a[i][0];
    }
    if (ans == 0){
      cout << "NIE" << endl;
    } else {
      cout << "TAK" << endl;
      for (int i = 0; i < n; i++){
        cout << 1;
        if (i < n - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  } else {
    int r = diff[0];
    int ans = 0;
    for (int i = 0; i < n; i++){
      if (i != r){
        ans ^= a[i][0];
      }
    }
    for (int i = 0; i < m; i++){
      if ((ans ^ a[r][i]) != 0){
        cout << "TAK" << endl;
        for (int j = 0; j < n; j++){
          if (j != r){
            cout << 1;
          } else {
            cout << i + 1;
          }
          if (j < n - 1){
            cout << ' ';
          }
        }
        cout << endl;
        break;
      }
    }
  }
}