#include <bits/stdc++.h>
using namespace std;
const int INF = 10000;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<vector<int>> upd(8192);
  for (int i = 0; i < 8192; i++){
    upd[i].push_back(0);
  }
  vector<int> dp(8192, 8192);
  dp[0] = 0;
  for (int i = 0; i < n; i++){
    for (int x : upd[a[i]]){
      int p = dp[x ^ a[i]];
      if (p > a[i]){
        dp[x ^ a[i]] = a[i];
        for (int j = a[i] + 1; j < p; j++){
          upd[j].push_back(x ^ a[i]);
        }
      }
    }
    upd[a[i]].clear();
  }
  vector<int> x;
  for (int i = 0; i < 8192; i++){
    if (dp[i] != 8192){
      x.push_back(i);
    }
  }
  int k = x.size();
  cout << k << endl;
  for (int i = 0; i < k; i++){
    cout << x[i];
    if (i < k - 1){
      cout << ' ';
    }
  }
  cout << endl;
}