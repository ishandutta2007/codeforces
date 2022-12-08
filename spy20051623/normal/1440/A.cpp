#include <bits/stdc++.h>

using namespace std;

char s[1005];

void solve() {
	int n, x, y, h;
	scanf("%d%d%d%d", &n, &x, &y, &h);
	if (x < y) y = min(y, x + h);
	if (x > y) x = min(x, y + h);
	scanf("%s", s);
	int c[2] = {0, 0};
	for (int i = 0; i < n; ++i) ++c[s[i] - '0'];
	printf("%d\n", c[0] * x + c[1] * y);
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