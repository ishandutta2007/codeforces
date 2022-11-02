#include <iostream>
using namespace std;

const int N = 1011;

struct Point
{
	int x, y;
	Point operator -(Point rhs) {
		return {x - rhs.x, y - rhs.y};
	}
	int cross(Point rhs) {
		return x * rhs.y - y * rhs.x;
	}
}p[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i <= n; i ++)
		cin >> p[i].x >> p[i].y;
	p[n + 1] = p[1];
	int ans = 0;
	for(int i = 1; i <= n; i ++)
		ans += ((p[i] - p[i - 1]).cross(p[i + 1] - p[i]) > 0);
	cout << ans << '\n';
	return 0;
}