#include <bits/stdc++.h>
using namespace std;
int n, m; vector<int> d[100009], dp[100009][22]; bool vis[100009][22];
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = i * 2; j <= n; j += i) {
			d[j].push_back(i);
		}
	}
	vis[1][0] = true;
	for(int i = 1; i <= m; i++) {
		for(int j = 2; j <= n; j++) {
			for(int k : d[j]) {
				if(vis[k][i - 1]) {
					dp[j][i] = dp[k][i - 1];
					dp[j][i].push_back(j / k);
					vis[j][i] = true;
					break;
				}
			}
		}
	}
	if(!vis[n][m]) cout << -1 << endl;
	else for(int i : dp[n][m]) cout << i << ' ';
	return 0;
}