#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<vector<string>> s(3, vector<string>(n));
    for (int j = 0; j < 3; j++){
      for (int k = 0; k < n; k++){
        cin >> s[j][k];
      }
    }
    map<string, int> mp;
    for (int j = 0; j < 3; j++){
      for (int k = 0; k < n; k++){
        mp[s[j][k]] |= 1 << j;
      }
    }
    vector<int> ans(3, 0);
    for (auto P : mp){
      int x = P.second;
      if (x == 1){
        ans[0] += 3;
      }
      if (x == 2){
        ans[1] += 3;
      }
      if (x == 4){
        ans[2] += 3;
      }
      if (x == 3){
        ans[0]++;
        ans[1]++;
      }
      if (x == 5){
        ans[0]++;
        ans[2]++;
      }
      if (x == 6){
        ans[1]++;
        ans[2]++;
      }
    }
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;
  }
}