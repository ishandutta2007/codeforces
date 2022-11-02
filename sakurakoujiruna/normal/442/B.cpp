#include <bits/stdc++.h>
using namespace std;

const int N = 111;
double p[N];

int main() {
	ios :: sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> p[i];
	sort(p, p + n, greater<double>());
	double ans = 0, p1 = 0;
	double p0 = 1;
	for(int i = 0; i < n; i ++) {
		p1 = p[i] * p0 + (1 - p[i]) * p1;
		p0 = (1 - p[i]) * p0;
		ans = max(ans, p1);
	}
	cout << fixed << setprecision(12) << ans << '\n';
	return 0;
}