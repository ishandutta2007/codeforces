#include <iostream>
#include <string.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

vector < int > g[110000];
int c[110000], d[110000];
int mn[110000], mx[110000];
int n, m;
int d1[110000], d2[110000];
bool used[110000];
double res[110000];

void dfs(int v)
{
	if (g[v].size() == 0)
	{
		d1[v] = c[v], d2[v] = c[v];
		mn[v] = c[v], mx[v] = c[v];
		return ;
	}
	for (int i = 0; i < g[v].size(); i ++)
		dfs(g[v][i]);

	d1[v] = mx[g[v][0]];
	d2[v] = mn[g[v][1]];

	mn[v] = min(c[v], min(mn[g[v][0]], mn[g[v][1]]));
	mx[v] = max(c[v], max(mx[g[v][0]], mx[g[v][1]]));
}


int num[110000];
bool comp(int x, int y) {return d[x] < d[y];}
int g_first(int x)
{
        int l = 1, r = m;
        while (r - l > 1)
        {
                int key = (l + r) / 2;
                if (d[num[key]] > x)
                        r = key; else
                        l = key;
        }
        if (d[num[l]] > x) return l;
        if (d[num[r]] > x) return r;
        return -1;
}

int g_last(int x)
{
        int l = 1, r = m;
        while (r - l > 1)
        {
                int key = (l + r) / 2;
                if (d[num[key]] < x)
                        l = key; else
                        r = key;
        }
        if (d[num[r]] < x) return r;
        if (d[num[l]] < x) return l;
        return -1;
}

void dfs2(int v, int l, int r, int length = 0, double cur = 0.0)
{
	if (g[v].size() == 0)
	{
		for (int i = l; i <= r; i ++)
			res[num[i]] += cur;
		return ;
	}

	int a = g[v][0], b = g[v][1];
	int x = g_first(c[v]);
	int y = g_last(c[v]);
	if (x != -1 && x <= r) dfs2(b, max(x, l), r, length + 1, cur * (double)(length) / (double)(length + 1) + (double)(mx[a]) / (double)(length + 1));
	if (y != -1 && l <= y) dfs2(a, l, min(y, r), length + 1, cur * (double)(length) / (double)(length + 1) + (double)(mn[b]) / (double)(length + 1));
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d", &n);
	int root = 1;
	for (int i = 1; i <= n; i ++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		c[i] = v;
		if (u != -1)
			g[u].push_back(i); else root = i;
	}
	for (int i = 1; i <= n; i ++)
		if (g[i].size() != 0)
		{
			if (c[g[i][0]] > c[g[i][1]]) swap(g[i][0], g[i][1]);
		}
	scanf("%d", &m);
	for (int i = 1; i <= m; i ++)
		scanf("%d", &d[i]), num[i] = i;
	sort(num + 1, num + m + 1, comp);
	dfs(root);
	dfs2(root, 1, m);

	for (int i = 1; i <= m; i ++)
		printf("%.10lf\n", res[i]);
	return 0;
}