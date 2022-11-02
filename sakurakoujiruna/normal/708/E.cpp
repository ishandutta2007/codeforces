#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using db = double;
#define pb push_back
#define fir first
#define sec second

const ll mod = 1e9L + 7;

ll qpow(ll a, ll b) {
	ll r = 1;
	for(; b; b /= 2) {
		if(b & 1)
			r = r * a % mod;
		a = a * a % mod;
	}
	return r;
}

const int N = 1e5L + 11;
ll fac[N], inv[N];
ll binom(ll n, ll m) {
	return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

const int M = 2e3L + 11;
ll q[M], pre[2][M], suf[2][M];

int main() {
	fac[0] = inv[0] = fac[1] = inv[1] = 1;
	for(int i = 2; i < N; i ++)
		inv[i] = (mod - mod / i) * inv[mod % i] % mod;
	for(int i = 2; i < N; i ++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = inv[i - 1] * inv[i] % mod;
	}
	
	ios :: sync_with_stdio(0);
	int n, m, a, b, k;
	cin >> n >> m >> a >> b >> k;
	ll p = a * qpow(b, mod - 2) % mod;
	
	for(int i = 0; i <= m; i ++) if(i <= k)
		q[i] = binom(k, i) * qpow(p, i) % mod * qpow((1 - p + mod) % mod, k - i) % mod;
	
	for(int i = 1; i <= m; i ++)
		for(int j = i; j <= m; j ++) {
			pre[0][j] += q[i - 1] * q[m - j] % mod;
			suf[0][i] += q[i - 1] * q[m - j] % mod;
		}
	for(int i = 1; i <= m; i ++) pre[0][i] = (pre[0][i] + pre[0][i - 1]) % mod;
	for(int i = m; i >= 1; i --) suf[0][i] = (suf[0][i] + suf[0][i + 1]) % mod;
	
	int s = 0; //cout << pre[s][m] << '\n';
	for(int _ = 2; _ <= n; _ ++) {
		int t = s ^ 1;
		memset(pre[t], 0, sizeof pre[t]);
		memset(suf[t], 0, sizeof suf[t]);
		
		ll all = pre[s][m], sum = 0;
		for(int i = 1; i <= m; i ++) {
			sum += q[i - 1]; sum %= mod;
			pre[t][i] += sum * q[m - i] % mod * (all - suf[s][i + 1]) % mod;
		}
		sum = 0;
		for(int i = m; i >= 1; i --) {
			sum += q[m - i]; sum %= mod;
			suf[t][i] += sum * q[i - 1] % mod * (all - pre[s][i - 1]) % mod;
		}
		
		sum = 0;
		for(int i = 1; i <= m; i ++) {
			sum += q[i - 1] * pre[s][i - 1]; sum %= mod;
			pre[t][i] -= sum * q[m - i] % mod;
		}
		sum = 0;
		for(int i = m; i >= 1; i --) {
			sum += q[m - i] * suf[s][i + 1]; sum %= mod;
			suf[t][i] -= sum * q[i - 1] % mod;
		}
		
		for(int i = 1; i <= m; i ++) pre[t][i] = ((pre[t][i] + pre[t][i - 1]) % mod + mod) % mod;
		for(int i = m; i >= 1; i --) suf[t][i] = ((suf[t][i] + suf[t][i + 1]) % mod + mod) % mod;
		
		s = t;
	}
	
	cout << pre[s][m] << '\n';
	
	return 0;
}