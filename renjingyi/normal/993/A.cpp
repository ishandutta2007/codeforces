#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <complex>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const int oo = 1e9;
bool in(const int &x, const int &y, const int &x1, const int &y1, const int &x2, const int &y2)
{
	return x >= x1 && x <= x2 && y >= y1 && y <= y2;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int x1 = oo, y1 = oo, x2 = -oo, y2 = -oo;
	for(int i = 1; i <= 4; i ++)
	{
		int x, y;
		cin >> x >> y;
		x1 = min(x1, x);
		x2 = max(x2, x);
		y1 = min(y1, y);
		y2 = max(y2, y);
	}
	int x3 = oo, y3 = oo, x4 = -oo, y4 = -oo;
	for(int i = 1; i <= 4; i ++)
	{
		int x, y;
		cin >> x >> y;
		x3 = min(x3, x);
		x4 = max(x4, x);
		y3 = min(y3, y);
		y4 = max(y4, y);
	}
	for(int dy = 0; dy <= (y4 - y3) >> 1; dy ++)
		for(int dx = 0; dx <= dy; dx ++)
			if(in(x3 + dy, (y3 + y4) / 2 + dx, x1, y1, x2, y2) || in(x3 + dy, (y3 + y4) / 2 - dx, x1, y1, x2, y2) || in(x4 - dy, (y3 + y4) / 2 + dx, x1, y1, x2, y2) || in(x4 - dy, (y3 + y4) / 2 - dx, x1, y1, x2, y2))
			{
				cout << "YES" << endl;
				return 0;
			}
	cout << "NO" << endl;
	
	return 0;
}