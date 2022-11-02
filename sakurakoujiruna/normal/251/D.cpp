#include <bits/stdc++.h>
using namespace std;

#define pb push_back
using ll = long long;
const int N = 1e5L + 11;

ll a[N], b[N];
vector <ll> v[N];
int ans[N];

ll hb(ll x) { return (1LL << (63 - __builtin_clzll(x))); }

int main() {
	ios :: sync_with_stdio(0);
	int n; cin >> n;
	ll all = 0;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		all ^= a[i];
	}
	int m = 0;
	for(int i = 0; i <= 60; i ++) if((all >> i) & 1) {
		for(int j = 1; j <= n; j ++)
			b[j] |= ((a[j] >> i) & 1) << m;
		m ++;
	}
	for(int i = 0; i <= 60; i ++) if((all >> i) & 1 ^ 1) {
		for(int j = 1; j <= n; j ++)
			b[j] |= ((a[j] >> i) & 1) << m;
		m ++;
	}

	for(int i = 1; i <= n; i ++) {
		ll t = b[i];
		v[i] = v[i - 1];
		for(ll x : v[i])
			if(hb(x) & t) t ^= x;
		if(t) {
			for(ll &x : v[i])
				if(hb(t) & x) x ^= t;
			v[i].pb(t);
		}
	}
	all = 0;
	for(ll x : v[n]) all ^= x;

	auto check = [](vector <ll> &v, ll x) {
		for(ll y : v)
			if(hb(y) & x) x ^= y;
		return x == 0;
	};
	for(int i = n; i >= 1; i --) {
		if(check(v[i - 1], all))
			ans[i] = 1;
		else {
			ans[i] = 2;
			all ^= b[i];
		}
	}
	for(int i = 1; i <= n; i ++)
		cout << ans[i] << ' ';
	cout << '\n';
}