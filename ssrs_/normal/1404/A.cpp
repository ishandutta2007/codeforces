#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<bool>> e(k, vector<bool>(2, false));
    for (int j = 0; j < n; j++){
      if (s[j] == '0'){
        e[j % k][0] = true;
      }
      if (s[j] == '1'){
        e[j % k][1] = true;
      }
    }
    bool ok = true;
    for (int j = 0; j < k; j++){
      if (e[j][0] && e[j][1]){
        ok = false;
      }
    }
    if (!ok){
      cout << "NO" << endl;
    } else {
      int cnt0 = 0;
      int cnt1 = 0;
      for (int j = 0; j < k; j++){
        if (e[j][0]){
          cnt0++;
        }
        if (e[j][1]){
          cnt1++;
        }
      }
      if (cnt0 > k / 2 || cnt1 > k / 2){
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
      }
    }
  }
}