#include <bits/stdc++.h>

using namespace std;
const int N = 1505;
vector<int> g1[N], g2[N];

long long c2(int x) {
	if (x <= 0) return 0;
	return 1ll * x * (x + 1) / 2;
}

int fd1(int x, int y) {
	if (g1[x][0] == y) return g1[x][1];
	else return g1[x][0];
}

int fd2(int x, int y) {
	if (g2[x][0] == y) return g2[x][1];
	else return g2[x][0];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 0; i < n + n; ++i) {
		int x, y;
		cin >> x >> y;
		g1[x].push_back(y - n);
		g2[y - n].push_back(x);
	}
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (g1[i][0] > g1[i][1]) swap(g1[i][0], g1[i][1]);
		ans += (c2(n) - c2(g1[i][0] - 1) - c2(g1[i][1] - g1[i][0] - 1) - c2(n - g1[i][1])) * i * (n - i + 1);
	}
	for (int i = 1; i <= n; ++i) {
		int k = g1[i][0], j = fd2(k, i);
		int mn1 = min(i, j), mx1 = max(i, j), mn2 = k, mx2 = k;
		while (j != i) {
			if (k == g1[j][0]) swap(g1[j][0], g1[j][1]);
			int x = g1[i][1], y = fd1(j, k);
			if (x < mn2 && y < mn2) ans -= 1ll * (mn2 - max(x, y)) * (n + 1 - mx2) * mn1 * (n + 1 - mx1);
			else if (x < mn2 && y > mx2) ans -= 1ll * (mn2 - x) * (y - mx2) * mn1 * (n + 1 - mx1);
			else if (x > mx2 && y < mn2) ans -= 1ll * (mn2 - y) * (x - mx2) * mn1 * (n + 1 - mx1);
			else if (x > mx2 && y > mx2) ans -= 1ll * mn2 * (min(x, y) - mx2) * mn1 * (n + 1 - mx1);
			k = y;
			mn2 = min(mn2, k);
			mx2 = max(mx2, k);
			j = fd2(k, j);
			mn1 = min(mn1, j);
			mx1 = max(mx1, j);
		}
	}
	cout << ans;
	return 0;
}