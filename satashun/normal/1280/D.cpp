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
#define dump(x) cerr << #x << " = " << (x) << endl
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

const int maxn = 3010;
const ll inf = -TEN(18);
const pair<int, ll> S = mp(-1, inf);

V<int> g[maxn];
int sz[maxn];
ll a[maxn];
pair<int, ll> dp[maxn][maxn], sub[2][maxn][maxn];
int n, m;

void dfs(int v, int p) {
	sz[v] = 1;
	rep(k, 2) rep(j, n+1) sub[k][v][j] = S;
	sub[0][v][1] = mp(0, a[v]);

	int c = 0, f = 1;

	for (int to : g[v]) if (to != p) {
		dfs(to, v);

		rep(j, sz[v] + sz[to] + 1) {
			sub[f][v][j] = S;
		}

		for (int j = 1; j <= sz[v]; ++j) if (sub[c][v][j] != S) {
			for (int k = 1; k <= sz[to]; ++k) if (dp[to][k] != S) {
				//cut
				auto r = dp[to][k];
				if (r.se > 0) r.fi++;
				chmax(sub[f][v][j+k], mp(r.fi + sub[c][v][j].fi, sub[c][v][j].se));
				//connect
				chmax(sub[f][v][j+k-1], mp(sub[c][v][j].fi+dp[to][k].fi, sub[c][v][j].se+dp[to][k].se));
			}
		}
		sz[v] += sz[to];
		swap(c, f);
	}
	rep(j, n+1) dp[v][j] = sub[c][v][j];
}

int main() {
	int TC; cin >> TC;
	while (TC--) {
		cin >> n >> m;
		rep(i, n) {
			a[i] = 0;
			g[i].clear();
		}
		rep(i, n) {
			int x; cin >> x;
			a[i] -= x;
		}
		rep(i, n) {
			int x; cin >> x;
			a[i] += x;
		}

		rep(i, n-1) {
			int a, b;
			cin >> a >> b;
			--a; --b;
			g[a].pb(b); g[b].pb(a);
		}

		dfs(0, -1);
		auto r = dp[0][m];

		if (r.se > 0) ++r.fi;
		printf("%d\n", r.fi);
	}
	return 0;
}