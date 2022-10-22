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

const int maxn = 300010;

int a[maxn][8];

int main() {
	int n, m; cin >> n >> m;
	rep(i, n) {
		rep(j, m) {
			cin >> a[i][j];
		}
	}

	auto can = [&](int x) {
		VV<int> cnt(1 << m);
		rep(i, n) {
			int t = 0;
			rep(j, m) {
				t *= 2;
				if (a[i][j] >= x) t += 1;
			}
			cnt[t].pb(i);
		}

		rep(i, 1 << m) if (cnt[i].size()) {
			int a = cnt[i].back();
			rep(j, 1 << m) if (cnt[j].size()) {
				if ((i | j) == (1 << m) - 1) {
					pii res = mp(a, cnt[j].back());
					return res;
				}
			}
		}
		return mp(-1, -1);
	};

	int lo = 0, hi = TEN(9) + 1;
	while (hi - lo > 1) {
		int m = (lo + hi) / 2;
		if (can(m).fi != -1) lo = m;
		else hi = m;
	}
	auto res = can(lo);
	cout << res.fi + 1 << " " << res.se + 1 << endl;
	return 0;
}