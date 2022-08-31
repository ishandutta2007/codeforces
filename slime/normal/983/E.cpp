#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <ctime>
#define ll long long
#define maxn 200005
#define dvs 305
#define mod 10000007
using namespace std;
struct ST
{
	ST *ch[2];
	int sum, mns;
	int l, r;
}p[maxn << 2], *root;
int stcnt = 0;
void bdtree(ST *a, int l, int r)
{
	a->l = l, a->r = r, a->sum = 0, a->mns = maxn;
	if(l == r) return;
	int mid = (l + r) >> 1;
	a->ch[0] = &p[stcnt++], a->ch[1] = &p[stcnt++];
	bdtree(a->ch[0], l, mid), bdtree(a->ch[1], mid + 1, r);
}
void ins(ST *a, int pl)
{
	a->sum++;
	if(a->l == a->r) return;
	int mid = (a->l + a->r) >> 1;
	if(pl <= mid) ins(a->ch[0], pl);
	else ins(a->ch[1], pl);
}
void push(ST *a, int l, int r, int lz)
{
	if(a->l == l && a->r == r)	
	{
		a->mns = min(a->mns, lz);
		return;
	}
	int mid = (a->l + a->r) >> 1;
	if(r <= mid) push(a->ch[0], l, r, lz);
	else if(l > mid) push(a->ch[1], l, r, lz);
	else push(a->ch[0], l, mid, lz), push(a->ch[1], mid + 1, r, lz);
}
int mns[maxn];
void dfs(ST *a, int nans)
{
	nans = min(nans, a->mns);
	if(a->l == a->r)
	{
		mns[a->l] = nans;
		return;
	}
	dfs(a->ch[0], nans), dfs(a->ch[1], nans);
}
int q(ST *a, int l, int r)
{
	if(a->l == l && a->r == r) return a->sum;
	int mid = (a->l + a->r) >> 1;
	if(r <= mid) return q(a->ch[0], l, r);
	else if(l > mid) return q(a->ch[1], l, r);
	else return q(a->ch[0], l, mid) + q(a->ch[1], mid + 1, r);
}
struct edge
{
	int u, v;
	edge *next;
}egp[maxn << 1], *egh[maxn];
int egcnt = 0;
void addedge(int u, int v)
{
	edge *n1 = &egp[egcnt++];
	n1->u = u, n1->v = v, n1->next = egh[u], egh[u] = n1;
}
int w[maxn], fa[maxn], dep[maxn], size[maxn], top[maxn], son[maxn];
void dfs1(int a)
{
	size[a] = 1;
	for(edge *p = egh[a]; p; p = p->next)
	{
		if(p->v == fa[a]) continue;
		fa[p->v] = a, 
		dep[p->v] = dep[a] + 1, 
		dfs1(p->v), 
		size[a] += size[p->v];
		if(size[p->v] > size[son[a]])
			son[a] = p->v;
	}	
}
int dfcnt = 0;
void dfs2(int a)
{
	w[a] = ++dfcnt;
	if(son[a])
		top[son[a]] = top[a], 
		dfs2(son[a]);
	for(edge *p = egh[a]; p; p = p->next)
	{
		if(p->v == fa[a] || p->v == son[a]) continue;
		top[p->v] = p->v, 
		dfs2(p->v);
	}
}
int lca(int a, int b)
{
	int x = top[a], y = top[b];
	while(x != y)
	{
		if(dep[x] < dep[y]) swap(a, b), swap(x, y);
		a = fa[x], 
		x = top[a];
	}
	if(dep[a] < dep[b]) swap(a, b);
	return b;
}
struct pls
{
	int a, b;
	bool operator < (const pls & x)const
	{
		return a < x.a;
	}
}act[maxn];
struct qr
{
	int id, tm, l, r;
	bool operator < (const qr &a)const
	{
		return tm < a.tm;
	}
}qs[maxn * 4];
int qans[maxn], nq[maxn];
bool flag[maxn];
int jp[maxn];
int tr[maxn];
int main()
{
//	freopen("1.txt", "w", stdout);
	int n, m;
	scanf("%d", &n);
	for(int i = 2; i <= n; i++)
	{
		int p;
		scanf("%d", &p);
		addedge(p, i);
	}
	top[1] = 1, 
	dep[1] = 1, 
	dfs1(1), 
	dfs2(1);
	root = &p[stcnt++];
	bdtree(root, 1, dfcnt);
	for(int i = 1; i <= n; i++)
		tr[w[i]] = i;
		
	scanf("%d", &m);
	for(int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		if(w[u] > w[v]) swap(u, v);
		act[i].a = w[u], act[i].b = w[v];
		int x = top[u], y = top[v];
		int lc = lca(u, v);
	//	cout<<lc<<endl;
	
		while(x != y)
		{
			if(dep[x] < dep[y]) swap(u, v), swap(x, y);
			push(root, w[x], w[u], w[lc]);
			u = fa[x], x = top[u];
		}
		if(w[u] < w[v]) swap(u, v);
		push(root, w[v], w[u], w[lc]);
	}
	dfs(root, maxn);
	
	for(int i = 1; i <= n; i++)
		if(mns[w[i]] != maxn) jp[i] = tr[mns[w[i]]];
		else jp[i] = maxn;
	
	sort(act, act + m);
	int qcnt = 0;
	int Q;
	scanf("%d", &Q);
	for(int i = 1; i <= Q; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		int lc = lca(u, v);
		int pl1 = u, pl2 = v;
		while(1)
		{
			if(pl1 == lc) break;
			qans[i]++;
			if(jp[pl1] == maxn || dep[jp[pl1]] >= dep[pl1]) 
			{
				qans[i] = -2 * maxn;
				break;
			}
			if(dep[jp[pl1]] <= dep[lc]) break;
			pl1 = jp[pl1]; 
		}
		while(1)
		{
			if(pl2 == lc) break;
			qans[i]++;
			if(jp[pl2] == maxn || dep[jp[pl2]] >= dep[pl2]) 
			{
				qans[i] = -2 * maxn;
				break;
			}
			if(dep[jp[pl2]] <= dep[lc]) break;
			pl2 = jp[pl2]; 
		}
		if(pl1 == lc || pl2 == lc) continue;
		
		if(w[pl1] > w[pl2]) 
			swap(pl1, pl2);
		
		qs[qcnt].id = -i, 
		qs[qcnt].tm = w[pl1] - 1, 
		qs[qcnt].l = w[pl2], 
		qs[qcnt++].r = w[pl2] + size[pl2] - 1;
		qs[qcnt].id = i, 
		qs[qcnt].tm = w[pl1] + size[pl1] - 1, 
		qs[qcnt].l = w[pl2], 
		qs[qcnt++].r = w[pl2] + size[pl2] - 1;
	//	cout<<pl1<<" "<<pl2<<" "<<w[pl1]<<" "<<w[pl2]<<endl;
	}
	sort(qs, qs + qcnt);
	int pl1 = 0, pl2 = 0;
	for(int i = 1; i <= n; i++)
	{
		while(act[pl1].a == i)
			ins(root, act[pl1].b), /*cout<<"INS"<<act[pl1].a<<" "<<act[pl1].b<<endl, */
			pl1++;
		while(qs[pl2].tm == i)
		{
			int nans = q(root, qs[pl2].l, qs[pl2].r);
			if(qs[pl2].id < 0) nq[-qs[pl2].id] -= nans;
			else nq[qs[pl2].id] += nans;
		//	cout<<qs[pl2].id<<" "<<qs[pl2].l<<" "<<qs[pl2].r<<" "<<qs[pl2].tm<<" "<<nans<<endl;
			pl2++;
		}
	}
	for(int i = 1; i <= Q; i++)
		if(nq[i] > 0) qans[i]--;
	for(int i = 1; i <= Q; i++)
		if(qans[i] < 0) printf("-1\n");
		else printf("%d\n", qans[i]); 
	return 0;
 } 
 /*
7
1 1 1 4 5 6
4
4 2
5 4
1 3
6 7
1
2 3

*/