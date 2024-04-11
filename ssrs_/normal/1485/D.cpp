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
  vector<int> s;
  for (int i = 1; i * i * i * i < 720720; i++){
    s.push_back(720720 - i * i * i * i);
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if ((i + j) % 2 == 0){
        cout << 720720;
      } else {
        for (int k : s){
          if (k % a[i][j] == 0){
            cout << k;
            break;
          }
        }
      }
      if (j < m - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}