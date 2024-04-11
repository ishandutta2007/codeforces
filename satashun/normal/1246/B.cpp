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
	int n, k; cin >> n >> k;
	V<int> a(n);
	ll ans = 0;
	map<V<pii>, int> T;

	rep(i, n) {
		cin >> a[i];
		int x = a[i];

		V<pii> vec;

		for (int j = 2; j * j <= x; ++j) {
			int t = 0;
			while (x % j == 0) {
				x /= j;
				++t;
			}
			t %= k;
			if (t) {
				vec.eb(j, t);
			}
		}
		if (x != 1 && k != 1) {
			vec.eb(x, 1);
		}

		V<pii> to = vec;
		for (auto &p : to) {
			p.se = k - p.se;
		}

		if (T.count(to)) {
			ans += T[to];
		}

		++T[vec];
	}
	cout << ans << endl;
	return 0;
}