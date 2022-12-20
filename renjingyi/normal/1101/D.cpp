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
vector<int> prime;
bool mark[maxn];
int to[maxn], pos[maxn];
int a[maxn];
int par[maxn];
vector<int> con[maxn];
void init(const int &p)
{
	while(a[p] != 1)
	{
		int now = to[a[p]];
		con[pos[now]].push_back(p);
		while(a[p] % now == 0)
			a[p] /= now;
	}
	for(int e = points[p]; e; e = edges[e].next)
		if(edges[e].to != par[p])
		{
			par[edges[e].to] = p;
			init(edges[e].to);
		}
}
int mx1[maxn], mx2[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	for(int i = 2; i <= 200000; i ++)
	{
		if(!mark[i])
		{
			pos[i] = prime.size();
			prime.push_back(i);
			to[i] = i;
		}
		for(int j = 0; j < prime.size() && i * prime[j] <= 200000; j ++)
		{
			mark[i * prime[j]] = 1;
			to[i * prime[j]] = prime[j];
			if(i % prime[j] == 0)
				break;
		}
	}
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	for(int i = 1; i < n; i ++)
	{
		int x, y;
		cin >> x >> y;
		adde(x, y);
		adde(y, x);
	}
	init(1);
	for(int i = 1; i <= n; i ++)
		mark[i] = 0;
	int ans = 0;
	for(int i = 0; i < prime.size(); i ++)
	{
		for(int j = 0; j < con[i].size(); j ++)
		{
			mark[con[i][j]] = 1;
			mx1[con[i][j]] = mx2[con[i][j]] = 0;
		}
		for(int j = (int)con[i].size() - 1; j >= 0; j --)
		{
			int tmp = con[i][j];
			mx1[tmp] ++;
			ans = max(ans, mx1[tmp] + mx2[tmp]);
			if(mark[par[tmp]])
			{
				if(mx1[tmp] > mx1[par[tmp]])
				{
					mx2[par[tmp]] = mx1[par[tmp]];
					mx1[par[tmp]] = mx1[tmp];
				}
				else if(mx1[tmp] > mx2[par[tmp]])
					mx2[par[tmp]] = mx1[tmp];
			}
		}
		for(int j = 0; j < con[i].size(); j ++)
			mark[con[i][j]] = 0;
	}
	cout << ans << endl;
	
	return 0;
}