
#include <bits/stdc++.h>
#define maxn 200005
#define ll long long
using namespace std;
struct th
{
	int num, pl;
	th(){num = -maxn, pl = 0;}
	th(int a, int b)
	{
		num = a,
		pl = b;
	}
	bool operator < (th a)
	{
		return num < a.num;
	}
	void otp()
	{
		cout<<num<<" "<<pl<<endl;
	}
};
th un(th n1, th n2)
{
	if(n1 < n2) swap(n1, n2);
	return n1;
} 
struct edge
{
	int u, v, c, fl;
	edge *next;
	edge *rev;
}egp[maxn << 1], *h[maxn];
int egcnt = 0;
void addedge(int u, int v, int c)
{
	edge *n1 = &egp[egcnt++];
	edge *n2 = &egp[egcnt++];
	n1->u = u, n1->v = v, n1->c = c, n1->fl = 1;
	n2->u = v, n2->v = u, n2->c = c, n2->fl = 1;
	n1->next = h[u], n2->next = h[v];
	n1->rev = n2, n2->rev = n1;
	h[u] = n1, 
	h[v] = n2;
}
int mx, mpl;
int sz[maxn], son[maxn];
void dfs(int a, int fa, int asize)
{
	sz[a] = 1;
	son[a] = 0;
	for(edge *p = h[a]; p; p = p->next)
	{
		if(p->v == fa || !p->fl) continue;
		dfs(p->v, a, asize);
		sz[a] += sz[p->v];
		if(sz[p->v] > sz[son[a]]) son[a] = p->v;
	}
	int nm = max(sz[son[a]], asize - sz[a]);
	if(nm < mx) mx = nm, mpl = a; 
}
int st[maxn], ed;
int dep[maxn], tf[maxn];
struct col
{
	vector<th> u;
	col(){u.clear();}
	void bd(int a)
	{
		u.resize(a);
		for(int i = 0; i < a; i++)
			u[i] = th();
	}
	void upd(int pl, th s)
	{
		u[pl] = un(s, u[pl]);
	}
}ns[maxn];
col uni(col a, col b)
{
	if(a.u.size() < b.u.size()) swap(a, b);
	for(int i = 0; i < b.u.size(); i++)
		a.upd(i, b.u[i]);
	return a;
}
int fr;
int tt = 0;
int x, y;
int L, R;
col cdq(int l, int r)
{
	if(l == r) return ns[l];
	int mid = (l + r) >> 1;
	col n1 = cdq(l, mid), n2 = cdq(mid + 1, r);
	int npl = n1.u.size() - 1;
	fr = ed = 0;
	/*
	cout<<"DCQ"<<l<<" "<<r<<endl;
	for(int i = 0; i < n1.u.size(); i++)
		n1.u[i].otp();
	cout<<endl;
	for(int i = 0; i < n2.u.size(); i++)
		n2.u[i].otp();
	cout<<endl;*/
	for(int i = 0; i < n2.u.size(); i++)
	{
		while(npl + i >= L && npl >= 0)
		{
			while(fr < ed && n1.u[st[ed - 1]].num <= n1.u[npl].num)
			 	ed--;
			st[ed++] = npl;
			npl--;
		}
		while(fr < ed && i + st[fr] > R)
			fr++;
		if(fr < ed && n1.u[st[fr]].num + n2.u[i].num >= 0)
		{
			tt = 1, 
			x = n2.u[i].pl, 
			y = n1.u[st[fr]].pl;
	//		cout<<"!!!"<<x<<" "<<y<<endl;
		}
	//	cout<<"PL"<<i<<" "<<fr<<" "<<ed<<" "<<stack[fr]<<" "<<tt<<endl;
	}
	return uni(n1, n2);
}
int ncnt = 0;
void dfs2(int a, int fa)
{
	st[ed++] = a;
	for(edge *p = h[a]; p; p = p->next)
	{
		if(p->v == fa || !p->fl) continue;
		dep[p->v] = dep[a] + 1;
		tf[p->v] = tf[a] + p->c;
		dfs2(p->v, a);
	}
}
void work(int a, int asize)
{
	if(tt) return;
//	cout<<"WAOK"<<a<<" "<<asize<<endl;
	ncnt = 0;
	ns[ncnt].bd(1);
	ns[ncnt].upd(0, th(0, a));
	ncnt++;
	for(edge *p = h[a]; p; p = p->next)
	{
		if(!p->fl) continue;
		ed = 0;
		dep[p->v] = 1, tf[p->v] = p->c;
		dfs2(p->v, a);
		ns[ncnt].bd(ed + 1);
		for(int i = 0; i < ed; i++)
		{
			int nid = st[i];
			th n1 = th(tf[nid], nid);
			ns[ncnt].upd(dep[nid], n1);
		}
		ncnt++;
	}
	if(ncnt) 
	{
	//	cout<<"CAL"<<endl;
		cdq(0, ncnt - 1);
	//	cout<<"AFT"<<endl;
	}
	dfs(a, 0, asize);
	for(edge *p = h[a]; p; p = p->next)
	{
		if(!p->fl) continue;
		mx = maxn;
		p->fl = p->rev->fl = 0;
		dfs(p->v, 0, sz[p->v]);
		work(mpl, sz[p->v]);
	}
}
int a[maxn], b[maxn], c[maxn];
int nm[maxn];
int n;
bool check(int t)
{
	tt = 0;
	egcnt = 0;
	for(int i = 0; i < maxn; i++)
		h[i] = NULL;
	for(int i = 1; i < n; i++)
		if(c[i] >= t)
			addedge(a[i], b[i], 1);
		else addedge(a[i], b[i], -1);
		
	work(1, n);
//	cout<<tt<<endl;
	return tt;
}
int main()
{
	scanf("%d%d%d", &n, &L, &R);
	for(int i = 1; i < n; i++)
		scanf("%d%d%d", &a[i], &b[i], &c[i]), 
		nm[i] = c[i];
	sort(nm + 1, nm + n);
	int l = 1, r = n - 1;
//	cout<<check(8)<<endl;
//	cout<<x<<" "<<y<<endl;
//	while(1);
	while(l < r)
	{
		int mid = (l + r) >> 1;
		if(check(nm[mid + 1])) l = mid + 1;
		else r = mid;
	}
	check(nm[l]);
	cout<<x<<" "<<y<<endl;
	return 0;	
}