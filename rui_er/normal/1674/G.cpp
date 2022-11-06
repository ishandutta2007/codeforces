// Problem: CF1674G Remove Directed Edges
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1674G
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n, m, in[N], out[N], deg[N], dp[N];
vector<int> e[N];
queue<int> q;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
void toposort() {
	memcpy(deg, in, sizeof(in));
	fill(dp+1, dp+1+n, 1);
	rep(i, 1, n) if(!deg[i]) q.push(i);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int v : e[u]) {
			if(in[v] > 1 && out[u] > 1) chkmax(dp[v], dp[u]+1);
			if(!--deg[v]) q.push(v);
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		++in[v];
		++out[u];
	}
	toposort();
	printf("%d\n", *max_element(dp+1, dp+1+n));
	return 0;
}