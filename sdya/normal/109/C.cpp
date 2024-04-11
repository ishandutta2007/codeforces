#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <string.h>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <algorithm>
#include <queue>

using namespace std;

int n;
vector < int > g[110000];
int used[110000], res;

bool good(int x)
{
	while (x)
	{
		if (x % 10 != 4 && x % 10 != 7) return 0;
		x /= 10;
	}
	return 1;
}

void dfs(int v)
{
	if (used[v]) return ;
	used[v] = true;
	res ++;

	for (int i = 0; i < g[v].size(); i ++)
		dfs(g[v][i]);
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d", &n);
	for (int i = 1; i < n; i ++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		if (!good(w)) g[u].push_back(v), g[v].push_back(u);
	}

	long long m = n;
	long long ans = m * (m - 1LL) * (m - 2LL);
	for (int i = 1; i <= n; i ++)
		if (!used[i])
		{
			res = 0;
			dfs(i);
			long long x = res;
			ans -= 2LL * x * (x - 1LL) * (m - x);
			ans -= x * (x - 1LL) * (x - 2LL);
		}
	cout << ans << endl;
	return 0;
}