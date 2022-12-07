#include <bits/stdc++.h>

using namespace std;

const int N = 16000000;
int ss[400000];
int cnt;

struct Tree{
	int sum, lazy, ls, rs;
}tree[N];
	
inline void up(int k)
{
	int &ls = tree[k].ls, &rs = tree[k].rs;
	if(!ls)ls = ++cnt;
	if(!rs)rs = ++cnt;
	tree[k].sum = tree[ls].sum + tree[rs].sum;
}

inline void down(int k, int l, int mid, int r)
{
	if(!tree[k].lazy)return;
	int op = tree[k].lazy - 1, &ls = tree[k].ls, &rs = tree[k].rs;
	if(!ls)ls = ++cnt;
	if(!rs)rs = ++cnt;
	tree[ls].lazy = tree[rs].lazy = op + 1;
	tree[ls].sum = op * (mid - l + 1);
	tree[rs].sum = op * (r - mid);
	tree[k].lazy = 0;
}

void change(int &k, int l, int r, int ll, int rr, int op)
{
	if(!k)k = ++cnt;
	if(ll <= l && r <= rr)
	{
		tree[k].sum = op * (r - l + 1);
		tree[k].lazy = op + 1;
		return;
	}
	int mid = (l + r) >> 1;
	down(k, l, mid, r);
	if(mid >= ll)change(tree[k].ls, l, mid, ll, rr, op);
	if(mid < rr)change(tree[k].rs, mid + 1, r, ll, rr, op);
	up(k);
}

int main()
{
	int n, q;
	scanf("%d", &n);
	scanf("%d", &q);
	int root = 0;
	change(root, 1, n, 1, n, 1);
	for(int i = 1; i <= q; i++)
	{
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		change(root, 1, n, l, r, k - 1);
		printf("%d\n", tree[root].sum);
	}
	for(int i=1; i<400000; i++)
	{
	    ss[i]++;
	}
}