#include <iostream>
using namespace std;

const int N = 100011;
typedef long long intl;
#define double long double

struct Point
{
	intl x, y;
	Point operator -(Point p) {
		return {x - p.x, y - p.y};
	}
	double cross(Point p) {
		return (double)x * p.y - (double)y * p.x;
	}
	intl y_inter(intl k) {
		return -k * x + y;
	}
}p[N];

intl a[N], b[N];
intl dp[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	for(int i = 1; i <= n; i ++)
		cin >> b[i];

	int l = 0, r = 1;
	p[0] = {-b[1], 0};
	for(int i = 2; i <= n; i ++)
	{
		while(l + 1 < r &&
			p[l].y_inter(a[i]) > p[l + 1].y_inter(a[i]))
			l ++;
		dp[i] = p[l].y_inter(a[i]);
		while(l + 1 < r &&
			(p[r - 1] - p[r - 2]).cross(Point{-b[i], dp[i]} - p[r - 1]) < 0)
			r --;
		p[r ++] = {-b[i], dp[i]};
	}

	cout << dp[n] << '\n';
	return 0;
}