#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
long long modsub(long long a, long long b){
	a %= MOD;
	b %= MOD;
	if (a >= b){
		return (a - b) % MOD;
	} else {
		return MOD - (b - a) % MOD;
	}
}
long long modpow(long long a, long long b){
	a %= MOD;
	long long res = 1;
	while (b > 0){
		if (b % 2 == 1) res = res * a % MOD;
		a = a * a % MOD;
		b = b / 2;
	}
	return res;
}
long long modinv(long long a){
	return modpow(a, MOD - 2);
}
long long moddiv(long long a, long long b){
  return (a % MOD) * modinv(b) % MOD;
}
vector<vector<long long>> matrix_multiplication(vector<vector<long long>> &A, vector<vector<long long>> &B){
  int a = A.size();
  int b = B.size();
  int c = B[0].size();
  vector<vector<long long>> C(a, vector<long long>(c, 0));
  for (int i = 0; i < a; i++){
    for (int j = 0; j < c; j++){
      for (int k = 0; k < b; k++){
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
      }
    }
  }
  return C;
}
vector<vector<long long>> matrix_exponentiation(vector<vector<long long>> A, long long k){
  int n = A.size();
  vector<vector<long long>> ans(n, vector<long long>(n, 0));
  for (int i = 0; i < n; i++){
    ans[i][i] = 1;
  }
  while (k > 0){
    if (k % 2 == 1){
      ans = matrix_multiplication(ans, A);
    }
    A = matrix_multiplication(A, A);
    k /= 2;
  }
  return ans;
}
vector<long long> matrix_vector_multiplication(vector<vector<long long>> M, vector<long long> V){
  int n = M.size();
  int m = V.size();
  vector<long long> ans(n, 0);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      ans[i] = (ans[i] + M[i][j] * V[j]) % MOD;
    }
  }
  return ans;
}
int main(){
  long long n, k;
  cin >> n >> k;
  vector<int> a(n);
  long long m = 0;
  for (int i = 0; i < n; i++){
    cin >> a[i];
    if (a[i] == 0){
      m++;
    }
  }
  if (m == 0){
    cout << 1 << endl;
  } else {
    long long T = (n * (n - 1) / 2) % MOD;
    //s
    vector<vector<long long>> M(m + 1, vector<long long>(m + 1, 0));
    M[0][1] = moddiv(m * m, T);
    M[0][0] = modsub(1, M[0][1]);
    for (int i = 1; i < m; i++){
      M[i][i - 1] = moddiv(i * (n + i - m * 2), T);
      M[i][i + 1] = moddiv((m - i) * (m - i), T);
      M[i][i] = modsub(1, M[i][i - 1] + M[i][i + 1]);
    }
    M[m][m - 1] = moddiv(m * (n - m), T);
    M[m][m] = modsub(1, M[m][m - 1]);
    vector<vector<long long>> M2 = matrix_exponentiation(M, k);
    int c = 0;
    for (int i = 0; i < m; i++){
      if (a[i] == 0){
        c++;
      }
    }
    cout << M2[c][m] << endl;
  }
}