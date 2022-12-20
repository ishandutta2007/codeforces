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
const int maxn = 1005, maxm = 1e5 + 5;
const int oo = 1e9;
struct Edge
{
	int to, next;
}edges[2 * maxm];
int te = 1;
int points[maxn];
void adde(const int &a, const int &b)
{
	te ++;
	edges[te].to = b;
	edges[te].next = points[a];
	points[a] = te;
}
int d[maxn][2];
bool mark[maxn][2];
void Dijkstra(const int &s, const int &n, const int &pos)
{
	for(int i = 1; i <= n; i ++)
		d[i][pos] = oo;
	d[s][pos] = 0;
	priority_queue<pp, vector<pp>, greater<pp> > q;
	q.push(mp(0, s));
	while(!q.empty())
	{
		pp p = q.top();
		q.pop();
		if(mark[p.second][pos])
			continue;
		mark[p.second][pos] = 1;
		for(int e = points[p.second]; e; e = edges[e].next)
			if(d[edges[e].to][pos] > p.first + 1)
			{
				d[edges[e].to][pos] = p.first + 1;
				q.push(mp(d[edges[e].to][pos], edges[e].to));
			}
	}
}
bool connect[maxn][maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	for(int i = 1; i <= m; i ++)
	{
		int a, b;
		cin >> a >> b;
		adde(a, b);
		adde(b, a);
		connect[a][b] = connect[b][a] = 1;
	}
	Dijkstra(s, n, 0);
	Dijkstra(t, n, 1);
	int ans = 0;
	for(int i = 1; i < n; i ++)
		for(int j = i + 1; j <= n; j ++)
			if(!connect[i][j] && min(d[i][0] + 1 + d[j][1], d[j][0] + 1 + d[i][1]) >= d[t][0])
				ans ++;
	cout << ans << endl;
	
	return 0;
}