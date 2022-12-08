#include <bits/stdc++.h>

using namespace std;

void solve() {
	int x, y, a, b;
	scanf("%d%d%d%d", &x, &y, &a, &b);
	if (x > y)swap(x, y);
	if (a > b)swap(a, b);
	int ans = 0;
	int t;
	if (a != b) {
		t = (y - x) / (b - a);
		t = min(t, x / a);
		t = min(t, y / b);
		ans += t;
		x -= a * t;
		y -= b * t;
	}
	t = x / (a + b);
	ans += t + t;
	x -= t * (a + b);
	y -= t * (a + b);
	if (x >= a && y >= b)++ans;
	printf("%d\n", ans);
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