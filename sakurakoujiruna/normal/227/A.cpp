#include <iostream>
using namespace std;

typedef long long intl;

int sgn(intl n)
{
	return (n > 0) - (n < 0);
}

struct Point
{
	intl x, y;
	Point operator -(Point rhs) const {
		return {x - rhs.x, y - rhs.y};
	}
	intl cross(Point rhs) {
		return x * rhs.y - y * rhs.x;
	}
};

string str[3] = {"RIGHT", "TOWARDS", "LEFT"};

int main()
{
	ios :: sync_with_stdio(false);
	Point a, b, c;
	cin >> a.x >> a.y;
	cin >> b.x >> b.y;
	cin >> c.x >> c.y;
	cout << str[sgn((b - a).cross(c - b)) + 1] << '\n';
	return 0;
}