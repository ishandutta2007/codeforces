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
const int maxn = 5005;
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
int p[maxn], c[maxn], k[maxn], ans[maxn];
bool mark[maxn], vis[maxn];
int match = 0, cnt = 0;
int par[maxn];
int n, m;
bool hungary(const int &x)
{
	if(vis[x])
		return 0;
	vis[x] = 1;
	for(int e = points[x]; e; e = edges[e].next)
	{
		int to = edges[e].to;
		if(par[to] == -1 || hungary(par[to]))
		{
			par[to] = x;
			return 1;
		}
	}
	return 0;
}
void work(const int &x)
{
	for(int i = 0; i <= match; i ++)
		vis[i] = 0;
	while(hungary(match))
	{
		match ++;
		for(int i = 0; i <= match; i ++)
			vis[i] = 0;
	}
	adde(p[x], c[x]);
	ans[cnt --] = match;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		cin >> p[i];
	for(int i = 1; i <= n; i ++)
		cin >> c[i];
	memset(par, -1, sizeof(par));
	int d;
	cin >> d;
	for(int i = 1; i <= d; i ++)
	{
		cin >> k[i];
		mark[k[i]] = 1;
	}
	cnt = n;
	for(int i = 1; i <= n; i ++)
		if(!mark[i])
			work(i);
	for(int i = d; i >= 1; i --)
		work(k[i]);
	for(int i = 1; i <= d; i ++)
		cout << ans[i] << endl;
	
	return 0;
}