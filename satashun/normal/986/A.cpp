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

const int maxn = 100010;
const int maxk = 110;
const ll INF = 1e9;

int n, m, s, k;
vector<int> g[maxn];
int a[maxn];
int d[maxk][maxn];
using Data = pii;

priority_queue<Data, vector<Data>, greater<Data>> que[110];

int main() {
	cin >> n >> m >> k >> s;
	rep(i, k) rep(j, n) d[i][j] = INF;

	rep(i, n) {
		cin >> a[i];
		--a[i];
		d[a[i]][i] = 0;
		que[a[i]].push(mp(0ll, i));
	}

	rep(i, m) {
		int a, b; cin >> a >> b;
		--a; --b;
		g[a].pb(b); g[b].pb(a);
	}

	rep(c, k) {
		while (!que[c].empty()) {
			auto p = que[c].top(); que[c].pop();
			int v = p.se;
			if (d[c][v] < p.fi) continue;
			for (int to : g[v]) {
				if (d[c][to] > d[c][v] + 1) {
					d[c][to] = d[c][v] + 1;
					que[c].push(mp(d[c][to], to));
				}
			}
		}
	}

	rep(i, n) {
		vi vec;
		rep(j, k) vec.pb(d[j][i]);
		sort(ALL(vec));
		int ans = 0;
		rep(j, s) ans += vec[j];
		printf("%d%c", ans, i == n-1 ? '\n' : ' ');
	}

	return 0;
}