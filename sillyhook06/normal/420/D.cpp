#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
inline int	read()
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; ch < '0' || ch > '9'; ch = getchar())	if (ch == '-')  positive = 0;
	for (; ch >= '0' && ch <= '9'; ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
#define link Link
#define next Next
#define elif else if


struct	node
{
	int size, key, a;
	node *l, *r;
	
	void	update()
	{
		size = 1;
		if (l)	size += l->size;
		if (r)	size += r->size;
	}
}	*null = NULL, Pool[1000007];

node* merge(node* a, node* b)
{
	if (!a)	return b;
	if (!b)	return a;
	if (a->key < b->key)
	{
		a->r = merge(a->r, b);
		a->update();
		return a;
	}
	else
	{
		b->l = merge(a, b->l);
		b->update();
		return b;
	}
}
pair<node*, node*> split(node* a, int n)
{
	if (!a)	return make_pair(null, null);
	if (n >= a->size)	return make_pair(a, null);
	if (!n)	return make_pair(null, a);
	pair<node*, node*> b;
	int cnt = a->l ? a->l->size : 0;
	if (cnt >= n)
	{
		b = split(a->l, n);
		a->l = b.second;
		a->update();
		return make_pair(b.first, a);
	}
	{
		b = split(a->r, n - cnt - 1);
		a->r = b.first;
		a->update();
		return make_pair(a, b.second);
	}
}

int N, M;
bool	done[1000006];
int	ans[1000006], tmpx[1000006], tmpk[1000006]; 

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	N = read(), M = read();
	node *root = NULL;
	for (int i = 1; i <= N; ++ i)
	{
		Pool[i].key = rand();
		Pool[i].l = Pool[i].r = NULL;
		Pool[i].size = 1;
		Pool[i].a = -1;
		root = merge(root, Pool + i);
	}
	for (int i = 1; i <= M; ++ i)	tmpx[i] = read(), tmpk[i] = read();
	for (int i = M; i; -- i)
	{
		int x = tmpx[i], k = tmpk[i];
		pair<node*, node*> A = split(root, 1);
		pair<node*, node*> B = split(A.second, k - 1);
		node *a = A.first, *b = B.first, *c = B.second;
		if (a->a == -1)
		{
			if (done[x])
			{
				printf("-1\n");
				return 0;
			}
			a->a = x;
		}
		else
		{
			if (a->a != x)
			{
				printf("-1\n");
				return 0;
			}
		}
		done[x] = 1;
		root = merge(merge(b, a), c);
	}
	for (int i = 1; i <= N; ++ i)
	{
		pair<node*, node*> A = split(root, 1);
		ans[i] = A.first->a;
		root = A.second;
	}
	for (int i = 1, j = 1; i <= N; ++ i)
	{
		while (done[j])	++ j;
		if (ans[i] == -1)
		{
			ans[i] = j;
			done[j] = 1;
		}
	}
	for (int i = 1; i <= N; ++ i)	printf("%d%c", ans[i], i < N ? ' ' : '\n');

	return 0;
}