#include <iostream>
using namespace std;

const int N = 100011;
typedef long long intl;

struct Point
{
	intl x, y;
	Point operator -(Point p) {
		return {x - p.x, y - p.y};
	}
	Point operator *(intl n) {
		return {x * n, y * n};
	}
}p[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	intl m;
	cin >> n >> m;
	m %= 2 * n;
	Point q;
	cin >> q.x >> q.y;
	for(int i = 0; i < n; i ++)
		cin >> p[i].x >> p[i].y;
	for(int i = 0; i < m; i ++)
		q = p[i % n] * 2 - q;
	cout << q.x << ' ' << q.y << '\n';
	return 0;
}