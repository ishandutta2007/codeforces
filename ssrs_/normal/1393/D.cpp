#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long BASE;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  random_device rnd;
  mt19937 mt(rnd());
  BASE = mt() % 100000 + 10000000;
  vector<long long> pow(27);
  pow[0] = 1;
  for (int i = 0; i < 26; i++){
    pow[i + 1] = pow[i] * BASE % MOD;
  }
  int n, m;
  cin >> n >> m;
  vector<string> A(n);
  for (int i = 0; i < n; i++){
    cin >> A[i];
  }
  int N = n + m - 1;
  vector<vector<char>> B(N, vector<char>(N, '{'));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      B[i + j][i - j + m - 1] = A[i][j];
    }
  }
  vector<vector<long long>> hash(N + 1, vector<long long>(N + 1, 0));
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      hash[i + 1][j + 1] = pow[B[i][j] - 'a'];
    }
  }
  for (int i = 1; i <= N; i++){
    for (int j = 1; j <= N; j++){
      hash[i][j] += hash[i][j - 1];
      hash[i][j] %= MOD;
    }
  }
  for (int j = 1; j <= N; j++){
    for (int i = 1; i <= N; i++){
      hash[i][j] += hash[i - 1][j];
      hash[i][j] %= MOD;
    }
  }
  long long ans = 0;
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      if (B[i][j] != '{'){
        int tv = 1;
        int fv = N;
        while (fv - tv > 1){
          int mid = (tv + fv) / 2;
          bool ok = true;
          if (i + mid > N || j + mid > N){
            ok = false;
          } else {
            long long H = hash[i + mid][j + mid] - hash[i][j + mid] - hash[i + mid][j] + hash[i][j];
            H += MOD * 2;
            H %= MOD;
            int c = B[i][j] - 'a';
            if (mid % 2 == 0){
              long long H2 = (mid * mid / 2) * (pow[c] + pow[26]) % MOD;
              if (H != H2){
                ok = false;
              }
            }
            if (mid % 2 == 1){
              long long H2 = ((mid * mid / 2) * (pow[c] + pow[26]) + pow[c]) % MOD;
              if (H != H2){
                ok = false;
              }
            }
          }
          if (ok){
            tv = mid;
          } else {
            fv = mid;
          }
        }
        ans += (tv + 1) / 2;
      }
    }
  }
  cout << ans << endl;
}