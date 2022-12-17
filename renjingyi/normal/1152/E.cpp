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
int d[maxn];
void adde(const int &a, const int &b)
{
	te ++;
	edges[te].to = b;
	d[b] ++;
	edges[te].next = points[a];
	points[a] = te;
}
int b[maxn], c[maxn];
map<int, int> id;
int v[maxn];
vector<int> ans;
bool mark[maxn << 1];
void eular(const int &p)
{
	for(int &e = points[p]; e; e = edges[e].next)
		if(!mark[e])
		{
			mark[e] = mark[e ^ 1] = 1;
			eular(edges[e].to);
		}
	ans.push_back(p);
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i < n; i ++)
	{
		cin >> b[i];
		id[b[i]] = 1;
	}
	for(int i = 1; i < n; i ++)
	{
		cin >> c[i];
		id[c[i]] = 1;
	}
	for(int i = 1; i < n; i ++)
		if(b[i] > c[i])
		{
			cout << -1 << endl;
			return 0;
		}
	int tot = 0;
	for(map<int, int>::iterator it = id.begin(); it != id.end(); it ++)
	{
		it->second = ++ tot;
		v[tot] = it->first;
	}
	for(int i = 1; i < n; i ++)
	{
		b[i] = id[b[i]];
		c[i] = id[c[i]];
		adde(b[i], c[i]);
		adde(c[i], b[i]);
	}
	int cnt = 0, pos = 1;
	for(int i = 1; i <= tot; i ++)
		if(d[i] & 1)
		{
			cnt ++;
			pos = i;
		}
	if(cnt > 2)
	{
		cout << -1 << endl;
		return 0;
	}
	eular(pos);
	if(ans.size() != n)
	{
		cout << -1 << endl;
		return 0;
	}
	for(int i = 0; i < n; i ++)
		cout << v[ans[i]] << " ";
	cout << endl;
	
	return 0;
}