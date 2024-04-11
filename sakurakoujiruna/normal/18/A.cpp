#include <iostream>
using namespace std;

struct Point
{
	int x, y;
	Point operator -(Point p) {
		return {x - p.x, y - p.y};
	}
	Point operator +(Point p) {
		return {x + p.x, y + p.y};
	}
	int dot(Point p) {
		return x * p.x + y * p.y;
	}
	int cross(Point p) {
		return x * p.y - y * p.x;
	}
}p[3];

Point d[5] = {
	{0, 0},
	{1, 0},
	{0, 1},
	{-1, 0},
	{0, -1}
};

string str[3] = {
	"NEITHER",
	"ALMOST",
	"RIGHT"
};

int main()
{
	ios :: sync_with_stdio(false);
	for(int i = 0; i < 3; i ++)
		cin >> p[i].x >> p[i].y;

	int ans = 0;
	for(int i = 0; i < 3; i ++)
		for(int j = 0; j < 5; j ++)
		{
			p[i] = p[i] + d[j];
			for(int k = 0; k < 3; k ++)
			{
				Point p1 = p[(k + 1) % 3] - p[k];
				Point p2 = p[(k + 2) % 3] - p[k];
				if(p1.cross(p2) != 0 && p1.dot(p2) == 0)
				{
					if(j == 0)
						ans = max(ans, 2);
					else
						ans = max(ans, 1);
				}
			}
			p[i] = p[i] - d[j];
		}
	cout << str[ans] << '\n';
	return 0;
}