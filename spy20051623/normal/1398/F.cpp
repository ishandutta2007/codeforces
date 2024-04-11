#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 5;
int a[2][N], b[2][N], c[2][N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	memset(b, 63, sizeof b);
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '?') {
			a[0][i + 1] = a[1][i + 1] = 1;
		} else {
			a[s[i] - '0'][i + 1] = 1;
			a[s[i] - '0' ^ 1][i + 1] = 0;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 2; ++j) {
			if (!a[j][i]) b[j][i] = 0;
			else if (a[j][i - 1]) b[j][i] = b[j][i - 1];
			else b[j][i] = i;
		}
	}
	for (int i = n; i >= 1; --i) {
		for (int j = 0; j < 2; ++j) {
			if (!a[j][i]) c[j][i] = 0;
			else if (a[j][i + 1]) c[j][i] = c[j][i + 1];
			else c[j][i] = i;
		}
	}
	for (int i = 1; i <= n; ++i) {
		int p = 1, q = 0, ans = 0;
		while (p <= n) {
			int t[2] = {1000000000, 1000000000};
			for (int j = 0; j < 2; ++j) {
				if (!b[j][p]) continue;
				int x = max(q + 1, b[j][p]);
				if (c[j][p] - x + 1 >= i) t[j] = x;
			}
			if (t[0] > n && t[1] > n) p += i;
			else ++ans, q = min(t[0], t[1]) + i - 1, p = q + 1;
		}
		cout << ans << ' ';
	}
	return 0;
}