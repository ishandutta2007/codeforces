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

const ll MOD = TEN(9) + 7;
const int maxn = 100010;

ll a[maxn];
V<int> g[maxn];
ll ans;

void dfs(int v, int p, map<ll, int> T) {
	map<ll, int> U;
	U[a[v]] = 1;
	for (auto p : T) {
		U[__gcd(a[v], p.fi)] += p.se;
	}

	for (auto p : U) {
		ans += p.fi * p.se;
		ans %= MOD;
	}
	for (int to : g[v]) if (to != p) {
		dfs(to, v, U);
	}
}

int main() {
	int n; cin >> n;
	rep(i, n) cin >> a[i];
	rep(i, n-1) {
		int x, y;
		cin >> x >> y;
		--x; --y;
		g[x].pb(y); g[y].pb(x);
	}
	map<ll, int> T;
	dfs(0, -1, T);
	cout << ans << endl;
	return 0;
}