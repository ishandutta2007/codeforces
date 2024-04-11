#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <time.h>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

struct edge {int u, v, w, num;};
bool comp(edge A, edge B) {return A.w < B.w;}

int n;
vector < pair < int, int > > g[110000];
edge e[110000];
int used[110000];
int p[110000];
int cs[110000];

long long res[110000];

int find_set(int v)
{
	if (p[v] == v) return v;
	int x = find_set(p[v]);
	p[v] = x;
	return x;
}

void up(int x, int y)
{
	int u = find_set(x), v = find_set(y);
	if (rand() % 2)
	{
		p[v] = u;
		cs[u] += cs[v];
	} else
	{
		p[u] = v;
		cs[v] += cs[u];
	}
}

vector < int > ng[110000];
vector < int > ans;

int pd[110000];
int ver[110000], num[110000], cur = 0, vr = 0;
int in[110000], t;

void dfs(int v)
{
	if (used[v]) return ;
	used[v] = true;
	pd[v] = cs[find_set(v)];
	ver[v] = cur;
	vr += pd[v];
	t ++;
	in[v] = t;
	for (int i = 0; i < ng[v].size(); i ++)
		if (!used[ng[v][i]])
		{
			dfs(ng[v][i]);
			pd[v] += pd[ng[v][i]];
		}
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	srand(time(0));
	scanf("%d", &n);
	for (int i = 1; i < n; i ++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
		e[i].u = u, e[i].v = v, e[i].w = w, e[i].num = i;
	}
	for (int i = 1; i <= n; i ++)
		p[i] = i, cs[i] = 1;

	sort(e + 1, e + n, comp);

	for (int i = 1; i < n; i ++)
	{
		int x = i;
		for (int j = i; j < n; j ++)
			if (e[j].w == e[i].w) x = j; else break;
		for (int j = i; j <= x; j ++)
		{
			int u = find_set(e[j].u), v = find_set(e[j].v);
			ng[u].clear(), ng[v].clear();
			pd[u] = pd[v] = 0;
			used[u] = used[v] = 0;
		}

		for (int j = i; j <= x; j ++)
		{
			int u = find_set(e[j].u), v = find_set(e[j].v);
			ng[u].push_back(v);
			ng[v].push_back(u);
		}

		cur = 0;
		for (int j = i; j <= x; j ++)
		{
			int u = find_set(e[j].u), v = find_set(e[j].v);
			if (!used[u])
			{
				cur ++;
				vr = t = 0;
				dfs(u);
				num[cur] = vr;
			}
		}

		for (int j = i; j <= x; j ++)
		{
			int u = find_set(e[j].u), v = find_set(e[j].v);
			long long A = num[ver[u]];
			long long B;
			if (in[u] > in[v]) B = pd[u]; else B = pd[v];
			res[e[j].num] = (long long)(A - B) * (long long)(B);
		}

		for (int j = i; j <= x; j ++)
			up(e[j].u, e[j].v);

		i = x;
	}

	long long mx = 0;
	for (int i = 1; i < n; i ++)
		if (res[i] > mx) mx = res[i];

	for (int i = 1; i < n; i ++)
		if (res[i] == mx) ans.push_back(i);


	cout << mx + mx << " " << ans.size() << endl;
	for (int i = 0; i < ans.size(); i ++)
		printf("%d ", ans[i]);
	printf("\n");


	return 0;
}