#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; i++){
    cin >> s[i];
  }
  vector<vector<vector<int>>> S(26, vector<vector<int>>(n + 1, vector<int>(m + 1, 0)));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      S[s[i][j] - 'a'][i + 1][j + 1]++;
    }
  }
  for (int i = 0; i < 26; i++){
    for (int j = 1; j <= n; j++){
      for (int k = 1; k <= m; k++){
        S[i][j][k] += S[i][j][k - 1];
      }
    }
    for (int j = 1; j <= n; j++){
      for (int k = 1; k <= m; k++){
        S[i][j][k] += S[i][j - 1][k];
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < m; i++){
    vector<int> U, D;
    U.push_back(0);
    D.push_back(0);
    int cnt = 1;
    for (int j = 1; j < n; j++){
      if (s[j][i] == s[j - 1][i]){
        D.back()++;
      } else {
        U.push_back(j);
        D.push_back(j);
        cnt++;
      }
    }
    for (int j = 1; j < cnt - 1; j++){
      int u = U[j];
      int d = D[j] + 1;
      int h = d - u;
      if (u >= h && d + h <= n){
        int c1 = s[u - 1][i] - 'a';
        int c2 = s[u][i] - 'a';
        int c3 = s[d][i] - 'a';
        int tv = 0;
        int fv = m + 1 - i;
        while (fv - tv > 1){
          int mid = (tv + fv) / 2;
          int r = i + mid;
          bool ok = true;
          if (S[c1][u][r] - S[c1][u][i] - S[c1][u - h][r] + S[c1][u - h][i] != h * mid){
            ok = false;
          }
          if (S[c2][d][r] - S[c2][d][i] - S[c2][u][r] + S[c2][u][i] != h * mid){
            ok = false;
          }
          if (S[c3][d + h][r] - S[c3][d + h][i] - S[c3][d][r] + S[c3][d][i] != h * mid){
            ok = false;
          }
          if (ok){
            tv = mid;
          } else {
            fv = mid;
          }
        }
        ans += tv;
      }
    }
  }
  cout << ans << endl;
}