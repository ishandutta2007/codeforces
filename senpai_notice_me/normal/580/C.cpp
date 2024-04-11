#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAX_N 200005

int n,m,dp[MAX_N];
bool cat[MAX_N],vis[MAX_N];
vector<int>to[MAX_N];
queue<int>que;

inline int BFS() {
	que.push(1); vis[1]=true;
	int nowp,next,ret=0;
	while (!que.empty()) {
		nowp=que.front(); que.pop();
		if (nowp!=1 && to[nowp].size()==1) {
			ret+=(dp[nowp]<=m);
			continue;
		}
		for (int i=0;i<to[nowp].size();i++) {
			next=to[nowp][i];
			if (vis[next]) continue;
			vis[next]=true; dp[next]=cat[next]?dp[nowp]+1:0;
			if (dp[next]>m) continue;
			que.push(next);
		}
	}
	return ret;
}

inline void Init() {
	int u,v;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",cat+i);
	for (int i=1;i<n;i++) {
		scanf("%d%d",&u,&v);
		to[u].push_back(v);
		to[v].push_back(u);
	}
}

inline void Solve() {
	dp[1]=cat[1];
	int ans=BFS();
	printf("%d\n",ans);
}

int main() {
	Init(); Solve();
	
	return 0;
}

//	freopen(".in","r",stdin); freopen(".out","w",stdout);