#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll p;
ll qmul(ll a, ll b) {
	ll r = 0;
	for(; b > 0; b >>= 10) {
		r = r + a * (b & 1023);
		a = (a << 10) % p;
	}
	return r % p;
}
ll qpow(ll a, ll b) {
	static map <ll, ll> mp;
	if(mp.count(a)) return mp[a];
	ll r = 1, ca = a;
	for(; b > 0; b >>= 1) {
		if(b & 1)
			r = qmul(r, a);
		a = qmul(a, a);
	}
	return mp[ca] = r;
}
void fwt(ll *a, int n, int op = 1) {
	for (int i = 1; i < n; i *= 2)
		for (int j = 0; j < n; j += i * 2)
			for (int k = 0; k < i; ++k) {
				ll x = a[j + k], y = a[j + k + i];
				a[j + k] = x + y - (x + y >= p) * p;
				a[j + k + i] = x - y + (x < y) * p;
			}
	if (op == -1) for (int i = 0; i < n; ++i) a[i] = a[i] / n;
}

const int N = 1 << 20;
ll e[N], t[N], b[N];

int main() {
	//ios :: sync_with_stdio(false);
	int m; ll k; cin >> m >> k >> p;
	int n = 1 << m;
	p = p << m;
	for(int i = 0; i < n; i ++) {
		//cin >> e[i];
		scanf("%d", e + i);
		e[i] = e[i] % p;
	}
	for(int i = 0; i <= m; i ++) {
		//cin >> b[i];
		scanf("%d", b + i);
		b[i] = b[i] % p;
	}
	
	for(int i = 0; i < n; i ++)
		t[i] = b[__builtin_popcount(i)];
	fwt(e, n); fwt(t, n);
	for(int i = 0; i < n; i ++)
		e[i] = qmul(e[i], qpow(t[i], k));
	fwt(e, n, -1);
	for(int i = 0; i < n; i ++)
		//cout << e[i] << '\n';
		printf("%d\n", e[i]);
	return 0;
}
//