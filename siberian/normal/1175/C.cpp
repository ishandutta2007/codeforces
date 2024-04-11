#include <bits/stdc++.h>

using namespace std;
#define int long long

void read() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &i : a)
		cin >> i;

	int l = 1e18;
	int ans = 0;
	
	for (int i = 0; i + k < n; i++) {
		if ((a[i + k] - a[i] + 1) / 2 < l) {
			l = (a[i + k] - a[i] + 1) / 2;
			ans = a[i] + l;
		}
	}
	cout << ans <<"\n";
}

void run() {

}

void write() {

}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		read();
	run();
	write();
	return 0;
}