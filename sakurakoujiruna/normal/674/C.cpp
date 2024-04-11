#include <bits/stdc++.h>
using namespace std;

const int N = 200011;
const int K = 53;
const double Eps = 1e-8;
int sgn(double a, double b = 0)
{
	a -= b;
	return (a > Eps) - (a < -Eps);
}

struct Point
{
	double x, y;
	Point operator -(Point p) {
		return {x - p.x, y - p.y};
	}
	double cross(Point p) {
		return x * p.y - y * p.x;
	}
	double y_inter(double k) {
		return -k * x + y;
	}
};

double xmul(Point a, Point b, Point c)
{
	return (b - a).cross(c - a);
}

int t[N];
double ps[N], s[N];

int hd[K], tl[K];
Point q[K][N];
double dp[K][N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		cin >> t[i];
	ps[0] = s[0] = 0;
	for(int i = 1; i <= n; i ++)
	{
		s[i] = s[i - 1] + t[i];
		ps[i] = ps[i - 1] + 1.0 / t[i];
	}
	double ans = 0;
	for(int i = 1; i <= n; i ++)
		ans += s[i] / t[i];
	q[0][tl[0] ++] = {0, 0};
	for(int i = 1; i <= n; i ++)
	{
		for(int k = min(i, m); k >= 1; k --)
		{
			while(hd[k - 1] + 1 < tl[k - 1] &&
				q[k - 1][hd[k - 1] + 1].y_inter(-ps[i]) > q[k - 1][hd[k - 1]].y_inter(-ps[i]))
				hd[k - 1] ++;
			dp[k][i] = q[k - 1][hd[k - 1]].y_inter(-ps[i]);
			Point nxt = {s[i], dp[k][i] - ps[i] * s[i]};
			while(hd[k] + 1 < tl[k] &&
				xmul(q[k][tl[k] - 2], nxt, q[k][tl[k] - 1]) <= 0)
				tl[k] --;
			q[k][tl[k] ++] = nxt;
		}
	}
	cout << setprecision(6) << ans - dp[m][n] << '\n';
	return 0;
}