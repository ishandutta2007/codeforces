#include <bits/stdc++.h>
using namespace std;

long long d, k, a, b, t, ans;

long long calc(long long x) {
	return x * ((a - b) * k + t) + d * b - t;
}

int main() {
//	freopen("d.in", "r", stdin);
	cin >> d >> k >> a >> b >> t;
	ans = min(d * b, d * a + t * ((d + k - 1) / k - 1));
	if (d >= k) {
		ans = min(ans, calc(1));
		ans = min(ans, calc(d / k));
	}
	cout << ans << endl;
	return 0;
}