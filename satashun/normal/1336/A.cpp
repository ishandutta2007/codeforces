#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
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

#ifdef LOCAL
void debug_out() { cerr << endl; }
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << H;
	debug_out(T...);
}
#define debug(...) cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

const int maxn = 200010;
V<int> g[maxn];
int dep[maxn];
int sz[maxn];

void dfs(int v, int p, int d) {
	dep[v] = d;
	sz[v] = 1;

	for (int to : g[v]) {
		if (to != p) {
			dfs(to, v, d + 1);
			sz[v] += sz[to];
		}
	}
}

bool t[maxn];

ll ans;

ll solve(int v, int p) {
	ll res = 0;
	if (!t[v]) {
		res = 1;
	}
	for (int to : g[v]) {
		if (to != p) {
			res += solve(to, v);
		}
	}	
	if (t[v]) {
		ans += res;
	}
	return res;
}

int main() {
	int n, k; cin >> n >> k;
	rep(i, n-1) {
		int a, b;
		cin >> a >> b; --a; --b;
		g[b].pb(a); g[a].pb(b);
	}

	dfs(0, -1, 0);

	V<pii> vec(n);
	rep(i, n) {
		vec[i] = mp(dep[i] - sz[i], i);
	}
	sort(ALL(vec));

	rep(i, n-k) {
		t[vec[i].se] = true;
	}

	rep(i, n) {
		debug(i, (int)t[i]);
	}
	solve(0, -1);
	cout << ans << endl;

	return 0;
}