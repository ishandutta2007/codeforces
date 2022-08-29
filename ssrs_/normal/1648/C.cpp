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
template <typename T>
struct binary_indexed_tree{
  int N;
  vector<T> BIT;
  binary_indexed_tree(vector<T> &A){
    N = A.size();
    BIT = vector<T>(N + 1, 0);
    for (int i = 0; i < N; i++){
      BIT[i + 1] = A[i];
    }
    for (int i = 1; i < N; i++){
      if (i + (i & -i) <= N){
        BIT[i + (i & -i)] += BIT[i];
      }
    }
  }
  void add(int i, T x){
    i++;
    while (i <= N){
      BIT[i] += x;
      i += i & -i;
    }
  }
  T sum(int i){
    T ans = 0;
    while (i > 0){
      ans += BIT[i];
      i -= i & -i;
    }
    return ans;
  }
  T sum(int L, int R){
    return sum(R) - sum(L);
  }
};
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> s(n);
  for (int i = 0; i < n; i++){
    cin >> s[i];
    s[i]--;
  }
  vector<int> t(m);
  for (int i = 0; i < m; i++){
    cin >> t[i];
    t[i]--;
  }
  vector<int> cnt(200000, 0);
  for (int i = 0; i < n; i++){
    cnt[s[i]]++;
  }
  long long all = modfact(n);
  for (int i = 0; i < 200000; i++){
    all *= modfactinv(cnt[i]);
    all %= MOD;
  }
  binary_indexed_tree<int> BIT(cnt);
  long long ans = 0;
  bool ok = true;
  for (int i = 0; i < min(m, n); i++){
    int x = BIT.sum(0, t[i]);
    int y = n - i;
    ans += all * x % MOD * modinv(y) % MOD;
    int x2 = BIT.sum(t[i], t[i] + 1);
    if (x2 == 0){
      ok = false;
      break;
    }
    all = all * x2 % MOD * modinv(y) % MOD;
    BIT.add(t[i], -1);
  }
  if (ok && m > n){
    ans += all;
  }
  ans %= MOD;
  cout << ans << endl;
}