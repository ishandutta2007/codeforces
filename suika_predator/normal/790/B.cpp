#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define maxn 200005
#define maxk 5
using namespace std;
struct edge
{
	int u, v;
	edge *next;
	edge *rev;
	bool flag;
}p[maxn << 1], *h[maxn];
int egcnt = 0;
void addedge(int u, int v)
{
	edge *new1 = &p[egcnt++];
	edge *new2 = &p[egcnt++];
	new1->u = u, new1->v = v, new1->next = h[u], h[u] = new1;
	new2->u = v, new2->v = u, new2->next = h[v], h[v] = new2;
	new1->rev = new2, new2->rev = new1;
	new1->flag = new2->flag = 1;
}
int sz[maxn];
int mipl, mis;
ll nans = 0; // 
int k, n;
void getzx(int a, int fa, int asize)
{
	sz[a] = 1;
	int mxs = 0;
	for(edge *p = h[a]; p; p = p->next)
	{
		if(!p->flag || p->v == fa) continue;
		getzx(p->v, a, asize), sz[a] += sz[p->v];
		if(asize == n)
			nans += (ll)sz[p->v] * (n - sz[p->v]);
		mxs = max(mxs, sz[p->v]);
	}
	int ns = max(mxs, asize - sz[a]);
	if(ns < mipl) mipl = ns, mis = a;
}
int dep[maxn];
int cnt[maxk];
int acnt[maxk];
ll ans[maxk];

void dfs(int a, int fa)
{
	cnt[dep[a] % k]++;
	for(edge *p = h[a]; p; p = p->next)
	{
		if(p->v == fa || !p->flag) continue;
		dep[p->v] = dep[a] + 1;
		dfs(p->v, a);
	}
}
void work(int a, int asize)
{
//	cout<<"WORK"<<a<<" "<<asize<<endl;
//	cout<<ans[0]<<" "<<ans[1]<<" "<<nans<<endl;
	memset(acnt, 0, sizeof(acnt));
	acnt[0] = 1;
	for(edge *p = h[a]; p; p = p->next)
	{
		if(!p->flag) continue;
		memset(cnt, 0, sizeof(cnt));
		dep[p->v] = 1, dfs(p->v, a);
		for(int i = 0; i < k; i++)
			for(int j = 0; j < k; j++)
				ans[(i + j) % k] += (ll)cnt[i] * (ll)acnt[j]; 
			//	cout<<"PLUS"<<i<<" "<<j<<" "<<cnt[i]<<" "<<acnt[j]<<endl;
		for(int i = 0; i < k; i++)
			acnt[i] += cnt[i];
	}
	getzx(a, -1, asize);
	for(edge *p = h[a]; p; p = p->next)
	{
		if(!p->flag) continue;
		p->flag = p->rev->flag = 0;
		mipl = mis = maxn;
		getzx(p->v, a, sz[p->v]);
		work(mis, sz[p->v]);
	}
}
int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v);
	}
	work(1, n);
	for(int i = 0; i < k; i++)
		if(i) nans += (k - i) * ans[i];
	nans /= k;
	printf("%I64d\n", nans);
	return 0;	
}