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
#define dump(x) cout << #x << " = " << (x) << endl
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
	int n, m, ta, tb, k;
	cin >> n >> m >> ta >> tb >> k;
	V<int> a(n), b(m);
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> b[i];

	if (min(n, m) <= k) {
		puts("-1");
		return 0;
	}

	const ll INF = TEN(18);
	ll ans = -1;

	for (int i = 0; i <= k; ++i) {
		auto it = lower_bound(ALL(b), a[i] + ta);

		if (it == b.end()) {
			puts("-1");
			return 0;
		}

		int j = it - b.begin() + (k - i);
		if (j < m) {
			chmax(ans, b[j] + tb);
		} else {
			puts("-1");
			return 0;
		}
	}
	cout << ans << endl;

	return 0;
}