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
typedef pair<int, int> pp;
const int maxn = 3e5 + 5;
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
int d[maxn];
int st[maxn], ed[maxn];
int pos[maxn];
int dfscnt = 0;
vector<pp> v[maxn];
void set_tree(const int &p, const int &fa)
{
	st[p] = ++ dfscnt;
	pos[p] = v[d[p]].size();
	v[d[p]].push_back(mp(st[p], p));
	for(int e = points[p]; e; e = edges[e].next)
		if(edges[e].to != fa)
		{
			d[edges[e].to] = d[p] + 1;
			set_tree(edges[e].to, p);
		}
	ed[p] = dfscnt;
}
long long add[maxn];
vector<long long> add2[maxn];
long long ans[maxn];
void work(const int &p, const int &fa)
{
	if(pos[p] > 0)
		add2[d[p]][pos[p]] += add2[d[p]][pos[p] - 1];
	add[st[p]] += add[st[p] - 1] + add2[d[p]][pos[p]];
	ans[p] = add[st[p]]	;
	for(int e = points[p]; e; e = edges[e].next)
		if(edges[e].to != fa)
			work(edges[e].to, p);
	add[ed[p]] -= add2[d[p]][pos[p]];
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i < n; i ++)
	{
		int x, y;
		cin >> x >> y;
		adde(x, y);
		adde(y, x);
	}
	set_tree(1, 0);
	for(int i = 0; i < n; i ++)
		add2[i].resize(v[i].size() + 1);
	int m;
	cin >> m;
	for(int i = 1; i <= m; i ++)
	{
		int p, dis;
		long long x;
		cin >> p >> dis >> x;
		add[st[p]] += x;
		add[ed[p] + 1] -= x;
		int tmp = d[p] + dis + 1;
		if(tmp >= n)
			continue;
		int p1 = lower_bound(v[tmp].begin(), v[tmp].end(), mp(st[p], 0)) - v[tmp].begin(), p2 = upper_bound(v[tmp].begin(), v[tmp].end(), mp(ed[p], n)) - v[tmp].begin();
		if(p1 < p2)
		{
			add2[tmp][p1] -= x;
			add2[tmp][p2] += x;
		}
	}
	work(1, 0);
	for(int i = 1; i <= n; i ++)
		cout << ans[i] << " ";
	cout << endl;
	
	return 0;
}