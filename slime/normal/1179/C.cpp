#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <deque>
#define maxn 1000005
#define ll long long
using namespace std;
struct ST
{
	int l, r;
	int mxs, lz;
	ST *ch[2];
}p[maxn << 1], *root;
int stcnt = 0;
void bdtree(ST *a, int l, int r)
{
	a->l = l, a->r = r, a->mxs = a->lz = 0;
	int mid = (l + r) >> 1;
	if(l == r) return;
	a->ch[0] = &p[stcnt++], 
	a->ch[1] = &p[stcnt++];
	bdtree(a->ch[0], l, mid), 
	bdtree(a->ch[1], mid + 1, r);
}
void upd(ST *a)
{
	a->mxs = max(a->ch[1]->mxs, a->ch[0]->mxs);
}
void pushlz(ST *a, int lz)
{
	a->lz += lz, a->mxs += lz;
}
void pushdown(ST *a)
{
	if(!a->lz) return;
	pushlz(a->ch[0], a->lz), 
	pushlz(a->ch[1], a->lz);
	a->lz = 0;
}
void push(ST *a, int l, int r, int lz)
{
//	cout<<"P"<<l<<" "<<r<<" "<<lz<<" "<<a->l<<" "<<a->r<<endl;
	if(a->l == l && a->r == r)
	{
		pushlz(a, lz);
//		cout<<"AF"<<endl;
		return;
	}
	int mid = (a->l + a->r) >> 1;
	pushdown(a);
	if(r <= mid)
		push(a->ch[0], l, r, lz);
	else if(l > mid)
		push(a->ch[1], l, r, lz);
	else 
		push(a->ch[0], l, mid, lz), 
		push(a->ch[1], mid + 1, r, lz);
	upd(a);
}
int q(ST *a)
{
	if(a->l == a->r) return a->l;
	pushdown(a);
	if(a->ch[1]->mxs > 0) return q(a->ch[1]);
	else return q(a->ch[0]);
}
int a[maxn], b[maxn];
int main()
{
	int n, m;
	root = &p[stcnt++];
	bdtree(root, 1, maxn - 1);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]),
		push(root, 1, a[i], 1);
	for(int i = 1; i <= m; i++)
		scanf("%d", &b[i]), 
		push(root, 1, b[i], -1);
	int qq;
	cin>>qq;
	for(int i = 0; i < qq; i++)
	{
		int tp, pl, to;
		scanf("%d%d%d", &tp, &pl, &to);
		if(tp == 1)
		{
			push(root, 1, a[pl], -1);
			a[pl] = to;
			push(root, 1, a[pl], 1);
		}
		else 
		{
			push(root, 1, b[pl], 1);
			b[pl] = to;
			push(root, 1, b[pl], -1);
		}
		if(root->mxs <= 0) printf("-1\n");
		else printf("%d\n", q(root));
	}
	return 0;
}