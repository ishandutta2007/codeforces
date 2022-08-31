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
    vector<int> row(n, 1), column(m, 1);
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        if (a[j][k] == 1){
          row[j] = 0;
          column[k] = 0;
        }
      }
    }
    int r_cnt = 0;
    for (int j = 0; j < n; j++){
      r_cnt += row[j];
    }
    int c_cnt = 0;
    for (int j = 0; j < m; j++){
      c_cnt += column[j];
    }
    int cnt = min(r_cnt, c_cnt);
    if (cnt % 2 == 1){
      cout << "Ashish" << endl;
    } else {
      cout << "Vivek" << endl;
    }
  }
}