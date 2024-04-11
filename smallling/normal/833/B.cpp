#include <bits/stdc++.h>

#define mn 35010
#define mk 55 

using namespace std;

int tree[mk][mn << 2], lazy[mk][mn << 2], f[mn][mk];
int a[mn], last[mn], now[mn];

int calc(int x, int y)
{
	int cnt = 0;
	for(int i = x; i <= y; i++)
	{
		if(last[i] < x)cnt++;
	}
	return cnt;
}

inline void down(int K, int k)
{
	if(!lazy[K][k])return;
	tree[K][k << 1] += lazy[K][k];
	tree[K][k << 1 | 1] += lazy[K][k];
	lazy[K][k << 1] += lazy[K][k];
	lazy[K][k << 1 | 1] += lazy[K][k];
	lazy[K][k] = 0;
}

void add(int K, int k, int l, int r, int ll, int o)
{
	if(l == r)
	{
		tree[K][k] = o;
		return;
	}
	down(K, k);
	int mid = (l + r) >> 1;
	if(mid >= ll)add(K, k << 1, l, mid, ll, o);
	else add(K, k << 1 | 1, mid + 1, r, ll, o);
	tree[K][k] = max(tree[K][k << 1], tree[K][k << 1 | 1]);
}

void Add(int K, int k, int l, int r, int ll, int rr)
{
	if(ll <= l && r <= rr)
	{
		tree[K][k] ++;
		lazy[K][k] ++;
		return;
	}
	down(K, k);
	int mid = (l + r) >> 1;
	if(mid >= ll)Add(K, k << 1, l, mid, ll, rr);
	if(mid < rr)Add(K, k << 1 | 1, mid + 1, r, ll, rr);
	tree[K][k] = max(tree[K][k << 1], tree[K][k << 1 | 1]);
}

int ask(int K, int k, int l, int r, int ll, int rr)
{
	if(ll <= l && r <= rr)
	{
		return tree[K][k];
	}
	down(K, k);
	int mid = (l + r) >> 1, nowans = 0;
	if(mid >= ll)nowans = ask(K, k << 1, l, mid, ll, rr);
	if(mid < rr)nowans = max(nowans, ask(K, k << 1 | 1, mid + 1, r, ll, rr));
	return nowans;
}

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		last[i] = now[a[i]];
		now[a[i]] = i;
	}
	for(int i = 1; i <= k; i++)
	{
		f[i][1] = calc(1, i);
		for(int k1 = 2; k1 <= k; k1++)
		{
			if(k1 > i)
			{
				f[i][k1] = f[i][k1 - 1];
				continue;
			}
			for(int j = 0; j < i; j++)
				f[i][k1] = max(f[i][k1], f[j][k1 - 1] + calc(j + 1, i));
		}
	}
	for(int k1 = 1; k1 <= k; k1++)
		for(int i = 1; i <= k; i++)
			add(k1, 1, 1, n, i, f[i][k1] + calc(i + 1, k + 1));
	for(int i = k + 1; i <= n; i++)
	{
		f[i][1] = f[i - 1][1];
		if(!last[i])f[i][1]++;
		for(int k1 = 2; k1 <= k; k1++)
		{
			f[i][k1] = ask(k1 - 1, 1, 1, n, 1, i - 1);
		}
		for(int k1 = 0; k1 <= k; k1++)
			add(k1, 1, 1, n, i, f[i][k1]);
		if(i < n)
		{
			for(int k1 = 0; k1 <= k; k1++)
				Add(k1, 1, 1, n, max(last[i + 1], 1), i);
		}
	}
	printf("%d\n", f[n][k]);
}