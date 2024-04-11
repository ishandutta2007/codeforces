#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

const int MAXN = 1e6  + 10;

struct point{
	ld x, y;
	point() {}
	point(ld _x, ld _y) {
		x = _x, y = _y;
	}
};

point operator-(const point & a, const point & b) {
	return point(a.x - b.x, a.y - b.y);
}

ld dist(point a) {
	return sqrt(a.x * a.x + a.y * a.y);
}

ld dist(point a, point b) {
	return dist(a - b);
}

void solve() {
	point a, b, t;
	cin >> a.x >> a.y >> b.x >> b.y >> t.x >> t.y;
	int n;
	cin >> n;
	vector<point> have(n);
	for (auto &i : have) cin >> i.x >> i.y;
	ld ans = 0;
	for (int i = 0; i < n; i++) {
		ans += dist(t, have[i]) * 2;
	}

	vector<pair<ld, int>> haveA, haveB;
	for (int i = 0; i < n; i++) {
		haveA.push_back({dist(a, have[i]) - dist(have[i], t), i});
		haveB.push_back({dist(b, have[i]) - dist(have[i], t), i});
	}
	ld fans = ans;
	ans += dist(a, t) + dist(b, t);
	sort(all(haveA));
	while (haveA.size() > 100) haveA.pop_back();
	sort(all(haveB));
	while (haveB.size() > 100) haveB.pop_back();
	
	for (auto i : haveA) {
		chkmin(ans, fans + i.first);
	}

	for (auto i : haveB) {
		chkmin(ans, fans + i.first);
	}

	for (auto i : haveA) {
		for (auto j : haveB) {
			if (i.second == j.second) continue;
			chkmin(ans, fans + i.first + j.first);
		}
	}

	cout.precision(20);
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}