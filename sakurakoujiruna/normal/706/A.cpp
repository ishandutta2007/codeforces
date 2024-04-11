#include <bits/stdc++.h>
using namespace std;

int main() {
	cout << fixed << setprecision(9);
	ios :: sync_with_stdio(false);
	double a, b; cin >> a >> b;
	int n; cin >> n;
	double ans = 1e3;
	while(n --) {
		double x, y, v; cin >> x >> y >> v;
		a -= x; b -= y;
		ans = min(ans, sqrt(a * a + b * b) / v);
		a += x; b += y;
	}
	cout << ans << '\n';
	return 0;
}