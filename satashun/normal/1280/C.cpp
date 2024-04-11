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

const int maxn = 200010;

V<pii> g[maxn];
int sz[maxn];
ll G, B;
int n;

void dfs1(int v, int p) {
	sz[v] = 1;
	for (auto e : g[v]) {
		if (e.fi != p) {
			dfs1(e.fi, v);
			if (sz[e.fi] & 1) {
				G += e.se;
			}
			B += min(sz[e.fi], n-sz[e.fi]) * (ll)e.se;
			sz[v] += sz[e.fi];
		}
	}
}

int main() {
	int TC; cin >> TC;

	while (TC--) {
		int k; cin >> k;
		n = k * 2;
		rep(i, n) g[i].clear();
		rep(i, n-1) {
			int a, b, t;
			cin >> a >> b >> t;
			--a; --b;
			g[a].eb(b, t);
			g[b].eb(a, t);
		}

		G = B = 0;
		dfs1(0, -1);

		printf("%lld %lld\n", G, B);
	}

	return 0;
}