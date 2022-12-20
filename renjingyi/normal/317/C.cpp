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
const int maxn = 305, maxm = 5e4 + 5;
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
int par[maxn];
int getp(const int &x)
{
	if(par[x] == x)
		return par[x];
	return par[x] = getp(par[x]);
}
int du[maxn];
vector<int> asd;
int a[maxn], b[maxn];
bool mark[maxn];
long long tota = 0, totb = 0;
void check(const int &p)
{
	mark[p] = 1;
	tota += a[p];
	totb += b[p];
	for(int e = points[p]; e; e = edges[e].next)
		if(!mark[edges[e].to])
			check(edges[e].to);
}
vector<pp> ans;
vector<int> d;
int n, v, e;
void work1(const int &p, const int &fa, int &diff)
{
	if(!diff)
		return;
	if(a[p] >= diff)
	{
		ans.push_back(mp(p, fa));
		d.push_back(diff);
		a[p] -= diff;
		diff = 0;
		return;
	}
	int now = diff;
	diff -= a[p];
	a[p] = 0;
	for(int e = points[p]; e; e = edges[e].next)
		if(!mark[edges[e].to] && edges[e].to != fa)
			work1(edges[e].to, p, diff);
	if(now > diff)
	{
		ans.push_back(mp(p, fa));
		d.push_back(now - diff);
	}
}
void work2(const int &p, const int &fa, int &diff)
{
	if(!diff)
		return;
	if(a[p] - diff <= v)
	{
		ans.push_back(mp(fa, p));
		d.push_back(-diff);
		a[p] -= diff;
		diff = 0;
		return;
	}
	int now = diff;
	diff += v - a[p];
	a[p] = v;
	for(int e = points[p]; e; e = edges[e].next)
		if(!mark[edges[e].to] && edges[e].to != fa)
			work2(edges[e].to, p, diff);
	if(now < diff)
	{
		ans.push_back(mp(fa, p));
		d.push_back(diff - now);
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> v >> e;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	for(int i = 1; i <= n; i ++)
		cin >> b[i];
	for(int i = 1; i <= n; i ++)
		par[i] = i;
	for(int i = 1; i <= e; i ++)
	{
		int x, y;
		cin >> x >> y;
		if(getp(x) == getp(y))
			continue;
		adde(x, y);
		adde(y, x);
		du[x] ++;
		du[y] ++;
		par[par[x]] = par[y];
	}
	for(int i = 1; i <= n; i ++)
		if(!mark[i])
		{
			tota = totb = 0;
			check(i);
			if(tota != totb)
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	queue<int> q;
	for(int i = 1; i <= n; i ++)
		if(du[i] == 1)
			q.push(i);
	while(!q.empty())
	{
		int now = q.front();
		asd.push_back(now);
		q.pop();
		for(int e = points[now]; e; e = edges[e].next)
			if(-- du[edges[e].to] == 1)
				q.push(edges[e].to);
	}
	for(int i = 1; i <= n; i ++)
		mark[i] = 0;
	for(int i = 0; i < asd.size(); i ++)
	{
		int diff = b[asd[i]] - a[asd[i]];
		for(int e = points[asd[i]]; e; e = edges[e].next)
			if(!mark[edges[e].to])
			{
				if(diff > 0)
					work1(edges[e].to, asd[i], diff);
				if(diff < 0)
					work2(edges[e].to, asd[i], diff);
			}
		mark[asd[i]] = 1;
	}
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i ++)
		cout << ans[i].first << " " << ans[i].second << " " << d[i] << endl;
	
	return 0;
}