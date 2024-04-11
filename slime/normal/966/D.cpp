#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
#define maxn 300005
#define ld double
#define ll long long
#define mod 998244353
using namespace std;
ll ksm(ll a, ll b)
{
	if(!b) return 1;
	ll ns = ksm(a, b >> 1);
	ns = ns * ns % mod;
	if(b & 1) ns = ns * a % mod;
	return ns;
}
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
bool flag = 0;
int n;
int stack[maxn], top = 0;
int u[maxn], v[maxn];
int q[maxn], fr, ed;
int pre[maxn];
int dep[maxn];
int inq[maxn];

int lk[maxn];
int nlk[maxn];
int fa[maxn];
int size[maxn];
int d[maxn];
int gfa(int a)
{
	if(fa[a] == a) return a;
	return fa[a] = gfa(fa[a]);
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d", &u[i], &v[i]);
		d[u[i]]++, d[v[i]]++;
		if(u[i] > v[i]) swap(u[i], v[i]);
		addedge(u[i], v[i]), addedge(v[i], u[i]);
	}
	fr = ed = 0;
	q[ed++] = 1, inq[1] = 1;
	while(fr < ed)
	{
		for(edge *p = h[q[fr]]; p; p = p->next)
		{
			if(inq[p->v]) continue;
			pre[p->v] = q[fr], 
			dep[p->v] = dep[q[fr]] + 1, 
			inq[p->v] = 1;
			q[ed++] = p->v;
 		}
 		fr++;
	}
	if(inq[n] && dep[n] <= 3)
	{
		printf("%d\n", dep[n]);
		int npl = n;
		while(npl != 1)
			stack[top++] = npl, npl = pre[npl];
		stack[top++] = 1;
		for(int i = top - 1; i >= 0; i--)
			printf("%d ", stack[i]);
		printf("\n");
		return 0;
	}
	for(edge *p = h[1]; p; p = p->next)
		lk[p->v] = 1;
	for(int i = 1; i <= n; i++)
		if(lk[i])
			for(edge *p = h[i]; p; p = p->next)
			{
				if(p->v == 1) continue;
				if(lk[p->v]) continue;
				printf("4\n");
				printf("1 %d %d 1 %d\n", i, p->v, n);
				return 0;
			}
	//check 4
	
	for(int i = 1; i <= n; i++)
		fa[i] = i, size[i] = 1;
	for(int i = 0; i < m; i++)
		if(lk[u[i]] && lk[v[i]])
		{
			int ufa = gfa(u[i]), vfa = gfa(v[i]);
			if(ufa == vfa) continue;
			fa[ufa] = vfa, size[vfa] += size[ufa];
		}
	for(int i = 1; i <= n; i++)
		if(lk[i])
		{
			if(d[i] == size[gfa(i)]) continue;
			for(edge *p = h[i]; p; p = p->next)
				nlk[p->v] = 1;
			for(int j = 2; j <= n; j++)
			{
				if(!nlk[j]) continue;
				for(edge *p = h[j]; p; p = p->next)
				{
					if(p->v == i) continue;
					if(nlk[p->v]) continue;
					printf("5\n");
					printf("1 %d %d %d %d %d\n", i, j, p->v, i, n);
					return 0;
				}
			}
			
		}
	printf("-1\n");
	return 0;
}