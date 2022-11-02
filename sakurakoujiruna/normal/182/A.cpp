#include <bits/stdc++.h>
using namespace std;

const int N = 1011;
const double Eps = 1e-8;
int sgn(double a, double b = 0)
{
	a -= b;
	return (a > Eps) - (a < -Eps);
}

struct Point
{
	int x, y;
	Point operator -(Point p) {
		return {x - p.x, y - p.y};
	}
	int cross(Point p) {
		return x * p.y - y * p.x;
	}
	int dot(Point p) {
		return x * p.x + y * p.y;
	}
	double len() {
		return sqrt(x * x + y * y);
	}
	double dis(Point p, Point q)
	{
		if((*this - p).dot(q - p) > 0 &&
			(*this - q).dot(p - q) > 0)
			return abs((p - *this).cross(q - *this)) / (p - q).len();
		return min((*this - p).len(), (*this - q).len());
	}
}p[N][2];
double dis[N][N];

int step[N];

int main()
{
	ios :: sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	cin >> p[0][0].x >> p[0][0].y;
	int sx, sy;
	cin >> sx >> sy;
	int n;
	cin >> n;
	p[n + 1][0] = {sx, sy};
	for(int i = 1; i <= n; i ++)
	{
		cin >> p[i][0].x >> p[i][0].y;
		cin >> p[i][1].x >> p[i][1].y;
	}
	
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			dis[i][j] = min({p[i][0].dis(p[j][0], p[j][1]),
						p[i][1].dis(p[j][0], p[j][1]),
						p[j][0].dis(p[i][0], p[i][1]),
						p[j][1].dis(p[i][0], p[i][1])});

	for(int i = 1; i <= n; i ++)
	{
		dis[i][0] = dis[0][i] = p[0][0].dis(p[i][0], p[i][1]);
		dis[i][n + 1] = dis[n + 1][i] = p[n + 1][0].dis(p[i][0], p[i][1]);
	}
	dis[0][n + 1] = dis[n + 1][0] = (p[0][0] - p[n + 1][0]).len();

	bool can = false;
	double ans = 1e9;
	memset(step, -1, sizeof(step));
	step[0] = 0;
	queue <int> q;
	q.push(0);
	while(!q.empty())
	{
		int c = q.front();
		q.pop();
		if(sgn(dis[c][n + 1], a) <= 0)
		{
			can = true;
			ans = min(ans, step[c] * (a + b) + dis[c][n + 1]);
		}
		for(int i = 0; i <= n + 1; i ++)
			if(sgn(dis[c][i], a) <= 0 && step[i] == -1)
			{
				step[i] = step[c] + 1;
				q.push(i);
			}
	}

	if(can)
		cout << setprecision(6) << ans << '\n';
	else
		cout << -1 << '\n';
	return 0;
}