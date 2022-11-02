#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using db = double;
#define pb push_back
#define fir first
#define sec second

const int N = 1e6L + 11;
int p[N];
ll phi[N];

const ll mod = 1e9L + 7;
ll s1(ll n) {
	return n * (n + 1) / 2 % mod;
}
ll s2(ll n) {
	return n * (n + 1) * (2 * n + 1) / 6 % mod;
}

ll f[N], fi[N], fii[N];

int main() {
	for(int i = 2; i < N; i ++) if(!p[i])
		for(int j = i; j < N; j += i) if(!p[j]) p[j] = i;
	phi[1] = 1;
	for(int i = 2; i < N; i ++)
		if(p[i] == i) phi[i] = i - 1;
		else {
			int j = i / p[i];
			if(p[j] == p[i])
				phi[i] = phi[j] * p[i];
			else
				phi[i] = phi[j] * (p[i] - 1);
		}
	
	for(ll i = 1; i < N; i ++) {
		f[i] = i * (i * i - 2 * i);
		f[i] -= 2 * i * s1(i);
		f[i] += 2 * s2(i); f[i] %= mod;
	}
	for(int i = 1; i < N; i ++)
		for(int j = i; j < N; j += i) {
			f[j] += 2 * phi[j / i] * i;
			f[j] %= mod;
		}
	
	for(int i = 1; i < N; i ++) {
		if(f[i] < 0) f[i] += mod;
		fi[i] = fi[i - 1] + f[i] * i; fi[i] %= mod;
		fii[i] = fii[i - 1] + f[i] * i % mod * i; fii[i] %= mod;
		f[i] = f[i - 1] + f[i]; f[i] %= mod;
	}
	
	ios :: sync_with_stdio(0);
	int t; cin >> t;
	while(t --) {
		ll n, m; cin >> n >> m;
		ll x = min(n, m);
		ll ans = (n + 1) * (m + 1) % mod * f[x] % mod;
		ans -= (n + 1 + m + 1) * fi[x]; ans %= mod;
		ans += fii[x]; ans %= mod;
		if(ans < 0) ans += mod;
		cout << ans << '\n'; 
	}
	return 0;
}