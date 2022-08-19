#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <deque>
#define mod 998244353
#define maxn 200005
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
	a->l = l, a->r = r, a->lz = 0;
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
		a->lz = max(a->lz, lz);
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
	if(pl <= mid) return max(a->lz, q(a->ch[0], pl));
	else return max(a->lz, q(a->ch[1], pl));
}
int n, qs;
int a[maxn];
int l[maxn], r[maxn];
int main()
{
	scanf("%d%d", &n, &qs);
	for(int i = 1; i <= qs; i++)
		l[i] = n + 1, r[i] = 0;
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]), 
		l[a[i]] = min(l[a[i]], i), 
		r[a[i]] = max(r[a[i]], i);
	root = &p[stcnt++];
	bdtree(root, 1, n);
	for(int i = 1; i <= qs; i++)
		push(root, l[i], r[i], i);
	bool fl = 1;
	for(int i = 1; i <= n; i++)
		if(a[i] && a[i] < q(root, i)) fl = 0;
	int nf = 0;
	for(int i = 1; i <= n; i++)
		if(a[i] == qs) nf = 1;
	for(int i = 1; i <= n; i++)
		if(a[i]) continue;
		else if(!nf) a[i] = qs, nf = 1;
		else a[i] = max(q(root, i), 1);
	if(!(nf && fl)) printf("NO\n");
	else
	{
		printf("YES\n");
		for(int i = 1; i <= n; i++)
			printf("%d ", a[i]);
	}
	return 0;
}