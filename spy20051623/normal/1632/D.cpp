#include <bits/stdc++.h>

using namespace std;

int lg[200005];
int st[200005][20];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	for (int i = 1; i < 200005; ++i) {
		lg[i] = (int) log2(i);
	}
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> st[i][0];
	for (int i = 1; 1 << i <= n; ++i) {
		for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
			st[j][i] = __gcd(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
		}
	}
	int last = 0, cnt = 0;
	for (int i = 1; i <= n; ++i) {
		int l = last + 1, r = i, ans = 0;
		while (l <= r) {
			int m = (l + r) >> 1;
			int len = i - m + 1;
			int g = __gcd(st[m][lg[len]], st[i - (1 << lg[len]) + 1][lg[len]]);
			if (g == len) {
				ans = 1;
				break;
			}
			if (g > len) r = m - 1;
			else l = m + 1;
		}
		if (ans) ++cnt, last = i;
		cout << cnt << ' ';
	}
	return 0;
}