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
const int maxn = 1e5 + 5;
struct Edge
{
	int to, next;
	int flag;
}edges[maxn << 1];
int te = 1;
int points[maxn];
void adde(const int &a, const int &b, const int &flag)
{
	te ++;
	edges[te].to = b;
	edges[te].flag = flag;
	edges[te].next = points[a];
	points[a] = te;
}
int d[maxn], fa[maxn][21];
void set_tree(const int &p)
{
	for(int i = 1; i <= 20; i ++)
		fa[p][i] = fa[fa[p][i - 1]][i - 1];
	for(int e = points[p]; e; e = edges[e].next)
		if(edges[e].to != fa[p][0])
		{
			d[edges[e].to] = d[p] + 1;
			fa[edges[e].to][0] = p;
			set_tree(edges[e].to);
		}
}
int lca(const int &u, const int &v)
{
	int x = u, y = v;
	if(d[x] < d[y])
		swap(x, y);
	int diff = d[x] - d[y];
	for(int i = 20; i >= 0; i --)
		if((diff >> i) & 1)
			x = fa[x][i];
	for(int i = 20; i >= 0; i --)
		if(fa[x][i] != fa[y][i])
		{
			x = fa[x][i];
			y = fa[y][i];
		}
	return x == y ? x : fa[x][0];
}
int add[maxn];
int ans[maxn];
void getans(const int &p, const int &fa)
{
	for(int e = points[p]; e; e = edges[e].next)
		if(edges[e].flag != fa)
		{
			getans(edges[e].to, edges[e].flag);
			add[p] += add[edges[e].to];
		}
	ans[fa] = add[p];
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i < n; i ++)
	{
		int a, b;
		cin >> a >> b;
		adde(a, b, i);
		adde(b, a, i);
	}
	set_tree(1);
	int k;
	cin >> k;
	for(int i = 1; i <= k; i ++)
	{
		int a, b;
		cin >> a >> b;
		add[a] ++;
		add[b] ++;
		int x = lca(a, b);
		add[x] -= 2;
	}
	getans(1, 0);
	for(int i = 1; i < n; i ++)
		cout << ans[i] << " ";
	cout << endl;
	
	return 0;
}