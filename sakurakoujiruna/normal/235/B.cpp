#include <bits/stdc++.h>
using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	cout << fixed << setprecision(9);
	int n; cin >> n;
	double ans = 0, e = 0;
	for(int i = 0; i < n; i ++) {
		double p; cin >> p;
		ans += p * (1 + 2 * e);
		e = p * (1 + e);
	}
	cout << ans << '\n';
	return 0;
}