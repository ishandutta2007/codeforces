#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>

using namespace std;

#define maxn 100500

struct Edge
{
	int prev, next, br;
	int x, y;
};

int beg[maxn], en[maxn];
Edge sm[2 * maxn];
int cnt;
int n;
int col[maxn];
char ans[maxn];
int tree[maxn];
int h[maxn];
int st[maxn], stsz;
int it;
int par[maxn];

int killEdge(int id)
{
	if (sm[id].prev != 0)
	{
		sm[sm[id].prev].next = sm[id].next;
	}
	if (sm[id].next != 0)
	{
		sm[sm[id].next].prev = sm[id].prev;
	}
	if (sm[id].next == 0 && sm[id].prev == 0)
	{
		beg[sm[id].x] = 0;
	}
	else
	{
		if (sm[id].prev == 0)
			beg[sm[id].x] = sm[id].next;
	}
	return sm[id].br;
}

int addEdge(int x, int y)
{
	++cnt;
	sm[cnt].x = x;
	sm[cnt].y = y;
	sm[cnt].br = cnt + 1;
	sm[cnt].prev = 0;
	sm[cnt].next = beg[x];
	if (beg[x] != 0)
		sm[beg[x]].prev = cnt;
	beg[x] = cnt;
	++cnt;
	sm[cnt].x = y;
	sm[cnt].y = x;
	sm[cnt].br = cnt - 1;
	sm[cnt].prev = 0;
	sm[cnt].next = beg[y];
	if (beg[y] != 0)
		sm[beg[y]].prev = cnt;
	beg[y] = cnt;
	return 0;
}

int DFS(int x, int iter, int sz, int pr) {
	st[stsz++] = x;
	col[x] = iter;
	tree[x] = 1;
	int cmax = 0;
	for (int i = beg[x]; i != 0; i = sm[i].next)
	{
		if (col[sm[i].y] != iter)
		{
			DFS(sm[i].y, iter, sz, x);
			tree[x] += tree[sm[i].y];
			cmax = max(cmax, tree[sm[i].y]);
		}
	}
	h[x] = max(cmax, sz - tree[x]);
	return 0;
}

int makeAns(int root, int sz, char c)
{
	stsz = 0;
	++it;
	DFS(root, it, sz, -1);
	int cur = root;
	for (int i = 0; i < stsz; ++i)
	{
		if (h[cur] > h[st[i]])
			cur = st[i];
	}
	ans[cur] = c;
	for (int i = beg[cur]; i != 0; i = sm[i].next)
	{
		int nxt = killEdge(i);
		killEdge(nxt);
		if (sm[i].y == par[cur])
		{
			makeAns(sm[i].y, sz - tree[cur], c + 1);
		}
		else
		{
			makeAns(sm[i].y, tree[sm[i].y], c + 1);
		}
	}
	return 0;
}

int main()
{
	scanf("%d", &n);
	cnt = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		addEdge(a, b);
	}
	makeAns(1, n, 'A');
	for (int i = 1; i <= n; ++i)
	{
		if (i != n)
		{
			printf("%c ", ans[i]);
		}
		else
		{
			printf("%c\n", ans[i]);
		}
	}
	return 0;
}