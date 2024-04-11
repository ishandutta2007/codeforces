#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n, k;
vector<int> a[4];

void read() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int t, f1, f2;
		cin >> t >> f1 >> f2;
		a[f1 * 2 + f2].push_back(t);
	}
	if (min(a[1].size(), a[2].size()) + a[3].size() < k) {
		cout << -1 << endl;
		exit(0);
	}
}

int ans;

void run() {
	ans = 2e9 + 228;
	for (int i = 1; i <= 3; i++) {
		sort(all(a[i]));
		for (int j = 1; j < (int)a[i].size(); j++) {
			a[i][j] += a[i][j - 1];
		}
	}
	for (int i = 0; i <= min(k, (int)a[3].size()); i++) {
		if (k - i > min(a[1].size(), a[2].size())) continue;
		int fans = 0;
		if (i > 0) fans += a[3][i - 1];
		if (k - i > 0) {
			fans += a[1][k - i - 1];
			fans += a[2][k - i - 1];
		}
		chkmin(ans, fans);
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