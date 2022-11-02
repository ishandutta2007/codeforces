#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

struct Point
{
	int x, y;
	Point operator -(Point p) {
		return {x - p.x, y - p.y};
	}
	int dot(Point p) {
		return x * p.x + y * p.y;
	}
	int length2() {
		return x * x + y * y;
	}
}p[8];

int q[4];
bool check(vector <Point> v, bool sq = false)
{
	iota(q, q + 4, 0);
	do
	{
		bool flag = true;
		for(int i = 0; i < 4; i ++)
			flag &= ((v[q[(i + 1) % 4]] - v[q[i]]).dot(v[q[(i + 2) % 4]] - v[q[(i + 1) % 4]]) == 0);
		if(sq && (v[q[0]] - v[q[1]]).length2() != (v[q[2]] - v[q[1]]).length2())
			flag = false;
		if(flag)
			return true;
	}while(next_permutation(q + 1, q + 4));
	return false;
}

int main()
{
	ios :: sync_with_stdio(false);
	for(int i = 0; i < 8; i ++)
		cin >> p[i].x >> p[i].y;
	for(int k = 0; k < (1 << 8); k ++)
		if(__builtin_popcount(k) == 4)
		{
			vector <Point> v1, v2;
			for(int i = 0; i < 8; i ++)
				if((k >> i) & 1)
					v1.push_back(p[i]);
				else
					v2.push_back(p[i]);
			if(check(v1, true) && check(v2))
			{
				cout << "YES\n";
				for(int i = 0; i < 8; i ++)
					if((k >> i) & 1)
						cout << i + 1 << ' ';
				cout << '\n';
				for(int i = 0; i < 8; i ++)
					if(((k >> i) & 1) == 0)
						cout << i + 1 << ' ';
				cout << '\n';
				return 0;
			}
		}
	cout << "NO\n";
	return 0;
}