#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> c(n);
  for (int i = 0; i < n; i++){
    cin >> c[i];
  }
  vector<vector<bitset<501>>> dp(n + 1, vector<bitset<501>>(k + 1));
  dp[0][0].set(0);
  for (int i = 0; i < n; i++){
    for (int j = 0; j <= k; j++){
      dp[i + 1][j] = dp[i][j];
    }
    for (int j = c[i]; j <= k; j++){
      dp[i + 1][j] |= dp[i][j - c[i]] | (dp[i][j - c[i]] << c[i]);
    }
  }
  vector<int> x;
  for (int i = 0; i <= k; i++){
    if (dp[n][k][i]){
      x.push_back(i);
    }
  }
  sort(x.begin(), x.end());
  x.erase(unique(x.begin(), x.end()), x.end());
  int q = x.size();
  cout << q << endl;
  for (int i = 0; i < q; i++){
    cout << x[i];
    if (i < q - 1){
      cout << ' ';
    }
  }
  cout << endl;
}