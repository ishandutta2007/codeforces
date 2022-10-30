///	Choe Kwang B

#include <bits/stdc++.h>
using namespace std;

int t, n, m, stx, sty, enx, eny;

int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d %d %d %d %d", &n, &m, &stx, &sty, &enx, &eny);
		int dx = abs(stx - enx), dy = abs(sty - eny);
		long long ans = 0;
		ans = 2ll * (n - dx) * (m - dy);
		int x = max(n - 2 * dx, 0), y = max(m - 2 * dy, 0);
		ans -= 1ll * x * y;
		ans = 1ll * n * m - ans;
		cout << ans << endl;
	}
	return 0;
}