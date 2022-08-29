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
vector<long long> convolution(vector<long long> A, vector<long long> B){
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
	ans.resize(deg);
	return ans;
}
int main(){
  int n;
  cin >> n;
  vector<long long> pr(n, 0);
  pr[0] = 1;
  /*
  for (int i = 1; i < n; i++){
    for (int j = (n - 1) / 2; j < n - i; j++){
      long long add = i;
      add *= modfact(n - 1 - i);
      add %= MOD;
      add *= modfact(n - 2 - j);
      add %= MOD;
      add *= modfactinv(n - 1 - i - j);
      add %= MOD;
      add *= modfactinv(n - 1);
      add %= MOD;
      pr[i] += add;
      pr[i] %= MOD;
    }
  }
  */
  vector<long long> f(n, 0);
  for (int i = 0; i < n; i++){
    f[i] = modfactinv(n - 1 - i);
  }
  vector<long long> g(n, 0);
  for (int i = 2; i <= (n + 1) / 2; i++){
    g[i] = modfact(i - 2);
  }
  vector<long long> fg = convolution(f, g);
  for (int i = 1; i < n; i++){
    pr[i] = fg[n + i] * i % MOD * modfact(n - 1 - i) % MOD * modfactinv(n - 1) % MOD;
  }
  vector<long long> ans = pr;
  /*
  for (int i = 0; i < n; i++){
    for (int j = i + 1; j < n; j++){
      ans[i] += MOD - pr[j] * modinv(j) % MOD;
      ans[i] %= MOD;
    }
  }*/
  long long sum = 0;
  for (int i = n - 1; i >= 0; i--){
    ans[i] += MOD - sum;
    ans[i] %= MOD;
    if (i > 0){
      sum += pr[i] * modinv(i);
      sum %= MOD;
    }
  }
  for (int i = 0; i < n; i++){
    cout << ans[i] * modfact(n - 1) % MOD;
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}