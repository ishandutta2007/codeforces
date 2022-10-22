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

const int maxn = 300010;
const int INF = TEN(9);

int close[maxn][20];

int main() {
	int n, q; scanf("%d %d", &n, &q);
	V<int> a(n);
	rep(i, n) scanf("%d", &a[i]);

	rep(i, n) rep(j, 20) {
		close[i][j] = INF;
	}

	V<int> cur(20, INF);

	for (int i = n-1; i >= 0; --i) {
		rep(j, 20) if (a[i] >> j & 1) {
			if (cur[j] != INF) {
				rep(k, 20) {
					chmin(close[i][k], close[cur[j]][k]);
				}
			}
			cur[j] = i;
			close[i][j] = i;
		}
	}

	while (q--) {
		int x, y;
		scanf("%d %d", &x, &y);
		--x; --y;
		bool ok = false;
		rep(j, 20) {
			if ((a[y] >> j & 1) and close[x][j] <= y) {
				ok = true;
			}
		}
		puts(ok ? "Shi" : "Fou");
	}
	return 0;
}