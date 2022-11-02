#include <bits/stdc++.h>
using namespace std;

struct Point
{
	double x, y;
	Point operator -(Point p) {
		return {x - p.x, y - p.y};
	}
	Point operator +(Point p) {
		return {x + p.x, y + p.y};
	}
	Point operator *(double d) {
		return {x * d, y * d};
	}
};

int main()
{
	Point p[6] = {
		{0, 0},
		{3.830127018922193, 3.366025403784439},
		{-3.601321235851749, 10.057331467373021},
		{0.466045194906253, 19.192786043799030},
		{10.411264148588986, 18.147501411122495},
		{12.490381056766580, 8.366025403784439}
	};

	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	cout << 4 * n + 1 << '\n';
	cout << fixed << setprecision(12);
	cout << p[1].x << ' ' << p[1].y << '\n';
	for(int i = 1; i <= n; i ++)
	{
		Point shift = (p[3] - p[1]) * (i - 1);
		for(int j = 2; j <= 5; j ++)
		{
			Point q = p[j] + shift;
			cout << q.x << ' ' << q.y << '\n';
		}
	}
	cout << "1 2 3 4 5\n";
	for(int i = 2; i <= n; i ++)
		cout << i * 4 - 5 << ' ' <<
			i * 4 - 2 << ' ' <<
			i * 4 - 1 << ' ' <<
			i * 4 << ' ' <<
			i * 4 + 1 << '\n';
	
	cout << 1;
	for(int i = 1; i <= n; i ++)
		cout << ' ' << i * 4 - 1;
	for(int i = n; i >= 2; i --)
		cout << ' ' << i * 4 + 1 <<
			' ' << i * 4 - 2 <<
			' ' << i * 4 <<
			' ' << i * 4 - 5;
	cout << " 5 2 4 1\n";
	return 0;
}