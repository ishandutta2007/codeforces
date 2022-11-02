#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1e5+10;

int n,q,fa[N][22],dp[N],head[N],top;
struct zs{
	int to,next;
}a[N << 1];

inline void add(int f,int t){
	a[++top].to = t;
	a[top].next = head[f];
	head[f] = top;
	a[++top].to = f;
	a[top].next = head[t];
	head[t] = top;
}

inline int lca(int x,int y){
	if(dp[x] < dp[y]) swap(x,y);
	for(int i=20;i >= 0;i--)
		if(dp[fa[x][i]] >= dp[y])
			x = fa[x][i];
	if(x == y) return x;
	for(int i=20;i >= 0;i--)
		if(fa[x][i] != fa[y][i])
			x = fa[x][i] , y = fa[y][i];
	return fa[x][0];
}

inline void dfs(int x,int d){
	dp[x] = d;
	for(int i=head[x];i != -1;i = a[i].next)
		if(a[i].to != fa[x][0])
			fa[a[i].to][0] = x , dfs(a[i].to,d+1);
}

int main()
{
	memset(head,-1,sizeof(head));
	scanf("%d",&n);
	int u,v;
	for(int i=1;i < n;i++)
		scanf("%d%d",&u,&v) , add(u,v);
	dfs(1,1);
	for(int j=1;j <= 20;j++)		//j!!!!! 
		for(int i=1;i <= n;i++)
			fa[i][j] = fa[fa[i][j-1]][j-1];
	scanf("%d",&q);
	int x,y,k;
	while(q--){
		scanf("%d%d%d%d%d",&u,&v,&x,&y,&k);
		int t = lca(x,y);
		if(dp[x]-dp[t]+dp[y]-dp[t] <= k && !((k-(dp[x]-dp[t]+dp[y]-dp[t]))&1)){
			puts("YES");
			continue;
		}
		int l1 = lca(u,x),l2 = lca(u,y),l3 = lca(v,x),l4 = lca(v,y);
		if(dp[x]-dp[l1]+dp[u]-dp[l1] + dp[y]-dp[l4]+dp[v]-dp[l4] + 1 <= k && !((k-(dp[x]-dp[l1]+dp[u]-dp[l1] + dp[y]-dp[l4]+dp[v]-dp[l4] +1))&1)){
			puts("YES");
			continue;
		}
		if(dp[x]-dp[l3]+dp[v]-dp[l3] + dp[y]-dp[l2]+dp[u]-dp[l2] + 1 <= k && !((k-(dp[x]-dp[l3]+dp[v]-dp[l3] + dp[y]-dp[l2]+dp[u]-dp[l2] +1))&1)){
			puts("YES");
			continue;
		}
		puts("NO");
	}
	return 0;
}