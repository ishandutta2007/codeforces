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

template<class T, class U> bool chmax(T& t, const U& u) { if (t < u) { t = u; return 1; } return 0; }
template<class T, class U> bool chmin(T& t, const U& u) { if (t > u) { t = u; return 1; } return 0; }

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
	vector<int> par, rank;

public:
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
};

string s[60];

int main() {
	int n, m; cin >> n >> m;
	rep(i, n) cin >> s[i];

	V<pii> es;
	unionfind uf;
	uf.init(n + m);

	rep(i, n) {
		rep(j, m) {
			if (s[i][j] == '#') {
				uf.unite(i, j + n);
				es.eb(i, j + n);
			}
		}
	}

	bool ok = 1;
	V<int> vis(n + m);
	rep(i, n) {
		if (vis[uf.find(i)]) {
			continue;
		}
		int c0 = 0, c1 = 0;
		rep(j, n) if (uf.same(i, j)) ++c0;
		rep(j, m) if (uf.same(i, j + n)) ++c1;
		int num = 0;
		for (auto e : es) {
			if (uf.same(e.fi, i)) {
				++num;
			}
		}
		//cerr << c0 << " " << c1 << " " << num << endl;
		if (num != c0 * c1) {
			ok = 0;
			break;
		}
		vis[uf.find(i)] = 1;
	}
	puts(ok ? "Yes" : "No");
	return 0;
}