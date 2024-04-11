#include <bits/stdc++.h>
using namespace std;
const int N = 502;

namespace H {
	bool us[N];
	int match[N];
	vector<int> g[N];
	int n;
	bool dfs(int x) {
		for (auto y: g[x]) {
			if (us[y]) continue;
			us[y] = 1;
			if (match[y] == -1 || dfs(match[y])) {
				match[y] = x; return 1;
			}
		}
		return 0;
	}
	int hungary() {
		memset(match,-1,sizeof(match));
		int tot=0;
		for (int i=0;i<n;i++) {
			memset(us,0,sizeof(us));
			if (dfs(i)) tot ++;
		}
		return tot;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<string> str(n);
	for (int i = 0; i < n; i ++)
		cin >> str[i];

	vector<vector<int> > a(n + 1, vector<int>(m + 1, 0)), s(n + 1, vector<int>(m + 1, 0));
	
	int ans = 0;
	for (int i = n - 1; i >= 0; i --) {
		for (int j = m - 1; j >= 0; j --) {
			a[i][j] = s[i+1][j] ^ s[i][j+1] ^ s[i+1][j+1] ^ (str[i][j] == 'B');
			if (a[i][j]) ans ++;
			s[i][j] = a[i][j] ^ s[i+1][j] ^ s[i][j+1] ^ s[i+1][j+1];
		}
	} 
	//printf("ans = %d\n", ans);
	H::n = max(n, m) + 1;
	for (int i = 0; i < n - 1; i ++) {
		for (int j = 0; j < m - 1; j ++) {
			if (a[i][j] == 1 && a[n-1][j] == 1 && a[i][m-1] == 1) {
				H::g[i].push_back(j);
			}
		}
	}
	int cnt = H::hungary();
	// printf("cnt = %d, ans = %d\n", cnt, ans);
	if (cnt >= 1) {
		ans -= cnt;
		if (cnt % 2 != a[n-1][m-1] && a[n-1][m-1] == 0) ans ++;
		if (cnt % 2 == a[n-1][m-1] && a[n-1][m-1] == 1) ans --;
	}
	cout << ans << "\n";
}