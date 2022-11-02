#include<bits/stdc++.h>
using namespace std;

#define N 300030

vector <int> v[N];
vector <long long> wg[N], mg[N];
map <pair<int, int>, long long> mp;

int color, x, y, col[N], n, m, q, dp[N][2];

void DFS(int x){
	col[x] = 1;
	for(auto y : v[x])if(!col[y]){
		DFS(y);
		if(dp[y][0] + 1 > dp[x][0]){
			dp[x][1] = dp[x][0];
			dp[x][0] = dp[y][0] + 1;
		}
		else if(dp[y][0] + 1 > dp[x][1]){
			dp[x][1] = dp[y][0] + 1;
		}
	}
}

void dfs(int x, int dep){
	wg[color].emplace_back(max(dep, dp[x][0]));
	col[x] = color;
	for(auto y : v[x]) if(!col[y]){
		if(dp[x][0] == dp[y][0] + 1) dfs(y, max(dep, dp[x][1]) + 1);
		else dfs(y, max(dep, dp[x][0]) + 1);
	}
}



int main(){
	//freopen("d.in", "r", stdin);
	scanf("%d %d %d", &n, &m, &q);
	while(m --){
		scanf("%d %d", &x, &y);
		v[x].emplace_back(y);
		v[y].emplace_back(x);
	}
	for(int i = 1; i <= n; i ++){
		if(!col[i]) DFS(i);
		col[i] = 0;
	}
	for(int i = 1; i <= n; i ++) if(!col[i]){
		++ color;
		dfs(i, 0);
		sort(wg[color].begin(), wg[color].end());
		mg[color].emplace_back(0);
		long long tot = 0;
		for(auto y : wg[color]){
			tot += y;
			mg[color].emplace_back(tot);
		}
	}
	while(q --){
		scanf("%d %d", &x, &y);
		x = col[x];
		y = col[y];
		if(x == y){ puts("-1"); continue; }
		if(wg[x].size() < wg[y].size()) swap(x, y);
		int len1 = wg[x].size(), len2 = wg[y].size();
		if(mp[make_pair(x, y)]) { printf("%.10lf\n", 1. * mp[make_pair(x, y)] / len1 / len2); continue; }
		int det = max(wg[x][wg[x].size()-1], wg[y][wg[y].size()-1]);
		long long ans = 0;
		for(auto z : wg[y]){
			int t = upper_bound(wg[x].begin(), wg[x].end(), det - 1 - z) - wg[x].begin();
			ans += 1ll * (z + 1) * (len1 - t) + 1ll * t * det;
			ans += mg[x][len1] - mg[x][t];
		}
		mp[make_pair(x, y)] = ans;
		printf("%.10lf\n", 1. * ans / len1 / len2);
	}
}