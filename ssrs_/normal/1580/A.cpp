#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        char c;
        cin >> c;
        A[j][k] = c - '0';
      }
    }
    vector<vector<int>> S(n + 1, vector<int>(m));
    for (int j = 0; j < m; j++){
      S[0][j] = 0;
      for (int k = 0; k < n; k++){
        S[k + 1][j] = S[k][j] + A[k][j];
      }
    }
    int ans = INF;
    for (int j = 0; j < n; j++){
      for (int k = j + 5; k <= n; k++){
        vector<int> X(m), Y(m);
        for (int l = 0; l < m; l++){
          X[l] = (k - j - 2) - (S[k - 1][l] - S[j + 1][l]);
          Y[l] = S[k - 1][l] - S[j + 1][l];
          if (A[j][l] == 0){
            Y[l]++;
          }
          if (A[k - 1][l] == 0){
            Y[l]++;
          }
        }
        vector<int> T(m + 1);
        T[0] = 0;
        for (int l = 0; l < m; l++){
          T[l + 1] = T[l] + Y[l];
        }
        vector<int> mn(m);
        mn[0] = INF;
        for (int l = 1; l < m; l++){
          mn[l] = min(mn[l - 1], X[l - 1] - T[l]);
        }
        for (int l = 3; l < m; l++){
          ans = min(ans, T[l] + X[l] + mn[l - 2]);
        }
      }
    }
    cout << ans << endl;
  }
}