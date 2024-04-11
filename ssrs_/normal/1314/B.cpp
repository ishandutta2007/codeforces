#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> a(k);
  for (int i = 0; i < k; i++){
    cin >> a[i];
    a[i]--;
  }
  vector<int> C(1 << n, 0);
  for (int i = 0; i < k; i++){
    C[a[i]] = 1;
  }
  int ans = 0;
  for (int i = 0; i < (1 << n); i += 2){
    if (C[i] == 1 || C[i + 1] == 1){
      ans++;
    }
  }
  vector<vector<int>> dp(1 << (n - 1), vector<int>(4, -INF));
  for (int i = 0; i < (1 << n); i += 2){
    int s = C[i] + C[i + 1];
    for (int j = 0; j < 4; j++){
      if (__builtin_popcount(j) == s){
        dp[i / 2][j] = 0;
      }
    }
  }
  for (int i = 1 << (n - 1); i >= 2; i /= 2){
    vector<vector<int>> dp2(i / 2, vector<int>(4, -INF));
    for (int j = 0; j < i; j += 2){
      for (int k = 0; k < 4; k++){
        for (int l = 0; l < 4; l++){
          int a = (k >> 0) & 1;
          int b = (l >> 0) & 1;
          int c = (k >> 1) & 1;
          int d = (l >> 1) & 1;
          for (int x = 0; x < 2; x++){
            int e, f;
            if (x == 0){
              e = a;
              f = b;
            } else {
              e = b;
              f = a;
            }
            int sum1 = a | b;
            for (int y = 0; y < 2; y++){
              int g;
              if (y == 0){
                g = c;
              } else {
                g = d;
              }
              int sum2 = c | d;
              for (int z = 0; z < 2; z++){
                int h;
                if (z == 0){
                  h = g;
                } else {
                  h = f;
                }
                int sum3 = f | g;
                int p = e + h * 2;
                dp2[j / 2][p] = max(dp2[j / 2][p], dp[j][k] + dp[j + 1][l] + sum1 + sum2 + sum3);
              }
            }
          }
        }
      }
    }
    swap(dp, dp2);
  }
  int ans2 = 0;
  for (int i = 0; i < 4; i++){
    ans2 = max(ans2, dp[0][i]);
  }
  if (k > 0){
    ans2++;
  }
  cout << ans + ans2 << endl;
}