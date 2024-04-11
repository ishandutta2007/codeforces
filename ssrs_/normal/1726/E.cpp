#include <bits/stdc++.h>
using namespace std;
const long long HALF = 499122177;
const long long MOD = 998244353;
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
vector<long long> ntt(vector<long long> A, bool inv){
	int N = A.size();
	long long r = 3;
	if (inv){
		r = modinv(r);
	}
	vector<long long> B(N);
	for (int i = N / 2; i > 0; i /= 2){
		long long z = modpow(r, (MOD - 1) / (N / i));
		long long z2 = 1;
		for (int j = 0; j < N; j += i * 2){
			for (int k = 0; k < i; k++){
				A[i + j + k] *= z2;
				A[i + j + k] %= MOD;
				B[j / 2 + k] = (A[j + k] + A[i + j + k]) % MOD;
				B[N / 2 + j / 2 + k] = (A[j + k] - A[i + j + k] + MOD) % MOD;
			}
			z2 = z2 * z % MOD;
		}
		swap(A, B);
	}
	if (inv){
		int Ninv = modinv(N);
		for (int i = 0; i < N; i++){
			A[i] = A[i] * Ninv % MOD;
		}
	}
	return A;
}
vector<long long> convolution(vector<long long> A, vector<long long> B, int d = -1){
	int deg = A.size() + B.size() - 1;
	int N = 1;
	while (N < deg){
		N *= 2;
	}
	A.resize(N);
	B.resize(N);
	A = ntt(A, false);
	B = ntt(B, false);
	vector<long long> ans(N);
	for (int i = 0; i < N; i++){
		ans[i] = A[i] * B[i] % MOD;
	}
	ans = ntt(ans, true);
	if (d != -1){
		deg = d;
	}
	ans.resize(deg);
	return ans;
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<long long> inv(n + 1);
    inv[1] = 1;
    for (int j = 2; j <= n; j++){
      inv[j] = MOD - inv[MOD % j] * (MOD / j) % MOD;
    }
    vector<long long> fact(n + 1), finv(n + 1);
    fact[0] = 1;
    finv[0] = 1;
    for (int j = 1; j <= n; j++){
      fact[j] = fact[j - 1] * j % MOD;
      finv[j] = finv[j - 1] * inv[j] % MOD;
    }
    vector<long long> hpow(n + 1);
    hpow[0] = 1;
    for (int j = 0; j < n; j++){
      hpow[j + 1] = hpow[j] * HALF % MOD;
    }
    vector<long long> f(n + 1, 0);
    for (int j = 0; j * 2 <= n; j++){
      f[j * 2] = finv[j] * hpow[j] % MOD;
    }
    vector<long long> g = finv;
    vector<long long> h = convolution(f, g);
    vector<long long> tmp(n + 1);
    for (int j = 0; j <= n; j++){
      tmp[j] = h[j] * fact[j] % MOD;
    }
    long long ans = 0;
    for (int j = 0; j * 4 <= n; j++){
      ans += tmp[n - j * 4] * fact[n - j * 2] % MOD * finv[n - j * 4] % MOD * finv[j] % MOD;
    }
    ans %= MOD;
    cout << ans << endl;
  }
}