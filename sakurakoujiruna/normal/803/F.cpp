#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e5L + 11;
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

int p[N], u[N];
int cnt[N];

int main() {
	for(int i = 2; i < N; i ++) if(!p[i])
		for(int j = i; j < N; j += i) if(!p[j]) p[j] = i;
	u[1] = 1;
	for(int i = 2; i < N; i ++)
		if(p[i] == i) u[i] = -1;
		else {
			int j = i / p[i];
			if(p[i] == p[j])
				u[i] = 0;
			else
				u[i] = -u[j];
		}
	
	ios :: sync_with_stdio(0);
	int n; cin >> n;
	for(int i = 1; i <= n; i ++) {
		int x; cin >> x;
		cnt[x] ++;
	}
	
	ll ans = 0;
	for(int i = 1; i < N; i ++) {
		int t = 0;
		for(int j = i; j < N; j += i)
			t += cnt[j];
		ans += u[i] * (qpow(2, t) - 1);
		ans %= mod;
	}
	cout << (ans + mod) % mod << '\n';
}