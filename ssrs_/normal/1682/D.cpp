#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> one;
    for (int j = 0; j < n; j++){
      if (s[j] == '1'){
        one.push_back(j);
      }
    }
    int m = one.size();
    if (m % 2 == 1 || m == 0){
      cout << "NO" << endl;
    } else {
      vector<vector<int>> zero(m);
      for (int j = 1; j < m; j++){
        for (int k = one[j - 1] + 1; k < one[j]; k++){
          zero[j].push_back(k);
        }
      }
      for (int k = one[0] - 1; k >= 0; k--){
        zero[m - 1].push_back(k);
      }
      for (int k = n - 1; k > one[m - 1]; k--){
        zero[m - 1].push_back(k);
      }
      for (int j = 1; j < m; j++){
        zero[j].push_back(one[j]);
      }
      vector<int> u, v;
      for (int j = 1; j < m; j++){
        int cnt = zero[j].size();
        u.push_back(one[0]);
        v.push_back(zero[j][0]);
        for (int k = 0; k < cnt - 1; k++){
          u.push_back(zero[j][k]);
          v.push_back(zero[j][k + 1]);
        }
      }
      cout << "YES" << endl;
      for (int j = 0; j < n - 1; j++){
        cout << u[j] + 1 << ' ' << v[j] + 1 << "\n";
      }
    }
  }
}