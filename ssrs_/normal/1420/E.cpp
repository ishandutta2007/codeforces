#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  if (n == 1){
    cout << 0 << endl;
  } else {
    int zero = 0, one = 0;
    vector<int> p;
    for (int i = 0; i < n; i++){
      if (a[i] == 0){
        zero++;
      }
      if (a[i] == 1){
        one++;
        p.push_back(i);
      }
    }
    int L = n * n / 4;
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(one + 1, vector<int>(L + 1, INF)));
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++){
      vector<vector<vector<int>>> dp2(n + 1, vector<vector<int>>(one + 1, vector<int>(L + 1, INF)));
      for (int j = 0; j <= i; j++){
        for (int k = max(0, i - zero); k <= min(one, i); k++){
          for (int l = 0; l < L; l++){
            if (dp[j][k][l] != INF){
              if (k > i - zero){
                dp2[j + 1][k][l] = min(dp2[j + 1][k][l], dp[j][k][l]);
              }
              if (k < one){
                int l2 = min(L, l + abs(p[k] - i));
                dp2[0][k + 1][l2] = min(dp2[0][k + 1][l2], dp[j][k][l] + j * (j - 1) / 2);
              }
            }
          }
        }
      }
      swap(dp, dp2);
    }
    vector<int> ans(L + 1, INF);
    for (int i = 0; i <= n; i++){
      for (int j = 0; j <= one; j++){
        for (int k = 0; k <= L; k++){
          ans[k] = min(ans[k], dp[i][j][k] + i * (i - 1) / 2);
        }
      }
    }
    for (int i = 0; i < L; i++){
      ans[i + 1] = min(ans[i + 1], ans[i]);
    }
    for (int i = 0; i <= n * (n - 1) / 2; i++){
      cout << zero * (zero - 1) / 2 - ans[min(i, L)];
      if (i < n * (n - 1) / 2){
        cout << ' ';
      }
    }
    cout << endl;
  }
}