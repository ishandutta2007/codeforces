#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
	int p, f;
	cin >> p >> f;
	int cs, cw;
	cin >> cs >> cw;
	int s, w;
	cin >> s >> w;
	if (s > w) swap(s, w), swap(cs, cw);
	int x = (p + f) / s;
	if (x > cs) x = cs;
	int y = (p + f - x * s) / w;
	if (y > cw) y = cw;
	for (int i = 0; i <= x; ++i) {
		if (i * s > p) break;
		int x1 = i, x2 = x - x1;
		int y1 = min((p - s * i) / w, y), y2 = y - y1;
		if (s * x1 + w * y1 <= p && s * x2 + w * y2 <= f) {
			cout << x + y << '\n';
			return;
		}
	}
	cout << x + y - 1 << '\n';
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}