#include <bits/stdc++.h>

using namespace std;

int a[5005];
long long b[5005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	long long ans = 1e18;
	for (int i = 0; i < n; ++i) {
		long long sum = 0;
		b[i] = 0;
		for (int j = i - 1; j >= 0; --j) {
			b[j] = b[j + 1] / a[j] + 1;
			sum += b[j];
			b[j] *= a[j];
		}
		for (int j = i + 1; j < n; ++j) {
			b[j] = b[j - 1] / a[j] + 1;
			sum += b[j];
			b[j] *= a[j];
		}
		ans = min(ans, sum);
	}
	cout << ans << '\n';
	return 0;
}