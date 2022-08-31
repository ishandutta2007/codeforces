#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <ctime>
#define ll long long
#define maxn 100805
#define dvs 305
#define mod 10000007
using namespace std;
int a[maxn];
int lz[maxn]; 
ll cnt = 0; 
struct qs
{
	int pt;
	int num;
	int hash()
	{
		int ns = (pt * 100007 + num) % mod;
		if(ns < 0)
			ns += mod;
		return ns;
	}
	bool operator == (qs a)
	{
		return pt == a.pt && num == a.num;
	}
	void otp()
	{
		cout<<pt<<" "<<num<<endl;
	}
};
int h[mod], nx[maxn], sz[maxn];
qs n1[maxn];
queue<int> x;
int n, Q;
ll ncnt = 0;
ll cnt0 = 0;
void ins(qs a)
{
//	cnt0++;
	int hs = a.hash();

	int pl = h[hs];
	int ans = 0;
	bool flag = 1;
	while(pl)
	{
		ncnt++;
		if(n1[pl] == a) 
		{	
			sz[pl]++;
			return ;
		}
		pl = nx[pl];
	}	
	int npl = x.front();
	n1[npl] = a, 
	sz[npl] = 1, 
	x.pop();
	nx[npl] = h[hs], 
	h[hs] = npl;
}
ll cnt2 = 0;
int fl = 0;
int wr = 0;
void del(qs a)
{
//	cnt0++;
	int hs = a.hash();
	int pl = h[hs];
	int ans = 0;
	bool flag = 1;
	int fr = 0;
	while(pl)
	{
		if(n1[pl] == a) 
		{	
			if(sz[pl] > 1) sz[pl]--;
			else
			{
				if(pl == h[hs]) h[hs] = nx[pl];
				else nx[fr] = nx[pl];
				sz[pl] = 0, 
				x.push(pl);
			}
			return ;
		}
		fr = pl, 
		pl = nx[pl];
	}
}
int gx[maxn];
void act(int pl, int num, int t)
{
	qs n1;
	if(t)
	{
		
		n1.pt = gx[pl], n1.num = a[pl];
		del(n1);
	}
	
	a[pl] += num;
	n1.pt = gx[pl], n1.num = a[pl];
	ins(n1);
}	
void add(int l, int r, int v)
{
	for(int i = l; i <= r; )
	{
		if(i % dvs == 1 && i + dvs <= r + 1)
			lz[gx[i]] += v, 
			i += dvs;
		else
			act(i, v, 1),
			i++;
	}
}

int q(int x, ll num)
{
//	cnt0++;
	qs a;
	a.pt = x, a.num = num;
	int hs = a.hash();
	int pl = h[hs];
	while(pl)
	{
		ncnt++; 
		if(n1[pl] == a) 
			return sz[pl];
		pl = nx[pl];
	}
	return 0;
}
int q(int l, int r, int num)
{
	int ans = 0;
	for(int i = l; i <= r; )
	{
		if(i % dvs == 1 && i + dvs <= r + 1)
			ans += q(gx[i], num - lz[gx[i]]),
		//	cout<<num - lz[gx[i]]<<" "<<gx[i]<<endl,
			i += dvs;
		else 
		{
			if(a[i] + lz[gx[i]] == num)
				ans++;
			i++;
		}
	}
	return ans;
}
struct edge
{
	int u, v;
	edge *next;
}p[maxn << 1], *egh[maxn];
int egcnt = 0;
void addedge(int u, int v)
{
	edge *n1 = &p[egcnt++];
	n1->u = u, n1->v = v, n1->next = egh[u], egh[u] = n1;
}
int w[maxn], fa[maxn], dep[maxn], size[maxn], top[maxn], son[maxn];
void dfs1(int a)
{
	size[a] = 1;
	for(edge *p = egh[a]; p; p = p->next)
	{
		if(p->v == fa[a]) continue;
		fa[p->v] = a, dfs1(p->v), size[a] += size[p->v];
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
void read(int &a)
{
	a = 0;
	bool flag = 0;
	char ch = getchar();
	while(ch > '9' || ch < '0') 
	{
		if(ch == '-') flag = 1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
		a = a * 10 + ch - '0', ch = getchar();
	if(flag) a = -a;
}
int s[maxn];
int main()
{
//	freopen("1.txt", "w", stdout);
	for(int i = 1; i < maxn; i++)
		gx[i] = (i - 1) / dvs + 1;
	int n, m;
	read(n), read(m);
	for(int i = 2; i <= n; i++)
	{
		int p;
		read(p);
		addedge(p, i), addedge(i, p);
	}
	for(int i = 1; i <= n; i++)
		read(s[i]);
	for(int i = 1; i <= n; i++)
		x.push(i);	
	dfs1(1);
	top[1] = 1, dfs2(1);	
	for(int i = 1; i <= n; i++)
		a[w[i]] = s[i];	
	for(int i = 1; i <= n; i++)
		act(i, 0, 0);
//	cout<<q(1, 2, 0)<<endl;
	int mns = 1000000;
	int nans = 0;
	for(int i = 0; i < m; i++)	
	{ 
		int p = 0;
		read(p);
		if(p > 0) 
		{
			if(a[w[p]] + lz[gx[w[p]]] < 0) 
				nans--;
			act(w[p], -mns, 1);
			int npl = p;
			while(npl)
			{
				add(w[top[npl]], w[npl], -1), 
			//	cout<<w[top[npl]]<<" "<<w[npl]<<endl;
				nans += q(w[top[npl]], w[npl], -1);
				npl = fa[top[npl]];
			}
		//	cout<<"END"<<endl;
		}
		else
		{
			p = -p;
			act(w[p], mns, 1);
			if(a[w[p]] + lz[gx[w[p]]] < 0) 
				nans++;
			int npl = p;
			while(npl)
			{
				add(w[top[npl]], w[npl], 1), 
				nans -= q(w[top[npl]], w[npl], 0);
				npl = fa[top[npl]];
			}
		}
		printf("%d ", nans);
	}
//	cout<<cnt0<<" "<<ncnt<<endl;
	return 0;
 } 
 /*
 3 1
 1 2
0 0 0
3
*/