#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long W, H, x1, y1, x2, y2, w, h;
	scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &W, &H, &x1, &y1, &x2, &y2, &w, &h);
	long long dx = x2 - x1, dy = y2 - y1;
	if (dx + w > W && dy + h > H) {
		printf("-1\n");
		return;
	}
	long long mx = dx + w > W ? 1e18 : min(max(0ll, w - x1), max(0ll, w - (W - x2)));
	long long my = dy + h > H ? 1e18 : min(max(0ll, h - y1), max(0ll, h - (H - y2)));
	double dis = min(mx, my);
	printf("%.9lf\n", dis);
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}