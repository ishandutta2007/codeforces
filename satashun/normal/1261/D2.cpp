#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

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

template<class T, class U> void chmin(T& t, const U& u) { if (t > u) t = u; }
template<class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }

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
const int MX = 200010;

ll inv[MX], fact[MX], ifact[MX];

void init() {
	inv[1] = 1;
	for (int i = 2; i < MX; ++i) {
		inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
	}
	fact[0] = ifact[0] = 1;
	for (int i = 1; i < MX; ++i) {
		fact[i] = fact[i-1] * i % MOD;
		ifact[i] = ifact[i-1] * inv[i] % MOD;
	}
}

ll comb(int n, int r) {
	if (n < 0 || r < 0 || r > n) return 0;
	return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
}

inline void add(ll &x, ll y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

ll powmod(ll x, ll k) {
	ll res = 1;
	for (; k; k /= 2, x = x * x % MOD) {
		if (k & 1) {
			res = res * x % MOD;
		}
	}
	return res;
}

int main() {
	int n, k;
	cin >> n >> k;
	init();

	V<int> h(n);
	rep(i, n) cin >> h[i];

	int same = 0, dif = 0;
	rep(i, n) {
		if ((h[i] == (h[(i+1) % n]))) {
			++same;
		} else {
			++dif;
		}
	}

	if (k == 1) {
		puts("0");
		return 0;
	}

	ll all = powmod(k, n);
	ll eq = 0;
	for (int i = 0; i * 2 <= dif; ++i) {
		ll way = comb(dif, i) * comb(dif - i, i) % MOD * powmod(k - 2, dif - i * 2) % MOD;
		add(eq, way);
	}

	eq = eq * powmod(k, same) % MOD;
	ll ans = (all - eq + MOD) % MOD;
	ans = (MOD + 1) / 2 * ans % MOD;
	cout << ans << endl;

	return 0;
}