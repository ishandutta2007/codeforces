#include <iostream>
using namespace std;

const int N = 100011;
const int M = 20;
typedef long long intl;

struct Point
{
	intl x, y;
	Point() { }
	Point(intl x, intl y) : x(x), y(y) { }
	Point operator -(Point rhs) { return Point(x - rhs.x, y - rhs.y); }
	intl cross(Point rhs)
	{
		return x * rhs.y - y * rhs.x;
	}
}h[N];

int depth[N];
int anc[N][M];
pair <Point, int> sta[N];
#define p first
#define t second

int lca(int u, int v)
{
	if(depth[u] > depth[v])
		swap(u, v);
	for(int i = M - 1; i >= 0; i --)
		if(depth[anc[v][i]] >= depth[u])
			v = anc[v][i];
	if(u == v)
		return u;
	for(int i = M - 1; i >= 0; i --)
		if(anc[u][i] != anc[v][i])
		{
			u = anc[u][i];
			v = anc[v][i];
		}
	return anc[u][0];
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> h[i].x >> h[i].y;

	int top = 1;
	sta[0] = {h[n], n};
	anc[n][0] = n;
	depth[n] = 0;
	for(int i = n - 1; i >= 1; i --)
	{
		int left = 0, right = top;
		while(left + 1 < right)
		{
			int mid = (left + right) / 2;
			if((sta[mid].p - sta[mid - 1].p).cross(h[i] - sta[mid - 1].p) < 0)
				right = mid;
			else
				left = mid;
		}
		anc[i][0] = sta[left].t;
		depth[i] = depth[sta[left].t] + 1;
		while(top > 1 && ((sta[top - 1].p - sta[top - 2].p).cross(h[i] - sta[top - 2].p)) < 0)
			top --;
		sta[top ++] = {h[i], i};
	}

	for(int j = 1; j < M; j ++)
		for(int i = 1; i <= n; i ++)
			anc[i][j] = anc[anc[i][j - 1]][j - 1];

	int m;
	cin >> m;
	while(m --)
	{
		int u, v;
		cin >> u >> v;
		cout << lca(u, v) << ' ';
	}
	cout << '\n';
	return 0;
}