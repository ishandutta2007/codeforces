#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, A, B;
    cin >> n >> A >> B;
    string S;
    cin >> S;
    vector<vector<vector<vector<bool>>>> dp(n + 1, vector<vector<vector<bool>>>(A, vector<vector<bool>>(B, vector<bool>(n + 1, false))));
    vector<vector<vector<vector<int>>>> p1(n + 1, vector<vector<vector<int>>>(A, vector<vector<int>>(B, vector<int>(n + 1, -1))));
    vector<vector<vector<vector<int>>>> p2(n + 1, vector<vector<vector<int>>>(A, vector<vector<int>>(B, vector<int>(n + 1, -1))));
    vector<vector<vector<vector<int>>>> p3(n + 1, vector<vector<vector<int>>>(A, vector<vector<int>>(B, vector<int>(n + 1, -1))));
    dp[0][0][0][0] = true;
    for (int j = 0; j < n; j++){
      for (int k = 0; k < A; k++){
        for (int l = 0; l < B; l++){
          for (int m = 0; m <= j; m++){
            if (dp[j][k][l][m]){
              int k2 = (k * 10 + (S[j] - '0')) % A;
              dp[j + 1][k2][l][m + 1] = true;
              p1[j + 1][k2][l][m + 1] = k;
              p2[j + 1][k2][l][m + 1] = l;
              p3[j + 1][k2][l][m + 1] = m;
              int l2 = (l * 10 + (S[j] - '0')) % B;
              dp[j + 1][k][l2][m] = true;
              p1[j + 1][k][l2][m] = k;
              p2[j + 1][k][l2][m] = l;
              p3[j + 1][k][l2][m] = m;
            }
          }
        }
      }
    }
    int ans = INF;
    int p = -1;
    for (int j = 1; j < n; j++){
      if (dp[n][0][0][j]){
        int d = abs(j - (n - j));
        if (ans > d){
          ans = d;
          p = j;
        }
      }
    }
    if (ans == INF){
      cout << -1 << endl;
    } else {
      string S;
      int c1 = 0, c2 = 0, c3 = p;
      for (int j = n; j >= 1; j--){
        int n1 = p1[j][c1][c2][c3];
        int n2 = p2[j][c1][c2][c3];
        int n3 = p3[j][c1][c2][c3];
        if (n3 == c3){
          S += 'B';
        } else {
          S += 'R';
        }
        c1 = n1;
        c2 = n2;
        c3 = n3;
      }
      reverse(S.begin(), S.end());
      cout << S << endl;
    }
  }
}