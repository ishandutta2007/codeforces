#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long modpow(long long a, long long b){
  long long ans = 1;
  while (b > 0){
    if (b % 2 == 1){
      ans *= a;
      ans %= MOD;
    }
    a *= a;
    a %= MOD;
    b /= 2;
  }
  return ans;
}
long long modinv(long long a){
  return modpow(a, MOD - 2);
}
int main(){
  int n;
  cin >> n;
  vector<vector<bool>> E(n, vector<bool>(n, false));
  for (int i = 0; i < n - 1; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u][v] = true;
    E[v][u] = true;
  }
  vector<long long> P(n);
  for (int i = 0; i < n; i++){
    vector<vector<long long>> A(n, vector<long long>(n, 0));
    for (int j = 0; j < n; j++){
      for (int k = j + 1; k < n; k++){
        int x;
        if (E[j][k]){
          x = i;
        } else {
          x = 1;
        }
        A[j][k] = (MOD - x) % MOD;
        A[k][j] = (MOD - x) % MOD;
        A[j][j] += x;
        A[j][j] %= MOD;
        A[k][k] += x;
        A[k][k] %= MOD;
      }
    }
    vector<vector<long long>> A2(n - 1, vector<long long>(n - 1));
    for (int j = 0; j < n - 1; j++){
      for (int k = 0; k < n - 1; k++){
        A2[j][k] = A[j][k];
      }
    }
    long long det = 1;
    for (int j = 0; j < n - 1; j++){
      int p = -1;
      for (int k = j; k < n - 1; k++){
        if (A2[k][j] > 0){
          p = k;
        }
      }
      if (p == -1){
        det = 0;
        break;
      }
      swap(A2[j], A2[p]);
      if (p != j){
        det = MOD - det;
      }
      det *= A2[j][j];
      det %= MOD;
      long long r = modinv(A2[j][j]);
      for (int k = j; k < n - 1; k++){
        A2[j][k] *= r;
        A2[j][k] %= MOD;
      }
      for (int k = 0; k < n - 1; k++){
        if (k != j){
          for (int l = 0; l < n - 1; l++){
            if (l != j){
              A2[k][l] -= A2[k][j] * A2[j][l] % MOD;
              if (A2[k][l] < 0){
                A2[k][l] += MOD;
              }
            }
          }
          A2[k][j] = 0;
        }
      }
    }
    P[i] = det;
  }
  vector<vector<long long>> A(n, vector<long long>(n + 1, 0));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      A[i][j] = modpow(i, j);
    }
    A[i][n] = P[i];
  }
  for (int i = 0; i < n; i++){
    int p = -1;
    for (int j = 0; j < n; j++){
      if (A[j][i] > 0){
        p = j;
      }
    }
    swap(A[i], A[p]);
    long long r = modinv(A[i][i]);
    for (int j = i; j <= n; j++){
      A[i][j] *= r;
      A[i][j] %= MOD;
    }
    for (int j = 0; j < n; j++){
      if (j != i){
        for (int k = 0; k <= n; k++){
          if (k != i){
            A[j][k] -= A[j][i] * A[i][k] % MOD;
            if (A[j][k] < 0){
              A[j][k] += MOD;
            }
          }
        }
        A[j][i] = 0;
      }
    }
  }
  for (int i = 0; i < n; i++){
    cout << A[i][n];
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}