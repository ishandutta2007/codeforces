#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue> 
#define ll long long

#define maxn 400005
using namespace std;
struct edge
{
	int u, v;
	ll w;
	edge *next;
}p[maxn << 2], *h[maxn];
int egcnt = 0;
void addedge(int u, int v, ll w)
{
	edge *n1 = &p[egcnt++];
	n1->u = u, n1->v = v, n1->w = w, n1->next = h[u], h[u] = n1;
}
ll dis[maxn];
struct th
{
	int a;
	ll num;
	bool operator < (const th &c)const
	{
		return num > c.num;
	}
};
priority_queue <th> q;
int n, m;
void work()
{
	for(int i = 0; i <= n; i++)
		dis[i] = 1e9, dis[i] *= dis[i];
	dis[0] = 0;
	th n1;
	n1.a = 0, n1.num = dis[0];
	q.push(n1);
	while(!q.empty())
	{
		th n1 = q.top();
		q.pop();
		if(n1.num != dis[n1.a]) continue;
		for(edge *p = h[n1.a]; p; p = p->next)
		{
			ll ndis = p->w + dis[n1.a];
			if(ndis >= dis[p->v]) continue;
			dis[p->v] = ndis;
			th n2;
			n2.a = p->v, n2.num = dis[p->v], q.push(n2);
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		int u, v;
		ll w;
		scanf("%d%d%I64d", &u, &v, &w);
		w *= 2;
		addedge(u, v, w), addedge(v, u, w);
	}
	for(int i = 1; i <= n; i++)
	{
		ll a;
		scanf("%I64d", &a);
		addedge(0, i, a);
	}
	work();
	for(int i = 1; i <= n; i++)
		printf("%I64d ", dis[i]);
	return 0;
}