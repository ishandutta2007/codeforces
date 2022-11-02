#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1011;
typedef long long intl;

struct Point
{
	intl x, y;
	Point operator -(Point p) {
		return {x - p.x, y - p.y};
	}
	intl length2() {
		return x * x + y * y;
	}
}p[N];
int k[N];

struct Circle
{
	Point o;
	intl r;
	bool operator <(Circle c) const {
		return r > c.r;
	}
}c[N];

int d[N][N];
vector <int> edges[N];
void dfs(int cur, int last, int root, int dis)
{
	d[root][cur] = dis;
	for(int &v : edges[cur])
		if(v != last)
			dfs(v, cur, root, dis + 1);
}

int main()
{
	ios :: sync_with_stdio(false);
	int n, m, q;
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i ++)
		cin >> p[i].x >> p[i].y;
	for(int i = 1; i <= m; i ++)
		cin >> c[i].r >> c[i].o.x >> c[i].o.y;

	sort(c + 1, c + m + 1);
	for(int i = 1; i <= m; i ++)
	{
		int pnt = 0;
		for(int j = i - 1; j >= 1; j --)
			if((c[i].o - c[j].o).length2() <= c[j].r * c[j].r)
			{
				pnt = j;
				break;
			}
		edges[i].push_back(pnt);
		edges[pnt].push_back(i);
	}
	for(int i = 1; i <= n; i ++)
		for(int j = m; j >= 1; j --)
			if((p[i] - c[j].o).length2() <= c[j].r * c[j].r)
			{
				k[i] = j;
				break;
			}
	for(int i = 0; i <= m; i ++)
		dfs(i, -1, i, 0);

	while(q --)
	{
		int u, v;
		cin >> u >> v;
		cout << d[k[u]][k[v]] << '\n';
	}
	return 0;
}