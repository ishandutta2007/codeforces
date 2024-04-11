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
#define mp(a, b) make_pair(a, b)
using namespace std;
typedef pair<long long, long long> pp;
const int maxn = 6e5 + 5;
const long long oo = 1e18;
struct Edge
{
	int to, next;
	long long c1, c2;
}edges[maxn << 1];
int te = 1;
int points[maxn];
void adde(const int &a, const int &b, const long long &w1, const long long &w2)
{
	te ++;
	edges[te].to = b;
	edges[te].c1 = w1;
	edges[te].c2 = w2;
	edges[te].next = points[a];
	points[a] = te;
}
long long w[maxn];
bool mark[maxn];
void Dijkstra(const int &s, const int &n)
{
	for(int i = 1; i <= n; i ++)
		w[i] = oo;
	static priority_queue<pp, vector<pp>, greater<pp> > q;
	w[s] = 0;
	q.push(mp(0, s));
	while(!q.empty())
	{
		pp now = q.top();
		q.pop();
		if(mark[now.second])
			continue;
		mark[now.second] = 1;
		for(int e = points[now.second]; e; e = edges[e].next)
			if(w[edges[e].to] > now.first + edges[e].c1 + edges[e].c2)
			{
				w[edges[e].to] = now.first + edges[e].c1 + edges[e].c2;
				q.push(mp(w[edges[e].to], edges[e].to));
			}
	}
}
int d[maxn], fa[maxn][21];
long long dis[maxn][21][2][2];
void set_tree(const int &p)
{
	for(int i = 1; i <= 20; i ++)
	{
		fa[p][i] = fa[fa[p][i - 1]][i - 1];
		for(int a = 0; a < 2; a ++)
			for(int b = 0; b < 2; b ++)
			{
				dis[p][i][a][b] = oo;
				for(int c = 0; c < 2; c ++)
					dis[p][i][a][b] = min(dis[p][i][a][b], dis[p][i - 1][a][c] + dis[fa[p][i - 1]][i - 1][c][b]);
			}
	}
	for(int e = points[p]; e; e = edges[e].next)
		if(edges[e].to != fa[p][0] && edges[e].to > 0)
		{
			int to = edges[e].to;
			d[to] = d[p] + 1;
			fa[to][0] = p;
			dis[to][0][0][0] = min(edges[e].c1, w[to] + edges[e].c2 + w[p]);
			dis[to][0][0][1] = min(edges[e].c1 + w[p], w[to] + edges[e].c2);
			dis[to][0][1][0] = min(w[to] + edges[e].c1, edges[e].c2 + w[p]);
			dis[to][0][1][1] = min(w[to] + edges[e].c1 + w[p], edges[e].c2);
			set_tree(to);
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
pp work(const int &u, const bool &p, const int &v)
{
	static long long trans[2];
	trans[p] = 0;
	trans[p ^ 1] = w[u];
	int x = u;
	for(int i = 20; i >= 0; i --)
		if(d[fa[x][i]] >= d[v])
		{
			static long long tmp[2];
			for(int a = 0; a < 2; a ++)
				tmp[a] = trans[a];
			for(int a = 0; a < 2; a ++)
			{
				trans[a] = oo;
				for(int b = 0; b < 2; b ++)
					trans[a] = min(trans[a], tmp[b] + dis[x][i][b][a]);
			}
			x = fa[x][i];
		}
	return mp(trans[0], trans[1]);
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> w[i];
	for(int i = 1; i < n; i ++)
	{
		int a, b;
		long long w1, w2;
		cin >> a >> b >> w1 >> w2;
		adde(a, b, w1, w2);
		adde(b, a, w1, w2);
	}
	for(int i = 1; i <= n; i ++)
	{
		adde(0, i, w[i], 0);
		adde(i, 0, w[i], 0);
	}
	Dijkstra(0, n);
	d[1] = 1;
	set_tree(1);
	int q;
	cin >> q;
	for(int i = 1; i <= q; i ++)
	{
		int u, v;
		cin >> u >> v;
		int x = u + 1 >> 1, y = v + 1 >> 1;
		bool a = (u + 1) & 1, b = (v + 1) & 1;
		int p = lca(x, y);
		pp now1 = work(x, a, p), now2 = work(y, b, p);
		cout << min(now1.first + now2.first, now1.second + now2.second) << endl;
	}
	
	return 0;
}