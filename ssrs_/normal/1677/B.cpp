#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> sum1(n * m + 1);
    sum1[0] = 0;
    for (int j = 0; j < n * m; j++){
      sum1[j + 1] = sum1[j] + s[j] - '0';
    }
    vector<int> row(n * m + 1, 0);
    for (int j = 1; j <= n * m; j++){
      if (j < m){
        if (sum1[j] >= 1){
          row[j]++;
        }
      } else {
        row[j] = row[j - m];
        if (sum1[j] - sum1[j - m] >= 1){
          row[j]++;
        }
      }
    }
    vector<bool> ok(m, false);
    int cnt = 0;
    vector<int> col(n * m + 1, 0);
    for (int j = 0; j < n * m; j++){
      if (s[j] == '1'){
        if (!ok[j % m]){
          cnt++;
        }
        ok[j % m] = true;
      }
      col[j + 1] = cnt;
    }
    for (int j = 1; j <= n * m; j++){
      cout << row[j] + col[j];
      if (j < n * m){
        cout << ' ';
      }
    }
    cout << endl;
  }
}