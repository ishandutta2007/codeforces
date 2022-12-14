//In the name of God
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 550;
const int Mod = 1e9 + 7;
int dp[N][N];
int last[N][N],n,m;
char s[N][N];
pair<int,int> up[2],down[2];
bool check(int i,int j) {
	if(i < 0 || j < 0 || i >= n || j >= m) return 0;
	return 1;
}
bool adj(int i1,int j1,int i2,int j2) {
	if(abs(i1 - i2) + abs(j1 - j2) == 1) return 1;
	return 0;
}
main() {
	up[0] = {0,1};
	up[1] = {1,0};
	down[0] = {0,-1};
	down[1] = {-1,0};
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
		scanf("%s",s[i]);
	int mid = n + m - 1 >> 1;
	if((n + m - 1) & 1) {
		int sum = mid;
		for(int i = 0; i < n; ++i) {
			int j = sum - i;
			if(j < 0 || j >= m) continue;
			dp[i][i] = 1;
		}
	} else {
		int sum = mid;
		for(int i = 0; i < n; ++i) {
			int x = i,y = sum - i;
			if(y < m && y >= 0)
			for(int r = -1; r < 2; ++r) {
				for(int l = -1; l < 2; ++l) {
					if(abs(r + l) == 1) {
						int t = x + r,p = y + l;
						if(t + p < x + y && check(t,p)) {
							if(s[t][p] == s[x][y]) {
								dp[t][x] = 1;
							}
						}
					}
				}
			}
		}
	}
	for(int dis = 2 + ((n + m) & 1); dis < n + m; dis += 2) {
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				last[i][j] = dp[i][j],dp[i][j] = 0;
		int sum1 = ++mid,sum2 = sum1 - dis;
		for(int x = 0; x < n; ++x) {
			int y = sum1 - x;
			if(!check(x,y)) continue;
			for(int t = 0; t < n; ++t) {
				int p = sum2 - t;
				if(!check(t,p)) continue;
				if(s[x][y] != s[t][p]) continue;
				for(int i = 0; i < 2; ++i) {
					int tox = x + down[i].first,toy = y + down[i].second;
					if(!check(tox,toy)) continue;
					for(int j = 0; j < 2; ++j) {
						int tot = t + up[j].first,top = p + up[j].second;
						if(!check(tot,top)) continue;
						dp[t][x] += last[tot][tox]; dp[t][x] %= Mod;
					}
				}
			}
		}
	}
	cout << dp[0][n-1] << endl;
	return 0;
}