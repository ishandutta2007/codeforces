#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll mod;

struct mat {
	ll a[2][2];
	ll* operator [](int i) { return a[i]; }
	mat operator *(mat m) {
		mat r;
		for(int i : {0, 1})
			for(int j : {0, 1}) {
				r[i][j] = 0;
				for(int k : {0, 1})
					r[i][j] += a[i][k] * m[k][j];
				r[i][j] %= mod;
			}
		return r;
	}
};

const int N = 5e4L + 11, M = 18;
mat e, a[N][M];
mat query(int l, int r) {
	if(l > r) return e;
	int log2 = 31 - __builtin_clz(r - l + 1);
	return query(l, r - (1 << log2)) * a[r][log2];
}

mat qpow(mat a, ll b) {
	mat r = e;
	for(; b; b /= 2) {
		if(b & 1)
			r = r * a;
		a = a * a;
	}
	return r;
}

int n;
ll _s[N]; map <ll, ll> _mp;
ll s(ll i) {
	if(_mp.count(i))
		return _mp[i];
	return _s[(i + n) % n];
}

mat mt(ll i) {
	mat r;
	r[0][0] = 0; r[0][1] = s(i - 1);
	r[1][0] = 1; r[1][1] = s(i);
	return r;
}

int main() {
	e[0][0] = e[1][1] = 1; e[0][1] = e[1][0] = 0;
	ios :: sync_with_stdio(0);
	ll k;
	cin >> k >> mod;
	cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> _s[i];
	int m; cin >> m;
	set <ll> st;
	while(m --) {
		ll j, v; cin >> j >> v;
		_mp[j] = v;
		st.insert(j); st.insert(j + 1);
	}
	for(int i = 0; i < n; i ++) {
		a[i][0] = mt(i);
		for(int j = 0; j + 1 < M; j ++) if(i - (1 << j) >= 0)
			a[i][j + 1] = a[i - (1 << j)][j] * a[i][j];
	}
	mat ans = e;
	for(ll p = 0; p < k; ) {
		if(*st.begin() == p + 1) {
			ans = ans * mt(++ p);
			st.erase(st.begin());
		} else {
			ll l = p + 1;
			ll r = k;
			if(st.size() && *st.begin() <= k)
				r = *st.begin() - 1;
			if(l / n == r / n)
				ans = ans * query(l % n, r % n);
			else
				ans = ans * query(l % n, n - 1) *
					qpow(query(0, n - 1), r / n - l / n - 1) * query(0, r % n);
			p = r;
		}
	}
	cout << ans[1][0] % mod << '\n';
}