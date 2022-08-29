#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
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
vector<long long> ntt(vector<long long> A, bool inv){
	int N = A.size();
	int M = 0;
	for (int i = 1; i < N; i *= 2){
		M++;
	}
	for (int i = 0; i < N; i++){
		int j = 0;
		for (int k = 0; k < M; k++){
			if ((i >> k) & 1){
				j |= 1 << (M - 1 - k);
			}
		}
		if (i < j){
			swap(A[i], A[j]);
		}
	}
	for (int i = 1; i < N; i *= 2){
		for (int j = 0; j < i; j++){
			long long z = modpow(3, (MOD - 1) / (i * 2) * j);
			if (inv){
				z = modinv(z);
			}
			for (int k = 0; k < N; k += i * 2){
				long long s = A[j + k];
				long long t = A[j + k + i] * z % MOD;
				A[j + k] = (s + t) % MOD;
				A[j + k + i] = (s - t + MOD) % MOD;;
			}
		}
	}
	if (inv){
		int Ninv = modinv(N);
		for (int i = 0; i < N; i++){
			A[i] = A[i] * Ninv % MOD;
		}
	}
	return A;
}
vector<long long> convolution(vector<long long> A, vector<long long> B){
	int deg = A.size() + B.size() - 1;
	int N = 1;
	while (N < deg){
		N *= 2;
	}
	while (A.size() < N){
		A.push_back(0);
	}
	while (B.size() < N){
		B.push_back(0);
	}
	vector<long long> a = ntt(A, false);
	vector<long long> b = ntt(B, false);
	vector<long long> c(N);
	for (int i = 0; i < N; i++){
		c[i] = a[i] * b[i] % MOD;
	}
	c = ntt(c, true);
	vector<long long> ans(deg);
	for (int i = 0; i < deg; i++){
		ans[i] = c[i];
	}
	return ans;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<long long> V1(n, 0);
    vector<long long> V2(n, 0);
    for (int j = 0; j < n; j++){
      if (s[j] == 'V'){
        V1[j] = 1;
        V2[n - j - 1] = 1;
      }
    }
    vector<long long> K1(n, 0);
    vector<long long> K2(n, 0);
    for (int j = 0; j < n; j++){
      if (s[j] == 'K'){
        K1[n - j - 1] = 1;
        K2[j] = 1;
      }
    }
    vector<long long> S2 = convolution(V1, K1);
    vector<long long> S3 = convolution(V2, K2);
    vector<bool> S(n, true);
    for (int j = 0; j < n; j++){
      if (S2[j] != 0 || S3[j] != 0){
        S[n - 1 - j] = false;
      }
    }
    vector<bool> res(n, true);
    for (int j = 1; j < n; j++){
      for (int k = j; k < n; k += j){
        if (!S[k]){
          res[j - 1] = false;
          break;
        }
      }
    }
    vector<int> ans;
    for (int j = 0; j < n; j++){
      if (res[j]){
        ans.push_back(j + 1);
      }
    }
    int cnt = ans.size();
    cout << cnt << "\n";
    for (int j = 0; j < ans.size(); j++){
      cout << ans[j];
      if (j < ans.size() - 1){
        cout << ' ';
      }
    }
    cout << "\n";
  }
}