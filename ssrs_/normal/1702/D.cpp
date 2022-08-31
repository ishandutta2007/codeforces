#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string w;
    cin >> w;
    int p;
    cin >> p;
    int n = w.size();
    int sum = 0;
    for (int j = 0; j < n; j++){
      sum += w[j] - 'a' + 1;
    }
    vector<vector<int>> pos(26);
    for (int j = 0; j < n; j++){
      pos[w[j] - 'a'].push_back(j);
    }
    vector<bool> used(n, true);
    for (int j = 25; j >= 0; j--){
      int cnt = pos[j].size();
      for (int k = 0; k < cnt; k++){
        if (sum > p){
          used[pos[j][k]] = false;
          sum -= j + 1;
        }
      }
    }
    string ans;
    for (int j = 0; j < n; j++){
      if (used[j]){
        ans += w[j];
      }
    }
    cout << ans << endl;
  }
}