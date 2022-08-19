#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <deque>
#define inf 1000000007
#define maxn 500005
#define ll long long
using namespace std;
struct ST
{
	ST *ch[2];
	int l, r, lz;
}p[maxn << 1], *root;
int stcnt = 0;
void bdtree(ST *a, int l, int r)
{
	a->l = l, a->r = r, a->lz = inf;
	if(l == r) return;
	int mid = (l + r) >> 1;
	a->ch[0] = &p[stcnt++], a->ch[1] = &p[stcnt++];
	bdtree(a->ch[0], l, mid), 
	bdtree(a->ch[1], mid + 1, r);
}
void push(ST *a, int l, int r, int lz)
{
	if(l > r) return ;
	if(a->l == l && a->r == r)
	{
		a->lz = min(a->lz, lz);
		return ;
	}
	int mid = (a->l + a->r) >> 1;
	if(r <= mid) push(a->ch[0], l, r, lz);
	else if(l > mid) push(a->ch[1], l, r, lz);
	else push(a->ch[0], l, mid, lz), 
		push(a->ch[1], mid + 1, r, lz);
}
int q(ST *a, int pl)
{
	if(a->l == a->r) return a->lz;
	int mid = (a->l + a->r) >> 1;
	if(pl <= mid) return min(a->lz, q(a->ch[0], pl));
	else return min(a->lz, q(a->ch[1], pl));
}
int w[maxn], fa[maxn], top[maxn], dep[maxn], sz[maxn], ftp[maxn], son[maxn];
int dfcnt = 0;
struct edge
{
	int u, v, id, w, tp;
	edge *next;
	bool operator < (const edge &a)const
	{
		if(tp != a.tp) return tp < a.tp;
		return w < a.w;
	}
}egp[maxn << 1], *h[maxn], x[maxn << 1];
int egcnt = 0;
void addedge(int u, int v, int tp)
{
//	cout<<"AD"<<u<<" "<<v<<" "<<tp<<endl;
	edge *n1 = &egp[egcnt++];
	n1->u = u, n1->v = v, n1->tp = tp;
	n1->next = h[u], h[u] = n1;
}
void dfs1(int a)
{
	sz[a] = 1;
	for(edge *p = h[a]; p; p = p->next)
	{
		if(p->v == fa[a]) continue;
		fa[p->v] = a, ftp[p->v] = p->tp, dep[p->v] = dep[a] + 1;
		dfs1(p->v);
		sz[a] += sz[p->v];
		if(sz[p->v] > sz[son[a]]) son[a] = p->v;
	}
}
void dfs2(int a)
{

	w[a] = ++dfcnt;	
//	cout<<a<<" "<<w[a]<<" "<<top[a]<<" "<<son[a]<<endl;
	if(son[a]) 
		top[son[a]] = top[a], dfs2(son[a]);
	for(edge *p = h[a]; p; p = p->next)
	{
		if(p->v == son[a] || p->v == fa[a]) continue;
	//	cout<<"!!"<<p->v<<endl;
		top[p->v] = p->v, dfs2(p->v);
	}
}
void push(int u, int v, int lz)
{
	int ufa = top[u], vfa = top[v];
	while(ufa != vfa)
	{
		if(dep[ufa] < dep[vfa]) swap(u, v), swap(ufa, vfa);
//		cout<<"PUS"<<w[top[u]]<<" "<<w[u]<<" "<<lz<<" "<<u<<" "<<top[u]<<endl;
		push(root, w[top[u]], w[u], lz), 
		u = fa[top[u]], ufa = top[u];
	}
	if(dep[u] < dep[v]) swap(u, v);
	push(root, w[v] + 1, w[u], lz);
//	cout<<"PUS"<<w[v] + 1<<" "<<w[u]<<" "<<lz<<" "<<u<<" "<<v<<" "<<top[u]<<" "<<top[v]<<endl;
}
int f[maxn];
int gf(int x)
{
	if(f[x] == x) return x;
	return f[x] = gf(f[x]);
}
bool fl[maxn << 1];
int main()
{
	int n, k, m;
	scanf("%d%d%d", &n, &k, &m);
	for(int i = 1; i <= n; i++)
		f[i] = i;
	for(int i = 1; i <= k; i++)
		scanf("%d%d", &x[i].u, &x[i].v), 
		x[i].tp = 0;
	for(int i = 1; i <= m; i++)
		scanf("%d%d%d", &x[i + k].u, &x[i + k].v, &x[i + k].w), 
		x[i + k].tp = 1;
	sort(x + 1, x + k + m + 1);
	for(int i = 1; i <= k + m; i++)
	{
		int ufa = gf(x[i].u), vfa = gf(x[i].v);
		if(ufa == vfa) continue;
	//	cout<<"I"<<i<<" "<<x[i].tp<<" "<<x[i].u<<" "<<x[i].v<<endl;
		fl[i] = 1;
		addedge(x[i].u, x[i].v, x[i].tp), addedge(x[i].v, x[i].u, x[i].tp);
		f[ufa] = vfa;
	}
	top[1] = 1, dep[1] = 1, ftp[1] = 1;
	dfs1(1), dfs2(1);
//	cout<<"ASFD"<<endl;
	root = &p[stcnt++];
	bdtree(root, 1, n);
	for(int i = 1; i <= k + m; i++)
		if(!fl[i])
			push(x[i].u, x[i].v, x[i].w);
	ll ans = 0;
	for(int i = 1; i <= n; i++)
		if(ftp[i]) continue;
		else 
		{
			int nans = q(root, w[i]);
		//	cout<<i<<" "<<nans<<" "<<w[4]<<endl;
			if(nans == inf)
			{
				printf("-1\n");
				return 0;
			}
			ans += nans;
		}
	printf("%lld\n", ans);
	return 0;
}