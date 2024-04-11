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

int main() {
	int n, U; cin >> n >> U;
	V<int> E(n); rep(i, n) cin >> E[i];

	bool ok = 0;
	rep(i, n) {
		int x = upper_bound(ALL(E), E[i] + U) - E.begin();
		if (x - i >= 3) {
			ok = 1;
		}
	}
	if (!ok) {
		puts("-1");
		return 0;
	}

	double mx = 0.0;

	rep(i, n-2) {
		int x = upper_bound(ALL(E), E[i] + U) - E.begin();
		if (x > i+2) {
			--x;
			chmax(mx, (double)(E[x] - E[i+1]) / (E[x] - E[i]));
		}
	}

	printf("%.10f\n", mx);
	return 0;
}