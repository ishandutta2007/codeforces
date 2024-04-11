#include <bits/stdc++.h>
using namespace std;
const int N = 300000 * 31 + 1;
int dp[N][2], tot;
int ch[N][2];

void insert(int x, int id, int y) {
	int rt = 0;
	for (int i = 30; i >= 0; i --) {
		if (ch[rt][x>>i&1] == 0) ch[rt][x>>i&1] = ++tot;
		rt = ch[rt][x>>i&1];
		dp[rt][id>>i&1] = max(dp[rt][id>>i&1], y);
	}
}
int query(int x, int y) {
	int rt = 0, ans = 0;
	for (int i = 30; i >= 0; i --) {
		int id = x>>i&1;
		if (ch[rt][id^1]) {
			ans = max(ans, dp[ch[rt][id^1]][!(y>>i&1)]);
		}
		if (ch[rt][id]) rt = ch[rt][id]; else break;
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		int n;
		cin >> n;
		vector<int> a(n);
		int ans = 0;
		for (int i = 0; i < n; i ++) {
			cin >> a[i];
			int f = query(a[i]^i, a[i]) + 1;
			ans = max(ans, f);
			insert(i^a[i], i, f);
		}
		for (int i = 0; i <= tot; i ++) for (int j = 0; j < 2; j ++)
			dp[i][j] = ch[i][j] = 0;
		tot = 0;
		cout << ans << "\n";
	}
}