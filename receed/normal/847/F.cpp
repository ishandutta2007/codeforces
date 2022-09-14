
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef FLOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, k, m, a, t;
	cin >> n >> k >> m >> a;
	vector<vector<int>> c(n, vector<int>(3)), now;
	for (int i = 0; i < n; i++)
		c[i][2] = i;
	for (int i = 0; i < a; i++) {
		cin >> t;
		c[--t][0]++;
		c[t][1] = -i;
	}
	sort(c.begin(), c.end());
	vector<int> ans(n, 0);
	for (int i = 0; i < n; i++) {
		now = c;
		now[i][0] += m - a;
		if (m > a)
			now[i][1] = 1 - m;
		int d = 0;
		for (int j = 0; j < n; j++)
			d += (now[j] > now[i]);
		if (!(a == m && c[i][0] == 0) && d < k)
			ans[now[i][2]] = 1;
	}
	for (int i = 0; i < n; i++) {
		now = c;
		now.erase(now.begin() + i);
		int v = m - a;
		if (k == n) {
			if (c[i][0] == 0)
				ans[c[i][2]] ^= 3;
			continue;
		}
		for (int j = n - 2; j >= n - k - 1; j--) {
			if (now[j][0] == c[i][0] && now[j][1] < c[i][1])
				v--;
			else if (now[j][0] < c[i][0])
				v -= c[i][0] - now[j][0] + 1;
		}
		if (c[i][0] == 0 || v >= 0)
			ans[c[i][2]] ^= 3;
	}
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]);
}