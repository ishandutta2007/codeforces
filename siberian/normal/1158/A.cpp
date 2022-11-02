#include <bits/stdc++.h>

using namespace std;
#define int long long
int n, m;
vector <int> a;
vector <int> b;
void read() {
	cin >> n >> m;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	b.resize(m);
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	sort(b.begin(), b.end());
	if (a[n - 1] > b[0]) {
		cout << -1 << endl;
		exit(0);
	}
}

int ans;
void run() {
	ans = 0;
	for (int i = 0; i < n; i++)
		ans += a[i] * m;
	for (int i = 1; i < m; i++)
		ans += b[i] - a[n - 1];
	if (b[0] != a[n - 1]) {
		if (n == 1) {
			cout << -1 << endl;
			exit(0);
		}
		if (m == 1 && a[n - 2] != b[0]) {
			cout << -1 << endl;
			exit(0);
		}
		ans += b[0] - a[n - 2];
	}
}

void write() {
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}