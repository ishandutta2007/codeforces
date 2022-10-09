#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int maxn = 200;

bool used[maxn];
int next[maxn], first[maxn], last[maxn], edge[maxn];


int n, m, cnt;

void add(int v, int u)
{
	edge[cnt] = u;
	if (first[v] == -1)
		first[v] = cnt;
	else
		next[last[v]] = cnt;
	last[v] = cnt;
	next[last[v]] = -1;
	cnt++;
}

int dfs(int v, int &r)
{
	used[v] = true;
	int ed = first[v];
	int res = 0;
	r = v;
	while (ed != -1)
	{
		int u = edge[ed];
		if (used[u])
		{
			ed = next[ed];
			continue;
		}
		int w;
		int d = dfs(u, w) + 1;
		if (d > res)
		{
			r = w;
			res = d;
		}
		ed = next[ed];
	}
	return res;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		cnt = 0;
		for (int i = 0; i < maxn; i++)
		{
			used[i] = false;
			first[i] = last[i] = -1;
		}
		for (int j = 1; j < m; j++)
		{
			int v, u;
			cin >> v >> u;
			add(v, u);
			add(u, v);
		}
		int v;
		int d = dfs(1, v);
		for (int i = 0; i < maxn; i++)
			used[i] = false;
		int u;
		d = dfs(v, u);
		ans += d;

	}
	cout << ans;

    return 0;
}