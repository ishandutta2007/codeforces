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
const int inf = -TEN(9);

int main() {
	int TC; cin >> TC;
	while (TC--) {
		int n, m, k; cin >> n >> m >> k;
		V<int> a(n);
		rep(i, n) cin >> a[i];
		int ans = inf;

		chmin(k, m-1);
		for (int i = 0; i <= k; ++i) { //front
			int rem = m-1-k;
			int ch = INF;
			
			for (int p = i; p <= i + rem; ++p) {
				int q = m-1-p;
				int mx = max(a[p], a[n-1-q]);
				chmin(ch, mx);
			}
			chmax(ans, ch);
		}
		cout << ans << endl;
	}
	return 0;
}