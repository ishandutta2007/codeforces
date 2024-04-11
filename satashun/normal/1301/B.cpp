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

const int INF = TEN(9);

int main() {
	int TC; cin >> TC;
	while (TC--) {
		int n; cin >> n;
		V<int> a(n); rep(i, n) cin >> a[i];

		auto ok = [&](int d) {
			int mini = -INF, maxi = INF;

			rep(i, n) {
				if (a[i] == -1) {
					if (i > 0 && a[i-1] != -1) {
						int l = a[i-1] - d, r = a[i-1] + d;
						chmax(mini, l);
						chmin(maxi, r);
					}
					if (i+1<n && a[i+1] != -1) {
						int l = a[i+1] - d, r = a[i+1] + d;
						chmax(mini, l);
						chmin(maxi, r);						
					}
				}
			}
			if (maxi == INF) {
				return 0;
			}
			if (mini > maxi) {
				return -1;
			}
			return maxi;
		};

		int lo = 0, hi = TEN(9);
		{
			auto res = ok(0);
			if (res != -1) {
				hi = 0;
			}
		}
		while (hi - lo > 1) {
			int m = (lo + hi) / 2;
			auto res = ok(m);
			if (res != -1) {
				hi = m;
			} else {
				lo = m;
			}
		}

		rep(i,n-1) {
			if (a[i] != -1 && a[i+1] != -1) {
				chmax(hi, abs(a[i+1]-a[i]));
			}
		}

		int res = ok(hi);
		printf("%d %d\n", hi, res);
	}
	return 0;
}