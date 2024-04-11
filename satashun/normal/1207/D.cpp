#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
#define dump(x) cout << #x << " = " << (x) << endl
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os<<"{";
	rep(i, v.size()) {
		if (i) os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

const ll MOD = 998244353;
const int maxn = 300010;

vector<pii> vec;
ll fact[maxn];

int main() {
	fact[0] = 1;
	for (int i = 1; i < maxn; ++i) {
		fact[i] = fact[i-1] * i % MOD;
	}

	int n; cin >> n;
	rep(i, n) {
		int a, b;
		cin >> a >> b;
		vec.eb(a, b);
	}

	ll ans = 0;

	rep(tt, 2) {
		map<int, int> T;

		rep(i, n) {
			++T[vec[i].fi];
		}

		ll v = 1;

		for (auto &p : T) {
			v = v * fact[p.se] % MOD;
		}

		ans += v;
		ans %= MOD;

		rep(i, n) swap(vec[i].fi, vec[i].se);
	}

	bool f = true;
	sort(ALL(vec));
	rep(i, n-1) {
		if (vec[i].se > vec[i+1].se) {
			f = 0;
		}
	}
	if (f) {

		map<pii, int> T;
		rep(i, n) ++T[vec[i]];

		ll v = 1;

		for (auto &p : T) {
			v = v * fact[p.se] % MOD;
		}

		ans -= v;
		if (ans < 0) ans += MOD;
	}

	ans = fact[n] - ans;
	if (ans < 0) ans += MOD;
	cout << ans << endl;

	return 0;
}