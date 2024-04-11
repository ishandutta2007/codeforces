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

int a[4][60];

int main() {
	int n, k;
	cin >> n >> k;

	rep(i, 4) {
		rep(j, n) cin >> a[i][j];
	}

	V<pair<int,pii>> ans;

	if (k == n * 2) {
		bool ok = 0;
		rep(i, n) {
			if (a[1][i] == a[0][i]) {
				ok = 1;
				ans.eb(a[0][i], mp(0, i));
				a[1][i] = 0;
				break;
			}
			if (a[2][i] == a[3][i]) {
				ok = 1;
				ans.eb(a[3][i], mp(3, i));
				a[2][i] = 0;
				break;				
			}
		}
		if (!ok) {
			puts("-1");
			return 0;
		}
	}

	while (true) {
		bool ex = 0;
		rep(i, n) {
			if (a[1][i] > 0 || a[2][i] > 0) {
				ex = 1;
			}
			if (a[1][i] > 0 && a[1][i] == a[0][i]) {
				ans.eb(a[0][i], mp(0, i));
				a[1][i] = 0;
			}
			if (a[2][i] == a[3][i] && a[2][i] > 0) {
				ans.eb(a[3][i], mp(3, i));
				a[2][i] = 0;			
			}
		}	
		if (!ex) break;

		V<pii> val;
		rep(i, n) val.eb(1, i);
		rep(i, n) val.eb(2, n-1-i);
		int now = -1;
		rep(i, n * 2) {
			int p, q; tie(p, q) = val[i];
			if (a[p][q] == 0) now = i;
		}
		dump(val);

		rep(i, val.size()-1) {
			int nx = now + 1;
			if (nx == val.size()) {
				nx = 0;
			}

			int p, q; tie(p, q) = val[nx];
			if (a[p][q] != 0) {
				ans.eb(a[p][q], val[now]);
			}
			int x, y;
			tie(x, y) = val[now];
			a[x][y] = a[p][q];
			a[p][q] = 0;
			now = nx;
		}
		dump(ans);
	}

	cout << ans.size() << endl;
	for (auto t : ans) {
		cout << t.fi << " " << t.se.fi + 1 << " " << t.se.se + 1 << endl;
	}

	return 0;
}