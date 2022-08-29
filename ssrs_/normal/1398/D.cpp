#include <bits/stdc++.h>
using namespace std;
int main(){
  int R, G, B;
  cin >> R >> G >> B;
  vector<int> r(R);
  for (int i = 0; i < R; i++){
    cin >> r[i];
  }
  vector<int> g(G);
  for (int i = 0; i < G; i++){
    cin >> g[i];
  }
  vector<int> b(B);
  for (int i = 0; i < B; i++){
    cin >> b[i];
  }
  sort(r.rbegin(), r.rend());
  sort(g.rbegin(), g.rend());
  sort(b.rbegin(), b.rend());
  vector<vector<vector<long long>>> dp(R + 1, vector<vector<long long>>(G + 1, vector<long long>(B + 1, 0)));
  for (int i = 0; i <= R; i++){
    for (int j = 0; j <= G; j++){
      for (int k = 0; k <= B; k++){
        if (i > 0 && j > 0){
          dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + r[i - 1] * g[j - 1]);
        }
        if (j > 0 && k > 0){
          dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + g[j - 1] * b[k - 1]);
        }
        if (k > 0 && i > 0){
          dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + b[k - 1] * r[i - 1]);
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i <= R; i++){
    for (int j = 0; j <= G; j++){
      for (int k = 0; k <= B; k++){
        ans = max(ans, dp[i][j][k]);
      }
    }
  }
  cout << ans << endl;
}