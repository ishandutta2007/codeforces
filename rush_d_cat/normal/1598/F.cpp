#include <bits/stdc++.h>
using namespace std;
struct Item {
	int tot, m;
	map<int,int> mp;
	void init(string s) {
		tot = m = 0;
		tot = count(s.begin(),s.end(),'(') - count(s.begin(), s.end(), ')');
		int c = 0;
		for (int i = 0; s[i]; i ++) {
			if (s[i] == '(') c ++; else c --;
			m = min(m, c);
			mp[c] ++;
		}
	}
};
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);

	int n;
	cin >> n;
	
	vector<string> s(n);
	vector<Item> it(n);
	for (int i = 0; i < n; i ++) {
		cin >> s[i]; 
		it[i].init(s[i]);
	}	
	constexpr int N = 400000 + 10;
	constexpr int inf = 1e9;
	vector<int> dp(1<<n, -inf), total(1<<n, 0);
	dp[0] = 0;
	for (int mask = 0; mask < 1<<n; mask ++) {
		int sum = 0;
		for (int i = 0; i < n; i ++)
			if (mask >> i & 1) sum += it[i].tot;
		total[mask] = sum;

		for (int i = 0; i < n; i ++) if (!(mask >> i & 1))
			if (sum + it[i].m >= 0) 
				dp[mask|1<<i] = max(dp[mask|1<<i], ((sum + it[i].m == 0) ? it[i].mp[it[i].m] : 0) + dp[mask]);
	}
	//cout << "ok" << "\n";
	int ans = 0;
	for (int i = 0; i < n; i ++) {
		vector<int> res(N, 0), mp(N, 0);
		for (int j = 0, lim = 0, cur = 0; j < s[i].length(); lim ++) {
			while (j < s[i].length() && cur <= lim) {
				int tcur = cur + (s[i][j] == ')' ? 1 : -1);
				if (tcur <= lim) {
					cur = tcur, j ++;
					if (cur >= 0)
					mp[cur] ++;
				} 
				if (tcur > lim) break;
			}
			res[lim] = mp[lim];
		}

		for (int mask = 0; mask < 1<<n; mask ++) if (not (mask >> i & 1)) {
			if (total[mask] >= 0 && dp[mask] >= 0) {
				ans = max(ans, dp[mask] + res[total[mask]]);
			}
		}
	}
	cout << ans << "\n";
}