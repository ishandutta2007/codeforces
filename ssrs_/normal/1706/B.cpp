#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> c(n);
    for (int j = 0; j < n; j++){
      cin >> c[j];
      c[j]--;
    }
    vector<vector<int>> p(n);
    for (int j = 0; j < n; j++){
      p[c[j]].push_back(j);
    }
    vector<int> ans(n, 0);
    for (int j = 0; j < n; j++){
      int cnt = p[j].size();
      if (cnt > 0){
        ans[j] = 1;
        for (int k = 1; k < cnt; k++){
          if ((p[j][k] - p[j][k - 1]) % 2 == 1){
            ans[j]++;
          }
        }
      }
    }
    for (int j = 0; j < n; j++){
      cout << ans[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}