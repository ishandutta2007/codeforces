#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define maxn 200005
#define W 5100000
#define ll long long
#define ld double
#define mod 998244353
#define maxb 10
using namespace std;
ll ksm(ll a, ll b)
{
	ll ns = ksm(a, b >> 1);
	ns = ns * ns % mod;
	if(b & 1) ns = ns * a % mod;
	return ns;
}
struct ST
{
	int l, r, lz;
	ST *ch[2];
}p[maxn << 1], *root;
int stcnt = 0;
void bdtree(ST *a, int l, int r)
{
	a->l = l, a->r = r, a->lz = maxb * 2;
	if(l == r) return;
	int mid = (l + r) >> 1;
	a->ch[0] = &p[stcnt++], a->ch[1] = &p[stcnt++];
	bdtree(a->ch[0], l, mid), 
	bdtree(a->ch[1], mid + 1, r);
}
void push(ST *a, int l, int r, int lz)
{
	if(a->l == l && a->r == r)
	{
		a->lz = min(a->lz, lz);
		return;
	}
	int mid = (a->l + a->r) >> 1;
	if(r <= mid) push(a->ch[0], l, r, lz);
	else if(l > mid) push(a->ch[1], l, r, lz);
	else push(a->ch[0], l, mid, lz), 
		push(a->ch[1], mid + 1, r, lz);
}
int Q(ST *a, int pl)
{
	if(a->l == a->r)
		return a->lz;
	int mid = (a->l + a->r) >> 1;
	if(pl <= mid) return min(a->lz, Q(a->ch[0], pl));
	else return min(a->lz, Q(a->ch[1], pl));
} 
int fst[W][maxb];
bool bpr[W];
vector<int> prs[W];
struct qr
{
	int l, r, id;
	bool operator < (const qr&x)const
	{
		return l < x.l;
	}
}as[W];
int ans[W];
int a[maxn];
int mns[maxb * 2];
int tt;
int dv[maxb];
int npl;
void dfs(int a, int b, int size)
{
	if(a == tt)
	{
		size = tt - size;
		for(int l = 0; l < maxb; l++)
			mns[l + size] = min(mns[l + size], fst[b][l]);
	//	cout<<b<<" "<<size<<endl;
		fst[b][size] = npl;
		return;
	}
	dfs(a + 1, b, size), 
	dfs(a + 1, b * dv[a], size + 1);
}
int main()
{
	for(int i = 0; i < W; i++)
		bpr[i] = 1;
	for(int i = 2; i < W; i++)
	{
		if(!bpr[i]) continue;
		for(int j = 2; j * i < W; j++)
			bpr[i * j] = 0;
		ll ns = i;
		int tms = 1;
		while(ns < W)
		{
			if(tms)
				for(int j = 1; j * ns < W; j++)
					if(j % i) prs[j * ns].push_back(i);
			ns *= i, tms ^= 1;
		}
	}
//	cout<<"AF"<<endl;
	int n, q;
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	root = &p[stcnt++];
	bdtree(root, 1, n);
	for(int i = 1; i < W; i++)
		for(int j = 0; j < maxb; j++)
			fst[i][j] = n + 1;
//	cout<<"ADF"<<endl;
	for(int i = 1; i <= q; i++)
		scanf("%d%d", &as[i].l, &as[i].r), 
		as[i].id = i;
	sort(as + 1, as + q + 1);
	int pl = q;
	for(int i = n; i >= 1; i--)
	{
		for(int j = 0; j < 2 * maxb; j++)
			mns[j] = n + 1;
		tt = prs[a[i]].size();
		for(int j = 0; j < tt; j++)
			dv[j] = prs[a[i]][j];	
	//	cout<<"CAAL"<<i<<" "<<tt<<endl;
		npl = i;
		dfs(0, 1, 0);
	//	cout<<"CAAL111"<<i<<" "<<tt<<endl;
		for(int j = 0; j < 2 * maxb; j++)
		{
		//	cout<<"ASSS"<<j<<endl;
			if(mns[j] <= n)
			//	cout<<i<<" PISSS"<<j<<" "<<mns[j]<<endl,
				push(root, mns[j], n, j);
		}
	//	cout<<"CAAL"<<i<<" "<<pl<<" "<<as[pl].l<<" "<<as[pl].r<<endl;
		while(pl && as[pl].l == i)
			ans[as[pl].id] = Q(root, as[pl].r), 
			pl--;
	//	cout<<"ADF"<<i<<endl;
	}
	for(int i = 1; i <= q; i++)
		printf("%d\n", ans[i]);
	return 0;
}