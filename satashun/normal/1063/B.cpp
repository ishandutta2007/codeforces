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

const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,1,-1};
const int INF = TEN(9) + 10;
const pii inf = mp(INF, INF);

string s[2010];

pii d[2010][2010];

int main() {
	int n, m; cin >> n >> m;
	int r, c; cin >> r >> c;
	--r; --c;
	int x, y; cin >> x >> y;

	rep(i, n) cin >> s[i];

	rep(i, n) rep(j, m) {
		d[i][j] = inf;
	}

	using Data = pair<pii, pii>;
	priority_queue<Data, vector<Data>, greater<Data>> que;

	d[r][c] = mp(0, 0);
	que.push(mp(d[r][c], mp(r, c)));

	while (!que.empty()) {
		auto t = que.top(); que.pop();
		int p, q; tie(p, q) = t.se;
		if (d[p][q] < t.fi) continue;

		rep(dir, 4) {
			int np = p + dx[dir], nq = q + dy[dir];
			if (np >= 0 && np < n && nq >= 0 && nq < m && s[np][nq] != '*') {
				pii nx = d[p][q];
				if (dir == 3) {
					++nx.fi;
				} else if (dir == 2) {
					++nx.se;
				}
				if (d[np][nq] > nx) {
					d[np][nq] = nx;
					que.push(mp(d[np][nq], mp(np, nq)));
				}
			}
		}
	}

	int ans = 0;
	rep(i, n) rep(j, m) {
		if (d[i][j].fi <= x && d[i][j].se <= y) {
			++ans;
		}
	}
	cout << ans << endl;

	return 0;
}