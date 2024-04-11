#include <iostream>
#include <cmath>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1511;
#define double long double
typedef long long intl;
struct Point
{
	int x, y;
	Point operator -(Point p) {
		return {x - p.x, y - p.y};
	}
	intl cross(Point p) {
		return (intl)x * p.y - (intl)y * p.x;
	}
	bool operator <(Point p) {
		return tie(x, y) < tie(p.x, p.y);
	}
	double arg() {
		return atan2l(y, x);
	}
}p[N];

vector <int> edges[N];

int size[N];
void dfs1(int cur, int last)
{
	size[cur] = 1;
	for(auto &v : edges[cur])
		if(v != last)
		{
			dfs1(v, cur);
			size[cur] += size[v];
		}
}

int ans[N];
Point o;
bool cmp(int a, int b) {
	//return (p[a] - o).arg() < (p[b] - o).arg();
	return (p[a] - o).cross(p[b] - o) < 0;
}
void dfs2(int cur, int last, int lid, vector <int> to_use)
{
	o = p[lid];
	ans[lid] = cur;
	sort(to_use.begin(), to_use.end(), cmp);
	int cnt = 0;
	for(auto &v : edges[cur])
		if(v != last)
		{
			vector <int> nxt;
			int nid = to_use[cnt ++];
			for(int i = 1; i < size[v]; i ++)
				nxt.push_back(to_use[cnt ++]);
			dfs2(v, cur, nid, nxt);
		}
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i < n; i ++)
	{
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	for(int i = 1; i <= n; i ++)
		cin >> p[i].x >> p[i].y;
	int t = 1;
	for(int i = 2; i <= n; i ++)
		if(p[i] < p[t])
			t = i;
	vector <int> v;
	for(int i = 1; i <= n; i ++)
		if(t != i)
			v.push_back(i);
	dfs1(1, -1);
	dfs2(1, -1, t, v);
	for(int i = 1; i <= n; i ++)
		cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}