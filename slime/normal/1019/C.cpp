#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define maxn 1000005
using namespace std;
struct edge
{
	int u, v;
	edge *next;
}p[maxn], *h[maxn];
int egcnt = 0;
void addedge(int u, int v)
{
	edge *n1 = &p[egcnt++];
	n1->u = u, n1->v = v, n1->next = h[u], h[u] = n1;
}
int fl[maxn];
int st[maxn], top = 0;
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		addedge(a, b);
	}
	for(int i = 1; i <= n; i++)
	{
		if(fl[i]) continue;
		fl[i] = 1;
		for(edge *p = h[i]; p; p = p->next)
			if(p->v > i) fl[p->v] = -1;
	}
	for(int i = n; i >= 1; i--)
		if(fl[i] == 1)
			for(edge *p = h[i]; p; p = p->next)
				if(p->v < i && fl[p->v] == 1)
					fl[p->v] = -1;
	for(int i = 1; i <= n; i++)
		if(fl[i] == 1) st[top++] = i;
	printf("%d\n", top);
	for(int i = 0; i < top; i++)
		printf("%d ", st[i]);
	return 0;
}