#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	double br = 100000.0;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		br = min(br, (a+0.0)/(b+0.0));
	}
	double ans = br*m;
	cout << fixed << setprecision(10);
	cout << ans << endl;
	cin >> n;
}