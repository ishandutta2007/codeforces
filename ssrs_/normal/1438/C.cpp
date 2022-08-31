#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        cin >> a[j][k];
      }
    }
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        if (a[j][k] % 2 != (j + k) % 2){
          a[j][k]++;
        }
        cout << a[j][k];
        if (k < m - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}