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

#define LOCAL
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

using pll = pair<ll, ll>;
ll LIM = TEN(16) * 2 + 1000;

int main() {
	ll xg, yg, ax, ay, bx, by;
	cin >> xg >> yg >> ax >> ay >> bx >> by;
	ll sx, sy, t;
	cin >> sx >> sy >> t;

	V<pll> vec;
	vec.eb(xg, yg);
	while (true) {
		ll nx = vec.back().fi * ax + bx;
		ll ny = vec.back().se * ay + by;
		if (nx <= LIM && ny <= LIM) {
			vec.eb(nx, ny);
		} else {
			break;
		}
	}

	dump(vec);

	int ans = 0;
	rep(s, vec.size()) {
		ll cur = abs(sx - vec[s].fi) + abs(sy - vec[s].se);
		if (cur > t) continue;
		ll px = vec[s].fi, py = vec[s].se;

		for (int l = 0; l <= s; ++l) {
			for (int r = s; r < vec.size(); ++r) {
				ll need = min(abs(px - vec[l].fi) + abs(py - vec[l].se), abs(px - vec[r].fi) + abs(py - vec[r].se)); 
				need += abs(vec[r].fi - vec[l].fi) + abs(vec[r].se - vec[l].se) + cur;
				if (need <= t) {
					chmax(ans, r - l + 1);
				}
			}
		} 
	}
	cout << ans << endl;

	return 0;
}