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

#ifdef LOCAL
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else 
#define dump(x) true
#endif

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

typedef unsigned int uint;


const int maxn = 3010;

V<int> g[maxn];
int id[maxn][maxn];
uint M[6010][6010];
bool vis[6010][6010];

int sz[maxn];

void dfs(int v, int p) {
	sz[v] = 1;

	for (int to : g[v]) if (to != p) {
		dfs(to, v);
		sz[v] += sz[to];
	}
}

uint solve(int v1, int p1, int v2, int p2) {
	int e1 = id[v1][p1];
	int e2 = id[v2][p2];
	if (vis[e1][e2]) return M[e1][e2];
	vis[e1][e2] = 1;

	uint res = 0;

	for (int to : g[v1]) if (to != p1) {
		chmax(res, solve(to, v1, v2, p2));
	}

	for (int to : g[v2]) if (to != p2) {
		chmax(res, solve(v1, p1, to, v2));
	}
	res += sz[v1] * sz[v2];
	return M[e1][e2] = res;
}

int main() {
	int n; cin >> n;

	V<pii> es;

	int now = 0;

	rep(i, n-1) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].pb(b);
		g[b].pb(a);
		id[a][b] = now++;
		id[b][a] = now++;
		es.eb(a, b);
	}

	ll ans = 0;

	for (auto e : es) {
		int a = e.fi, b = e.se;
		dfs(a, b);
		dfs(b, a);
		ll tmp = solve(a, b, b, a);
		dump(tmp);
		chmax(ans, tmp);
	}

	cout << ans << endl;

	return 0;
}