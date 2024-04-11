#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long modsub(long long a, long long b){
	return (a % MOD - b % MOD + MOD) % MOD;
}
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
long long modbinom(int n, int k){
	if (n < 0 || k < 0 || k > n){
		return 0;
	} else {
		return modfact(n) * modfactinv(k) % MOD * modfactinv(n - k) % MOD;
	}
}
int main(){
  int N, M, R;
  cin >> N >> M >> R;
  vector<int> X(N), Y(N);
  vector<long long> B(N);
  for (int i = 0; i < N; i++){
    cin >> X[i] >> Y[i] >> B[i];
    X[i]--;
    Y[i]--;
  }
  vector<vector<int>> S(1001, vector<int>(1001, 0));
  for (int i = 0; i < N; i++){
    S[Y[i] + 1][X[i] + 1] = 1;
  }
  for (int i = 1; i <= 1000; i++){
    for (int j = 1; j <= 1000; j++){
      S[i][j] += S[i][j - 1];
    }
  }
  for (int j = 1; j <= 1000; j++){
    for (int i = 1; i <= 1000; i++){
      S[i][j] += S[i - 1][j];
    }
  }
  long long ans = 0;
  vector<int> r(N);
  for (int i = 0; i < N; i++){
    int ymin = max(0, Y[i] - R);
    int ymax = min(1000, Y[i] + R + 1);
    int xmin = max(0, X[i] - R);
    int xmax = min(1000, X[i] + R + 1);
    int cnt = S[ymax][xmax] - S[ymax][xmin] - S[ymin][xmax] + S[ymin][xmin];
    cnt--;
    r[i] = cnt;
    long long coef = 0;
    coef += modbinom(N - 1, M - 1);
    coef += modsub(modbinom(N - 1, M), modbinom(N - 1 - cnt, M));
    coef %= MOD;
    ans += B[i] * B[i] % MOD * coef % MOD;
  }
  for (int i = 0; i < N; i++){
    for (int j = i + 1; j < N; j++){
      int ymin = max({0, Y[i] - R, Y[j] - R});
      int ymax = min({1000, Y[i] + R + 1, Y[j] + R + 1});
      int xmin = max({0, X[i] - R, X[j] - R});
      int xmax = min({1000, X[i] + R + 1, X[j] + R + 1});
      long long coef = 0;
      bool c = abs(Y[j] - Y[i]) <= R && abs(X[j] - X[i]) <= R;
      coef += modbinom(N - 2, M - 2);
      coef += modbinom(N - 2, M - 1);
      if (!c){
        coef += MOD - modbinom(N - r[i] - 2, M - 1);
      }
      coef += modbinom(N - 2, M - 1);
      if (!c){
        coef += MOD - modbinom(N - r[j] - 2, M - 1);
      }
      int cnt = 0;
      if (ymin < ymax && xmin < xmax){
        cnt = S[ymax][xmax] - S[ymax][xmin] - S[ymin][xmax] + S[ymin][xmin];
        if (c){
          cnt -= 2;
        }
        coef += modbinom(N - 2, M);
        coef += MOD - modbinom(N - cnt - 2, M);
      }
      long long tmp = 0;
      tmp += modbinom(N - cnt - 2, M);
      if (!c){
        tmp -= modbinom(N - cnt - 2 - (r[i] - cnt), M);
      } else {
        tmp -= modbinom(N - cnt - 1 - (r[i] - cnt), M);
      }
      if (!c){
        tmp -= modbinom(N - cnt - 2 - (r[j] - cnt), M);
      } else {
        tmp -= modbinom(N - cnt - 1 - (r[j] - cnt), M);
      }
      if (!c){
        tmp += modbinom(N - cnt - 2 - (r[i] - cnt) - (r[j] - cnt), M);
      } else {
        tmp += modbinom(N - cnt - (r[i] - cnt) - (r[j] - cnt), M);
      }
      tmp %= MOD;
      //cout << "i = " << i << ", j = " << j << ", l = " << N - cnt - 2 << ", tmp = " << tmp << endl;
      coef += tmp;
      coef %= MOD;
      ans += 2 * B[i] * B[j] % MOD * coef % MOD;
    }
  }
  ans %= MOD;
  cout << ans << endl;
}