#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

struct Tree{
	int l, r, v;
}tree[N * 100];

int nowans, cnt, n, m, root[N];

void ask(int &k, int l, int r, int ll, int rr)
{
	if(!k)k = ++cnt;
	if(ll <= l && r <= rr)
	{
		nowans = max(nowans, tree[k].v);
		return;
	}
	int mid = (l + r) >> 1;
	if(mid >= ll)ask(tree[k].l, l, mid, ll, rr);
	if(mid < rr)ask(tree[k].r, mid + 1, r, ll, rr);
}

void modify(int &k, int l, int r, int ll, int v)
{
	if(!k)k = ++cnt;
	if(l == r)
	{
		tree[k].v = max(tree[k].v, v);
		return;
	}
	int mid = (l + r) >> 1;
	if(mid >= ll)modify(tree[k].l, l, mid, ll, v);
	else modify(tree[k].r, mid + 1, r, ll, v);
	tree[k].v = max(tree[tree[k].l].v, tree[tree[k].r].v);
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		root[i] = i;
	cnt = n;
	int ans = 0;
	for(int i = 1; i <= m; i++)
	{
		int x, y, v;
		scanf("%d%d%d", &x, &y, &v);
		nowans = 0;
		if(v > 0)ask(root[x], 0, 100000, 0, v - 1);
		modify(root[y], 0, 100000, v, nowans + 1);
		ans = max(ans, nowans + 1); 
	}
	cout << ans << endl;
}