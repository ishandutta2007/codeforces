#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int mod = 1000000007;
const int maxn = 1000010;

ll facts[maxn];
ll ifacts[maxn];

ll mult(ll a, ll b) {
	return a * b % mod;
}

void add(ll & a, ll b) {
	a = (a + b) % mod;
}

ll modpow(ll base, ll p) {
	if (p == 0) return 1LL;
	if (p%2 == 0) {
		ll tmp = modpow(base, p/2);
		return mult(tmp, tmp);
	}
	ll tmp = modpow(base, p-1);
	return mult(tmp, base);
}

ll inv(ll base) {
	return modpow(base, mod-2);
}

ll modmod(ll base, ll p) {
	if (p == -1) return inv(base);
	return modpow(base, p);
}

ll ans = 0LL;
int n, m, a, b;

ll choose(int u, int v) {
	ll res = facts[u];
	res = mult(res, ifacts[v]);
	res = mult(res, ifacts[u-v]);
	// cout << u << " choose " << v << " :: " << res << endl;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> a >> b;

	facts[0] = ifacts[0] = 1LL;
	for (int i = 1; i <= max(n, m); i++) {
		facts[i] = mult(facts[i-1], i);
		ifacts[i] = inv(facts[i]);
	}

	for (int i = 0; i <= n-2; i++) {
		//number of nodes in the middle

		int ne = i+1;
		if (m < ne) continue;

		ll res = 1LL; 
		res = mult(res, facts[n-2]);
		res = mult(res, ifacts[n-2-i]);

		res = mult(res, choose(m-1, ne-1));

		// cout << "    " << res << endl;

		res = mult(res, i+2);
		res = mult(res, modmod(n, n - (i+2) - 1));

		// cout << "thing count: " << mult(i+2, modmod(n, n - (i+2) - 1)) << endl;

		// cout << "   val :: " << n - 1 - ne << endl;

		if (n - 1 - ne > 0) res = mult(res, modmod(m, n - 1 - ne));

		// cout << i << " nodes in middle: " << res << endl;

		add(ans, res);

	}
	cout << ans << endl;
}