#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> m(n);
  for (int i = 0; i < n; i++){
    cin >> m[i];
  }
  vector<int> c(k);
  for (int i = 0; i < k; i++){
    cin >> c[i];
  }
  sort(m.begin(), m.end());
  reverse(m.begin(), m.end());
  vector<vector<int>> ans(1);
  ans[0].push_back(m[0]);
  for (int i = 1; i < n; i++){
    //put m[i]
    if (c[m[i] - 1] > c[m[i - 1] - 1]){
      ans[0].push_back(m[i]);
    } else {
      if (ans.back().size() + 1 > c[m[i] - 1]){
        ans.push_back(vector<int>());
        ans.back().push_back(m[i]);
      } else { 
        int tv = ans.size();
        int fv = -1;
        while (tv - fv > 1){
          int mv = (tv + fv) / 2;
          if (ans[mv].size() + 1 <= c[m[i] - 1]){
            tv = mv;
          } else {
            fv = mv;
          }
        }
        ans[tv].push_back(m[i]);
      }
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++){
    int t = ans[i].size();
    cout << t;
    for (int j = 0; j < t; j++){
      cout << ' ' << ans[i][j];
    }
    cout << endl;
  }
}