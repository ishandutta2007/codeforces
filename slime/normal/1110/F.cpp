#include <bits/stdc++.h>
#define maxn 500005
#define ll long long
#define mod 998244353
using namespace std;
const ll inf = 1000000000000000000ll;
struct ST
{
	int l, r;
	ST *ch[2];
	ll lz, mn;
}p[maxn << 1], *root;
int stcnt = 0;
int ms;
ll dis[maxn];
void upd(ST *a)
{
	a->mn = min(a->ch[0]->mn, a->ch[1]->mn);
} 
void actlz(ST *a, ll x)
{
	a->lz += x, a->mn += x;
}
void pushdown(ST *a)
{
	if(a->lz)
		for(int i = 0; i < 2; i++)
			actlz(a->ch[i], a->lz);
	a->lz = 0;
}
int x[maxn];
void bdtree(ST *a, int l, int r)
{
	a->l = l, a->r = r;
	if(l == r) 
	{
		a->mn = dis[l];
		return ;
	}
	int mid = (l + r) >> 1;
	a->ch[0] = &p[stcnt++];
	a->ch[1] = &p[stcnt++];
	bdtree(a->ch[0], l, mid), 
	bdtree(a->ch[1], mid + 1, r);
	upd(a);
}
void push(ST *a, int l, int r, ll x)
{
	if(a->l == l && a->r == r)
	{
		actlz(a, x);
		return;
	}
	int mid = (a->l + a->r) >> 1;
	pushdown(a);
	if(r <= mid) push(a->ch[0], l, r, x);
	else if(l > mid) push(a->ch[1], l, r, x);
	else push(a->ch[0], l, mid, x),
		push(a->ch[1], mid + 1, r, x);
	upd(a);
}
ll q(ST *a, int l, int r)
{
	if(a->l == l && a->r == r)
		return a->mn;
	int mid = (a->l + a->r) >> 1;
	pushdown(a);
	if(r <= mid) return q(a->ch[0], l, r);
	else if(l > mid) return q(a->ch[1], l, r);
	else 
		return min(q(a->ch[0], l, mid),
		q(a->ch[1], mid + 1, r));
}
vector<int> nx[maxn], w[maxn];
vector<int> qs[maxn];
int v[maxn], l[maxn], r[maxn];
ll ans[maxn];
ll dep[maxn];
int mxs[maxn];	
int n, Q;
int f[maxn];
void dfs(int a)
{
	for(int j = 0; j < qs[a].size(); j++)
	{
		int nv = qs[a][j];
		ans[nv] = q(root, l[nv], r[nv]);
	//	cout<<nv<<" "<<a<<" "<<l[nv]<<" "<<r[nv]<<" "<<q(root, l[nv], r[nv])<<endl;
	}
	for(int i = 0; i < nx[a].size(); i++)
	{
		push(root, 1, n, w[a][i]);
		push(root, nx[a][i], mxs[nx[a][i]], -2 * w[a][i]);
		dfs(nx[a][i]);
		push(root, 1, n, -w[a][i]);
		push(root, nx[a][i], mxs[nx[a][i]], 2 * w[a][i]);
	}
}
int main()
{
	scanf("%d%d", &n, &Q);
	for(int i = 2; i <= n; i++)
	{
		int ws;
		scanf("%d%d", &f[i], &ws);
		nx[f[i]].push_back(i), w[f[i]].push_back(ws);
		dis[i] = dis[f[i]] + ws;
	}
	for(int i = 1; i <= Q; i++)
	{
		scanf("%d%d%d", &v[i], &l[i], &r[i]);
		qs[v[i]].push_back(i);
	}
	for(int i = 1; i <= n; i++)
	{
		if(!(nx[i].empty()))
			dis[i] = inf;
	}
	for(int i = n; i >= 1; i--)
	{
		mxs[i] = max(mxs[i], i);
		mxs[f[i]] = max(mxs[f[i]], mxs[i]);
	//	cout<<i<<" "<<mxs[i]<<endl;
	}
	root = &p[stcnt++];
	bdtree(root, 1, n);
	dfs(1);
	for(int i = 1; i <= Q; i++)
		printf("%lld\n", ans[i]);
	return 0;
}