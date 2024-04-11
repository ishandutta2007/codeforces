#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100005
#define maxk 105 
using namespace std;
int q[maxn];
int dis[maxn][maxk];
int tp[maxn];
int fr, ed;
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
int main()
{
	int n, m, k, s;
	scanf("%d%d%d%d", &n, &m, &k, &s);
	for(int i = 1; i <= n; i++)
		scanf("%d", &tp[i]);
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v), addedge(v, u);
	}
	for(int i = 1; i <= k; i++)
	{
		fr = ed = 0;
		for(int j = 1; j <= n; j++)
		{
			dis[j][i] = n + 1;
			if(tp[j] == i)
				dis[j][i] = 0, q[ed++] = j;
		}
		while(fr < ed)
		{
			for(edge *p = h[q[fr]]; p; p = p->next)
			{
				int ndis = dis[q[fr]][i] + 1;
				if(dis[p->v][i] <= ndis) continue;
				dis[p->v][i] = ndis, q[ed++] = p->v;
			}
			fr++;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		sort(dis[i] + 1, dis[i] + 1 + k);
		int ns = 0;
		for(int j = 1; j <= s; j++)
			ns += dis[i][j];
		printf("%d ", ns);
	}
	return 0;
}