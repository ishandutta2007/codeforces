#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <complex>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const int maxn = 2e5 + 5;
const int oo = 1e9;
struct Edge
{
	int to, next;
}edges[maxn << 1];
int te = 1;
int points[maxn];
void adde(const int &a, const int &b)
{
	te ++;
	edges[te].to = b;
	edges[te].next = points[a];
	points[a] = te;
}
int p[maxn], to[maxn];
int pos[maxn], fa[maxn][21];
void set_tree(const int &p)
{
	for(int i = 1; i <= 20; i ++)
		fa[p][i] = fa[fa[p][i - 1]][i - 1];
	for(int e = points[p]; e; e = edges[e].next)
	{
		fa[edges[e].to][0] = p;
		set_tree(edges[e].to);
	}
}
int h[maxn << 2];
int sum;
int query(const int &l, const int &r)
{
	int ans = oo;
	for(int s = l + sum - 1, t = r + sum + 1; s ^ t ^ 1; s >>= 1, t >>= 1)
	{
		if(~s & 1)
			ans = min(ans, h[s ^ 1]);
		if(t & 1)
			ans = min(ans, h[t ^ 1]);
	}
	return ans;
}
int a[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int n, m, q;
	cin >> n >> m >> q;
	for(sum = 1; sum < m + 2; sum <<= 1);
	for(int i = 1; i <= n; i ++)
		cin >> p[i];
	for(int i = 1; i < n; i ++)
		to[p[i]] = p[i + 1];
	to[p[n]] = p[1];
	for(int i = 1; i <= m; i ++)
		cin >> a[i];
	for(int i = 1; i <= n; i ++)
		pos[i] = m + 1;
	for(int i = m; i >= 1; i --)
	{
		adde(pos[to[a[i]]], i);
		pos[a[i]] = i;
	}
	fa[m + 1][0] = m + 1;
	set_tree(m + 1);
	for(int i = 1; i <= m; i ++)
	{
		int x = i;
		for(int j = 20; j >= 0; j --)
			if((n - 1 >> j) & 1)
				x = fa[x][j];
		h[sum + i] = x;
	}
	for(int i = sum - 1; i; i --)
		h[i] = min(h[i << 1], h[i << 1 | 1]);
	for(int i = 1; i <= q; i ++)
	{
		int l, r;
		cin >> l >> r;
		cout << (query(l, r) <= r ? 1 : 0);
	}
	cout << endl;
	
	return 0;
}