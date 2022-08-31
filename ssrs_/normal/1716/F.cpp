#include <bits/stdc++.h>
using namespace std;
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
vector<long long> mf = {1};
vector<long long> mfi = {1};
long long modfact(int n){
	if (mf.size() > n){
		return mf[n];
	} else {
		for (int i = mf.size(); i <= n; i++){
			long long next = mf.back() * i % MOD;
			mf.push_back(next);
			mfi.push_back(modinv(next));
		}
		return mf[n];
	}
}
long long modfactinv(int n){
	if (mfi.size() > n){
		return mfi[n];
	} else {
		return modinv(modfact(n));
	}
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
  vector<long long> f(2001, 0);
  for (int i = 1; i <= 2000; i++){
    f[i] = modfactinv(i);
  }
  vector<vector<int>> co(2001, vector<int>(2001, 0));
  co[0][0] = 1;
  for (int i = 0; i <= 2000; i++){
    co[1][i] = f[i];
  }
  vector<long long> h = convolution(f, f);
  vector<long long> g = f;
  for (int i = 2; i <= 2000; i++){
    g = convolution(g, f);
    g.resize(2001);
    for (int j = 0; j <= 2000; j++){
      co[i][j] = g[j];
    }
  }
  vector<long long> inv(2001);
  inv[1] = 1;
  for (int i = 2; i <= 2000; i++){
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m, k;
    cin >> n >> m >> k;
    long long m2 = modinv(m);
    long long ans = 0;
    long long binom = 1;
    long long X = modpow(m, n);
    long long Y = 1;
    for (int j = 0; j <= min(n, k); j++){
      long long add = binom;
      add *= X;
      add %= MOD;
      add *= Y;
      add %= MOD;
      add *= co[j][k];
      add %= MOD;
      ans += add;
      binom *= n - j;
      binom %= MOD;
      binom *= inv[j + 1];
      binom %= MOD;
      X *= m2;
      X %= MOD;
      Y *= (m + 1) / 2;
      Y %= MOD;
    }
    ans %= MOD;
    ans *= modfact(k);
    ans %= MOD;
    cout << ans << endl;
  }
}