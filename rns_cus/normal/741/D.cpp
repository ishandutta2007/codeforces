#include<bits/stdc++.h>
using namespace std;

#define N 500050

int dt[N], ft[N], id[N], dtime, val[N], sz[N], hs[N], dp[N];
int dist[1 << 22], ans[N];
vector <int> v[N];

inline void chkmax(int &A, int B){ if(A < B) A = B; }

void dfs(int x){
	dt[x] = ++ dtime;
	id[dtime] = x;
	sz[x] = 1;
	for(auto y : v[x]){
		dp[y] = dp[x] + 1;
		dfs(y);
		sz[x] += sz[y];
		if(sz[hs[x]] < sz[y]) hs[x] = y;
	} ft[x] = dtime;
}

inline int mxlen(int value){
	int ret = -1e9;
	if(dist[value]) ret = dist[value];
	for(int t = 0; t < 22; t ++) if(dist[value^(1<<t)]) chkmax(ret, dist[value^(1<<t)]);
	return ret;
}

#define z id[i]

void DFS(int x, bool fg){
	for(auto y : v[x]) if(y != hs[x]) DFS(y, 1);
	if(hs[x]) DFS(hs[x], 0);
	for(auto y : v[x]){
		chkmax(ans[x], ans[y]);
		if(y != hs[x]){
			for(int i = dt[y]; i <= ft[y]; i ++) chkmax(ans[x], mxlen(val[z]) + dp[z] - dp[x] * 2);
			for(int i = dt[y]; i <= ft[y]; i ++) chkmax(dist[val[z]], dp[z]);
		}
	}
	chkmax(dist[val[x]], dp[x]);
	chkmax(ans[x], mxlen(val[x]) - dp[x]);
	if(fg) for(int i = dt[x]; i <= ft[x]; i ++) dist[val[z]] = 0;
}

int n, x;
char s[10];

int main(){
	scanf("%d", &n);
	for(int i = 2; i <= n; i ++){
		scanf("%d %s", &x, s);
		v[x].push_back(i);
		val[i] = val[x]^(1<<s[0]-'a');
	}
	dfs(1);
	DFS(1, 0);
	for(int i = 1; i <= n; i ++) printf("%d ", ans[i]);
}