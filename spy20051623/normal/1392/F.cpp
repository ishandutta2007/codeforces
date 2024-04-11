#include <bits/stdc++.h>

using namespace std;

long long a[1000005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	sum -= 1ll * (n - 1) * n / 2;
	long long m = sum % n, h = sum / n;
	for (int i = 0; i < n; ++i) {
		a[i] = h + i + (i < m);
	}
	for (int i = 0; i < n; ++i) {
		cout << a[i] << ' ';
	}
	return 0;
}