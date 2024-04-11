#include <bits/stdc++.h>
#define maxn 500005
#define ll long long
#define mod 998244353
using namespace std;
struct edge
{
	int u, v;
	edge *next;
}p[maxn << 1], *h[maxn];
int egcnt = 0;
int dep[maxn];
int fa[maxn];
int fl[maxn];
void addedge(int u, int v)
{
	edge *n1 = &p[egcnt++];
	n1->u = u, n1->v = v, n1->next = h[u], h[u] = n1;
}
void dfs(int a)
{
//	cout<<a<<" "<<fa[a]<<" "<<dep[a]<<endl;
	for(edge *p = h[a]; p; p = p->next)
	{
		if(dep[p->v]) continue;
		dep[p->v] = dep[a] + 1;
		fa[p->v] = a;
		fl[a] = 1;
		dfs(p->v);
	}
}
int os[maxn], ocnt = 0;
void otp(int x, int y)
{
	os[ocnt++] = x;
	while(x != y)
		os[ocnt++] = fa[x], 
		x = fa[x];
	printf("%d\n", ocnt);
	for(int i = 0; i < ocnt; i++)
		printf("%d ", os[i]);
	printf("\n");
}
struct th
{
	int id, ans;
	bool operator < (const th &x)const
	{
		return ans < x.ans;
	}
}s[maxn];
int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v), addedge(v, u);
	}
	dep[1] = 1;
	dfs(1);
	for(int i = 1; i <= n; i++)
		if(dep[i] >= n / k + 1)
		{
			printf("PATH\n");
			otp(i, 1);
			return 0;
		}
	for(int i = 1; i <= n; i++)
	{
		int ns[2] = {0, 0};
		if(!fl[i])
		for(edge *p = h[i]; p; p = p->next)
		{
			if(dep[p->v] >= dep[i]) continue;
			if(p->v == fa[i]) continue; 
			if(dep[p->v] >= dep[ns[0]])
				ns[1] = ns[0], ns[0] = p->v;
			else if(dep[p->v] > dep[ns[1]])
				ns[1] = p->v;
		}
		if(!ns[1] || !ns[0]) s[i].ans = maxn;
		else s[i].ans = dep[i] - dep[ns[1]] + 1;
		s[i].id = i;
	}
	ll tt = 0;
	sort(s + 1, s + n + 1);
	printf("CYCLES\n");
	for(int i = 1; i <= k; i++)
	{
		int nid = s[i].id;
		int ns[2] = {0, 0};
		for(edge *p = h[nid]; p; p = p->next)
		{
			if(dep[p->v] >= dep[nid]) continue;
			if(p->v == fa[nid]) continue;
			if(dep[p->v] >= dep[ns[0]])
				ns[1] = ns[0], ns[0] = p->v;
			else if(dep[p->v] > dep[ns[1]])
				ns[1] = p->v;
		}
		if(!ns[0] || !ns[1]) return 1;
		ocnt = 0;
		if((dep[nid] - dep[ns[0]] + 1) % 3)
			otp(nid, ns[0]);
		else if((dep[nid] - dep[ns[1]] + 1) % 3)
			otp(nid, ns[1]);
		else os[ocnt++] = nid, 
			otp(ns[0], ns[1]);
	}
	return 0;
}