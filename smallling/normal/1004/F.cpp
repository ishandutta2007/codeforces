#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

struct lhy{
	int x, v;
}L[22], R[22];

struct Tree{
	long long ans;
	int l[20], r[20];
}tree[N << 2], now;

int n, m, x, nowl;
int a[N], sum[22];

inline int cmp1(const lhy &a, const lhy &b)
{
	return a.x > b.x;
}

inline int cmp2(const lhy &a, const lhy &b)
{
	return a.x < b.x; 
}

Tree Merge(const Tree &a, const Tree &b, int l, int r, int mid)
{
	Tree c;
	c.ans = a.ans + b.ans;
	for(int i = 0; i < 20; i++)
	{
		L[i].x = b.l[i];
		L[i].v = 1 << i;
		R[i].x = a.r[i];
		R[i].v = 1 << i;
	}
	sort(R, R + 20, cmp1);
	if(R[0].x != mid)R[20].x = mid, R[20].v = 0;
	else R[20].x = 0;
	for(int i = 0; i < 19; i++)
		if(R[i].x == R[i + 1].x)R[i + 1].v |= R[i].v, R[i].x = 0;
	sort(R, R + 21, cmp1);
	sort(L, L + 20, cmp2);
	if(L[0].x != mid + 1)L[20].x = mid + 1, L[20].v = 0;
	else L[20].x = n + 1;
	for(int i = 0; i < 19; i++)
		if(L[i].x == L[i + 1].x)L[i + 1].v |= L[i].v, L[i].x = n + 1;
	sort(L, L + 21, cmp2);
	sum[0] = L[0].v;
	for(int i = 1; i <= 20; i++)
		sum[i] = sum[i - 1] | L[i].v;
	int i = 0, j = 20;
	while(j >= 0 && R[j].x == 0)j--;
	R[j + 1].x = l - 1;
	j = 20;
	while(j >= 0 && L[j].x == n + 1)j--;
	L[j + 1].x = r;
	int nowsum = 0;
	while(i <= 20 && j >= 0)
	{
		if(R[i].x == l - 1)break;
		nowsum |= R[i].v;
		while(j > 0 && (nowsum | sum[j - 1]) >= x)j--;
		if((nowsum | sum[j]) >= x)c.ans += 1ll * (r - L[j].x + 1) * (R[i].x - R[i + 1].x);
		i++;
	}
	for(int i = 0; i < 20; i++)
	{
		c.l[i] = min(a.l[i], b.l[i]);
		c.r[i] = max(a.r[i], b.r[i]);
	}
	return c;
}

void build(int k, int l, int r)
{
	if(l == r)
	{
		for(int i = 19; i >= 0; i--)
			if((a[l] >> i) & 1)tree[k].l[i] = tree[k].r[i] = l;
			else tree[k].l[i] = n + 1, tree[k].r[i] = 0;
		tree[k].ans = (a[l] >= x);
		return;
	}
	int mid = (l + r) >> 1;
	build(k << 1, l, mid);
	build(k << 1 | 1, mid + 1, r);
	tree[k] = Merge(tree[k << 1], tree[k << 1 | 1], l, r, mid);
}

void modify(int k, int l, int r, int ll, int v)
{
	if(l == r)
	{
		for(int i = 19; i >= 0; i--)
			if((v >> i) & 1)tree[k].l[i] = tree[k].r[i] = l;
			else tree[k].l[i] = n + 1, tree[k].r[i] = 0;
		tree[k].ans = (v >= x);
		return;
	}
	int mid = (l + r) >> 1;
	if(mid >= ll)modify(k << 1, l, mid, ll, v);
	else modify(k << 1 | 1, mid + 1, r, ll, v);
	tree[k] = Merge(tree[k << 1], tree[k << 1 | 1], l, r, mid);
}

void query(int k, int l, int r, int ll, int rr)
{
	if(ll <= l && r <= rr)
	{
		if(now.ans == -1)now = tree[k];
		else now = Merge(now, tree[k], nowl, r, l - 1);
		return;
	}
	int mid = (l + r) >> 1;
	if(mid >= ll)query(k << 1, l, mid, ll, rr);
	if(mid < rr)query(k << 1 | 1, mid + 1, r, ll, rr);
}

int main()
{
	scanf("%d%d%d", &n, &m, &x);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	build(1, 1, n);
	for(int i = 1; i <= m; i++)
	{
		int opt;
		scanf("%d", &opt);
		if(opt == 1)
		{
			int x, v;
			scanf("%d%d", &x, &v);
			modify(1, 1, n, x, v);
		}
		else
		{
			int l, r;
			scanf("%d%d", &l, &r);
			nowl = l;
			now.ans = -1;
			for(int i = 0; i < 20; i++)
				now.l[i] = n + 1, now.r[i] = 0;
			query(1, 1, n, l, r);
			printf("%lld\n", now.ans);
		}
	}
}