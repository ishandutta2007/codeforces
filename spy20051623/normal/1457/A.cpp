#include <bits/stdc++.h>

using namespace std;

long long dis(int x, int y, int r, int c) {
	return abs(x - c) + abs(y - r);
}

void solve() {
	int n, m, r, c;
	scanf("%d%d%d%d", &n, &m, &r, &c);
	long long res = 0;
	res = max(res, dis(1, 1, r, c));
	res = max(res, dis(1, n, r, c));
	res = max(res, dis(m, 1, r, c));
	res = max(res, dis(m, n, r, c));
	printf("%lld\n", res);
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