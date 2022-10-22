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

class unionfind {
public:
	vector<int> par, rank;

	void init(int n) {
		par.resize(n);
		rank.resize(n);

		for (int i = 0; i < n; i++) {
			par[i] = i;
			rank[i] = 0;
		}
	}

	int find(int x) {
		if (par[x] == x) return x;
		else return par[x] = find(par[x]);
	}

	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return ;

		if (rank[x] < rank[y]) par[x] = y;
		else {
			par[y] = x;
			if (rank[x] == rank[y]) ++rank[x];
		}
	}

	bool same(int x, int y) { return (find(x) == find(y)); }
} uf;

const ll MOD = TEN(9) + 7;

const int maxn = 500010;

ll p2[maxn];
ll c[maxn];

bool dfs(int v, int a, const vector<vi>& g, vi& col) {
	col[v] = a;
	for (int to : g[v]) {
		if (col[to] == -1) {
			if (!dfs(to, a ^ 1, g, col)) {
				return false;
			}
		} else {
			if (col[to] != (a ^ 1)) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	p2[0] = 1;
	for (int i = 1; i < maxn; ++i) {
		p2[i] = p2[i-1] * 2 % MOD;
	}

	int n, m, k; cin >> n >> m >> k;
	rep(i, n) cin >> c[i];

	vector<pair<ll, pii>> edges(m);

	rep(i, m) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		edges[i] = mp(c[a] ^ c[b], mp(a, b));
	}

	sort(ALL(edges));

	uf.init(n);

	ll ng = 0;
	int cmp = n;

	int i = 0;
	for (; i < edges.size(); ) {
		int j = i;
		while (j < edges.size() && edges[j].fi == edges[i].fi) ++j;

		vi em;
		for (int k = i; k < j; ++k) {
			int a, b;
			tie(a, b) = edges[k].se;

			em.pb(a);
			em.pb(b);
			if (!uf.same(a, b)) {
				uf.unite(a, b);
				--cmp;
			}
		}

		ll x = edges[i].fi;
		ll dec = 0;

		dec = p2[n] - p2[cmp];
		if (dec < 0) dec += MOD;

		for (int v : em) {
			uf.par[v] = v;
			uf.rank[v] = 0;
		}
		cmp = n;

		ng += dec;
		if (ng >= MOD) ng -= MOD;

		i = j;
	}

	ll ans = (1ll << k) % MOD * p2[n] % MOD;
	ans -= ng;
	if (ans < 0) ans += MOD;
	cout << ans << endl;

	return 0;
}