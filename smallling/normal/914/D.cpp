#include <bits/stdc++.h>

using namespace std;

const int N = 500050;

int a[N], tree[N << 2], cnt;

int gcd(int a, int b)
{
	if(a % b == 0)return b;
	return gcd(b, a % b);
}

void query(int k, int l, int r, int ll, int rr, int v)
{
	if(cnt > 1)return;
	if(ll <= l && r <= rr)
	{
		if(l == r)
		{
			if(tree[k] % v)cnt++;
			return;
		}
		int mid = (l + r) >> 1;
		if((tree[k << 1] % v) && (tree[k << 1 | 1] % v))
		{
			cnt = 2;
			return;
		}
		if(tree[k << 1] % v)
		{
			query(k << 1, l, mid, ll, rr, v);
		}
		if(tree[k << 1 | 1] % v)
		{
			query(k << 1 | 1, mid + 1, r, ll, rr, v);
		}
		return;
	}
	int mid = (l + r) >> 1;
	if(mid >= ll)query(k << 1, l, mid, ll, rr, v);
	if(mid < rr)query(k << 1 | 1, mid + 1, r, ll, rr, v);
}

void modify(int k, int l, int r, int ll, int v)
{
	if(l == r)
	{
		tree[k] = v;
		return;
	}
	int mid = (l + r) >> 1;
	if(mid >= ll)modify(k << 1, l, mid, ll, v);
	else modify(k << 1 | 1, mid + 1, r, ll, v);
	tree[k] = gcd(tree[k << 1], tree[k << 1 | 1]);
}

void build(int k, int l, int r)
{
	if(l == r)
	{
		tree[k] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(k << 1, l, mid);
	build(k << 1 | 1, mid + 1, r);
	tree[k] = gcd(tree[k << 1], tree[k << 1 | 1]);
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	build(1, 1, n);
	int m;
	scanf("%d", &m);
	for(int i = 1; i <= m; i++)
	{
		int opt;
		scanf("%d", &opt);
		if(opt == 1)
		{
			int l, r, y;
			scanf("%d%d%d", &l, &r, &y);
			cnt = 0;
			query(1, 1, n, l, r, y);
			if(cnt < 2)puts("YES");
			else puts("NO");
		}
		else
		{
			int l, y;
			scanf("%d%d", &l, &y);
			modify(1, 1, n, l, y);
		}
	}
}