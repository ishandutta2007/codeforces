#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
const int MOD1 = 999989981;
const int MOD2 = 999999893;
const int INF = INT_MAX / 2;
struct edge { int i, v; };

int pow_mod(ll x, ll n, int M) {
	ll ans = 1;
	for (; n; n>>=1) {
		if (n & 1) ans = ans * x % M;
		x = x * x % M;
	}
	return ans;
}

int inv_mod(int x, int p) {
	return pow_mod(x, p - 2, p);
}

struct rolling_hash {
	int M;
	vector<int> a, b;
	rolling_hash() {}
	rolling_hash(string s, int _M) {
		M = _M;
		int N = s.length();
		a.resize(N + 1);
		ll x = 1;
		for (int i = 0; i < N; i++) {
			a[i + 1] = (a[i] + x * s[i]) % M;
			x = x * 256 % M;
		}
		ll inv = inv_mod(256, M);
		b.resize(N + 1);
		b[0] = 1;
		for (int i = 0; i < N; i++)
			b[i + 1] = b[i] * inv % M;
	}
	int get(int l, int r) {
		return ((ll)(a[r] - a[l]) * b[l] % M + M) % M;
	}
};

int main() {
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<string> s(N);
		rep(i, N) cin >> s[i];
		vector<rolling_hash> a1(N), a2(N);
		rep(i, N) a1[i] = rolling_hash(s[i], MOD1);
		rep(i, N) a2[i] = rolling_hash(s[i], MOD2);
		vector<i_i> v;
		rep(i, N) for (int j = 1; j <= s[i].length(); j++)
			v.pb(i_i(j, i));
		sort(v.rbegin(), v.rend());
		set<ll> ng;
		int ans = 0;
		for (i_i ji: v) {
			int i = ji.second, j = ji.first;
			ll x = (ll)a1[i].get(0, j) * MOD2 + a2[i].get(0, j);
			if (ng.count(x)) continue;
			ans++;
			ng.insert(x);
			ll y = (ll)a1[i].get(1, j) * MOD2 + a2[i].get(1, j);
			ng.insert(y);
		}
		printf("%d\n", ans);
	}
}