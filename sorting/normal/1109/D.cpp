#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
const long long N = 2e6 + 7;

long long fast_pow(long long base, long long exp){
	if(exp < 0){
		return fast_pow(base, exp + mod - 1);
	}

	if(exp == 0){
		return 1;
	}

	if(exp & 1){
		long long ret = fast_pow(base, exp - 1);
		ret = (ret * base) % mod;

		return ret;
	}

	long long ret = fast_pow(base, exp/2);

	ret = (ret*ret) % mod;

	return ret;
}

long long inverse(long long x){
	return fast_pow(x, mod-2);
}

long long fact[N], pow_m[N];
long long dp[100][100];

long long combination(long long a, long long b){
	if(b > a){
		return 0;
	}
	
	long long ret = fact[a];
	ret *= inverse(fact[b]);
	ret %= mod;
	ret *= inverse(fact[a-b]);
	ret %= mod;

	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, m, a, b, res = 0;

	cin >> n >> m >> a >> b;

	fact[0] = 1;
	pow_m[0] = 1;
	for(long long i = 1; i < N; i++){
		fact[i] = (fact[i-1] * i) % mod; 
		pow_m[i] = (pow_m[i-1] * m) % mod;
	}

	for(long long i = 1; i < n; i++){
		long long add = (fact[n-2] * inverse(fact[n-1-i])) % mod;
		add *= ((i+1) *fast_pow(n, n - i - 2)) % mod;
		add %= mod;
		add *= pow_m[n-i-1];
		add %= mod;
		//cout << add << endl;

		add *= combination(m - 1, i-1);

		add %= mod;

		res += add;
		res %= mod;
	}

	cout << res << "\n";

	return 0;
}