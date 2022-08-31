#include <bits/stdc++.h>
#define maxn 200005
#define ll long long
#define mod 1000000007
using namespace std;
struct edge
{
	int u, v;
	edge *next;
}p[maxn << 1], *h[maxn];
int egcnt = 0;
void addedge(int u, int v)
{
	edge *n1 = &p[egcnt++];
	n1->u = u, n1->v = v, n1->next = h[u], h[u] = n1;
}
ll dp[2][maxn];
int c[maxn];
void dfs(int a, int fa)
{
	int fl = 0;
	for(edge *p = h[a]; p; p = p->next)
	{
		if(p->v == fa) continue;
		fl = 1;
		dfs(p->v, a);
		dp[0][a] += dp[0][p->v];
	}
	dp[1][a] = dp[0][a];
	for(edge *p = h[a]; p; p = p->next)
	{
		if(p->v == fa) continue;
		dp[1][a] = min(dp[1][a], dp[0][a] + dp[1][p->v] - dp[0][p->v]); 
	}
	dp[0][a] = min(dp[0][a], c[a] + dp[1][a]);
	if(fl == 0) dp[1][a] = 0, dp[0][a] = c[a];
//	cout<<a<<" "<<dp[0][a]<<" "<<dp[1][a]<<endl;
}
int ca[2][maxn];
int fl[maxn];
void dfs2(int a, int fa)
{
//	int fl = 0;
	ll n1 = 0, n2 = 0;
	for(edge *p = h[a]; p; p = p->next)
	{
		if(p->v == fa) continue;
	//	fl = 1, 
		n1 += dp[0][p->v];
		n2 = max(n2, dp[0][p->v] - dp[1][p->v]);
	}
	if(ca[0][a])
	{
		if(dp[0][a] == dp[1][a] + c[a]) fl[a] = 1, ca[1][a] = 1;
		for(edge *p = h[a]; p; p = p->next)
			if(p->v == fa) continue;
			else
			{
				if(dp[0][a] == n1)
					ca[0][p->v] = 1;
			}
	}
	if(ca[1][a])
	{
		if(c[a] == 0) fl[a] = 1;
		int tt = 0;
		for(edge *p = h[a]; p; p = p->next)
		{
			if(p->v == fa) continue;
			if(dp[0][p->v] - dp[1][p->v] == n2)
				ca[1][p->v] = 1, tt++;
		}
		for(edge *p = h[a]; p; p = p->next)
		{
			if(p->v == fa) continue;
			int n1 = (dp[0][p->v] - dp[1][p->v] == n2);
			if(n1 < tt) ca[0][p->v] = 1;
		}
	}
	for(edge *p = h[a]; p; p = p->next)
	{
		if(p->v == fa) continue;
		dfs2(p->v, a);
	}
}
int ans[maxn], cnt = 0;
int main()
{
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++)
		cin>>c[i];
	for(int i = 1; i < n; i++)
	{
		int a, b;
		cin>>a>>b;
		addedge(a, b), 
		addedge(b, a);
	}
	dfs(1, 0);
	ca[0][1] = 1;
	dfs2(1, 0);
	for(int i = 1; i <= n; i++)
		if(fl[i]) ans[cnt++] = i;
	cout<<dp[0][1]<<" "<<cnt<<endl;
	for(int i = 0; i < cnt; i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}