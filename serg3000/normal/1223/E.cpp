#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <queue>
#include <deque>
#include <unordered_set>
#include <map>
#include<unordered_map>
#include <bitset>
#include <random>
#include <ctime>
using namespace std;
#define int long long
vector<vector<pair<int, int>>>g;
vector<pair<int, int>>dp;
vector<int>used;
int k;
void dfs(int v, int col) {
	used[v] = 1;
	int ans = 0;
	vector<int>a;
	for (auto u : g[v]) {
		if (!used[u.first]) {
			dfs(u.first, u.second);
		}
		ans += dp[u.first].first;
		a.push_back(dp[u.first].first - dp[u.first].second);
	}
	int n = a.size();
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		a[i] *= -1;
	}
	for (int i = 0; i < min(k, n); i++) {
		if (a[i] > 0) {
			ans += a[i];
		}
	}
	dp[v].first = ans;
	if (col != -1) {
		if (n >= k) {
			if (a[k - 1] > 0) {
				ans -= a[k - 1];
			}
			ans += col;
		}
		else {
			ans += col;
		}
		dp[v].second = ans;
	}
}
signed main() {
	int q;
	cin >> q;
	for (int w = 0; w < q; w++) {
		int n;
		cin >> n >> k;
		g.resize(n);
		for (int i = 0; i < n; i++) {
			g[i].clear();
		}
		dp.clear();
		dp.resize(n);
		used.clear();
		used.resize(n);
		for (int i = 0; i < n - 1; i++) {
			int x, y, ll;
			cin >> x >> y >> ll;
			x--; y--;
			g[x].push_back({ y, ll });
			g[y].push_back({ x, ll });
			
		}
		dfs(0, -1);
		cout << dp[0].first << '\n';
	}

	return 0;
}