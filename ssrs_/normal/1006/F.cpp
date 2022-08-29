#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  long long k;
  cin >> n >> m >> k;
  vector<vector<long long>> a(n, vector<long long>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> a[i][j];
    }
  }
  vector<vector<map<long long, long long>>> A(n, vector<map<long long, long long>>(m));
  A[0][0][a[0][0]] = 1;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (i + j < (n + m - 2) / 2){
        if (i < n - 1){
          for (auto P : A[i][j]){
            A[i + 1][j][P.first ^ a[i + 1][j]] += P.second;
          }
        }
        if (j < m - 1){
          for (auto P : A[i][j]){
            A[i][j + 1][P.first ^ a[i][j + 1]] += P.second;
          }
        }
      }
    }
  }
  vector<vector<map<long long, long long>>> B(n, vector<map<long long, long long>>(m));
  B[n - 1][m - 1][a[n - 1][m - 1]] = 1;
  for (int i = n - 1; i >= 0; i--){
    for (int j = m - 1; j >= 0; j--){
      if (i + j > (n + m - 2) / 2){
        if (i > 0){
          for (auto P : B[i][j]){
            B[i - 1][j][P.first ^ a[i - 1][j]] += P.second;
          }
        }
        if (j > 0){
          for (auto P : B[i][j]){
            B[i][j - 1][P.first ^ a[i][j - 1]] += P.second;
          }
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (i + j == (n + m - 2) / 2){
        for (auto P : A[i][j]){
          ans += P.second * B[i][j][k ^ P.first ^ a[i][j]];
        }
      }
    }
  }
  cout << ans << endl;
}