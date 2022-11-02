#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) (x).begin(),(x).end()
#define int ll

#define pt pair<int, int>
#define x first
#define y second

ld dist(pt a, pt b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void solve() {
	int r;
	cin >> r;
	pt a, b;
	cin >> a.x >> a.y >> b.x >> b.y;
	ld d = dist(a, b);
	int tl = -1, tr = 1e9;
	while (tl < tr - 1) {
		int mid = (tl + tr) / 2;
		if (r * 2 * mid >= d)
			tr = mid;
		else
			tl = mid; 
	}
	cout << tr;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20);
	int t;
	//cin >> t;
	t = 1;
	while (t--)
		solve();
	return 0;
}