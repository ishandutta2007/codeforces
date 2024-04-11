#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
vector<vector<long long>> matmul(vector<vector<long long>> A, vector<vector<long long>> B){
	int N = A.size();
	int K = N / 4;
	vector<vector<long long>> ans(N, vector<long long>(N, 0));
	for (int i1 = 0; i1 < K; i1++){
		for (int j1 = i1; j1 < K; j1++){
			for (int k1 = j1; k1 < K; k1++){
				for (int i = i1; i < N; i += K){
					for (int j = j1; j < N; j += K){
						for (int k = k1; k < N; k += K){
							ans[i][k] += A[i][j] * B[j][k];
							ans[i][k] %= MOD;
						}
					}
				}
			}
		}
	}
	return ans;
}
vector<vector<long long>> matexp(vector<vector<long long>> A, long long b){
	int N = A.size();
	vector<vector<long long>> ans(N, vector<long long>(N, 0));
	for (int i = 0; i < N; i++){
		ans[i][i] = 1;
	}
	while (b > 0){
		if (b % 2 == 1){
			ans = matmul(ans, A);
		}
		A = matmul(A, A);
		b /= 2;
	}
	return ans;
}
int main(){
  long long n;
  int k;
  cin >> n >> k;
  vector<vector<long long>> binom(k + 1, vector<long long>(k + 1, 1));
  for (int i = 2; i <= k; i++){
    for (int j = 1; j < i; j++){
      binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % MOD;
    }
  }
  int k1 = k + 1;
  vector<vector<long long>> A(k1 * 4, vector<long long>(k1 * 4, 0));
  for (int i = 0; i <= k; i++){
    for (int j = i; j <= k; j++){
      long long tmp = binom[k - i][j - i];
      A[i][j] = tmp;
      A[i + k1][j] = tmp;
      A[i][j + k1] = tmp;
    }
  }
  for (int i = 0; i < k1 * 2; i++){
    A[k1 * 2 + i][i] = 1;
    A[k1 * 2 + i][k1 * 2 + i] = 1;
  }
  A = matexp(A, n);
  long long ans = 0;
  for (int i = 0; i < k1 * 2; i++){
    ans += A[k1 * 2][i];
  }
  ans %= MOD;
  cout << ans << endl;
}