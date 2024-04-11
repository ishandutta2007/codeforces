#include <bits/stdc++.h>
using namespace std;

#define N 350010

int n, m, a[N], dp[N], pre[N], last[N], last_dp;

map <int, int> :: iterator it;
map <int, int> mp;

int main() {

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i ++) {
		pre[i] = last[a[i]];
		last[a[i]] = i;
	}
	for (int i = 1; i <= n; i ++) {
		if (!pre[i]) dp[i] = dp[i - 1] + 1;
		else dp[i] = dp[i - 1];
	}
	for (int k = 2; k <= m; k ++) {
		mp.clear();
		for (int i = k; i <= n; i ++) if (dp[i - 1] == dp[i]) mp[i] = 1;
		dp[k] = k;
		mp[0] = n + 1 - k;
		for (int i = k + 1; i <= n; i ++) {
			it = mp.upper_bound(pre[i]);
			it --;
			it->second --;
			if (it->second == 0) mp.erase(it->first);
			dp[i] = n + 1 - mp.begin()->second;
		}
	}
	printf("%d", dp[n]);
}