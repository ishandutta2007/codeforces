#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>
#define maxn 100005
#define ll long long
#define mod 1000000007
using namespace std;
struct edge
{
	int u, v;
	edge* next;
}p[maxn << 1], *h[maxn];
int egcnt = 0;
void addedge(int u, int v)
{
	edge *n1 = &p[egcnt++];
	n1->u = u, n1->v = v, n1->next = h[u], h[u] = n1;
}
int dp[maxn];
int bg[2][maxn];
int k;
int fa[maxn];
int q[maxn], ncnt = 1;
void dfs(int a)
{
	q[ncnt++] = a;
	for(edge *p = h[a]; p; p = p->next)
	{
		if(p->v == fa[a]) continue;
		fa[p->v] = a;
		dfs(p->v);
	}
}
int n;
int work(int l)
{
	memset(dp, 0, sizeof(dp));
	memset(bg, 0, sizeof(bg));
	for(int i = n; i >= 1; i--)
	{
		int nid = q[i], pr = fa[nid];
		if(bg[0][nid] + bg[1][nid] + 1 >= l)
		{
			dp[nid]++;
			dp[pr] += dp[nid];
		}
		else
		{
			dp[pr] += dp[nid];
			int ns = bg[0][nid] + 1;
			if(ns >= bg[0][pr])
				bg[1][pr] = bg[0][pr], bg[0][pr] = ns;
			else if(ns >= bg[1][pr])
				bg[1][pr] = ns;
		}
	}
	return dp[1];
}
int ans[maxn];

int pl[maxn];
int main()
{
	scanf("%d", &n);
	for(int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v), addedge(v, u);
	}
	dfs(1);
	int dvs = 1520;
	for(int i = 1; i <= dvs; i++)
		ans[i] = work(i);
	int s = work(1);
	for(int j = 1; j <= n / dvs; j++)
	{
	//	cout<<j<<endl;
		int l = 1, r = n;
		//if(j == 1) l = 1;
		if(s < j) continue;
		while(l < r)
		{
			int mid = (l + r) >> 1;
			if(work(mid + 1) >= j) l = mid + 1;
			else r = mid;
		}
		pl[j] = l;
		for(int k = 1; k <= l; k++)
			ans[k] = max(ans[k], j);
	}
	for(int i = 1; i <= n; i++)
		printf("%d\n", ans[i]);
	return 0;
}