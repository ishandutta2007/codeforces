#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  for (int i = 0; i < n; i++){
    cin >> p[i];
    p[i]--;
  }
  vector<int> q(n);
  for (int i = 0; i < n; i++){
    q[p[i]] = i;
  }
  vector<vector<int>> S(n + 1, vector<int>(n + 1, 0));
  for (int i = 0; i < n; i++){
    S[i + 1] = S[i];
    for (int j = 0; j <= p[i]; j++){
      S[i + 1][j]++;
    }
  }
  vector<int> id(1 << (k * 2), -1);
  vector<int> mask;
  for (int i = 0; i < (1 << (k * 2)); i++){
    if (__builtin_popcount(i) == k){
      id[i] = mask.size();
      mask.push_back(i);
    }
  }
  int m = mask.size();
  vector<int> dp(m, INF);
  dp[0] = 0;
  for (int i = 0; i < n; i++){
    vector<int> dp2(m, INF);
    for (int j = 0; j < m; j++){
      if (dp[j] != INF){
        int p = -1;
        for (int l = 0; l <= k * 2; l++){
          if ((mask[j] >> l & 1) == 0){
            if (p == -1){
              p = l;
            }
            int x = i - k + l;
            if (0 <= x && x < n){
              int j2 = id[(mask[j] + (1 << l)) >> 1];
              int c = 0;
              if (i + k + 1 <= n){
                c = S[q[x]][i + k + 1];
              }
              for (int a = 0; a < k * 2; a++){
                if ((mask[j2] >> a & 1) == 0){
                  int y = i - k + a + 1;
                  if (y < n){
                    if (q[y] < q[x]){
                      c++;
                    }
                  }
                }
              }
              dp2[j2] = min(dp2[j2], dp[j] + c);
            }
            if (l == 0){
              break;
            }
          }
          if (p != -1 && l == p + k){
            break;
          }
        }
      }
    }
    swap(dp, dp2);
  }
  cout << dp[0] << endl;
}