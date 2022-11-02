#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <cstring>
#include <bitset>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int a[10], b[10], c[10];
int d[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check(int day, int m, int y)
{
	bool vis = (y % 4 == 0);
	if (m == 2) d[2] += vis;
	bool good = true;
	if (!(y >= 1 && y <= 99)) good = false;
	if (!(m >= 1 && m <= 12)) good = false;
	if (!(day >= 1 && day <= d[m])) good = false;
	if (m == 2) d[2] -= vis;
	return good;
}

bool check()
{
	int d1 = a[1];
	int m1 = a[2];
	int y1 = a[3];

	int d2 = c[1];
	int m2 = c[2];
	int y2 = c[3];

	if (!check(d2, m2, y2)) return false;

	if (y1 - y2 > 18) return true;
	if (y1 - y2 == 18)
	{
		if (m2 != 2)
		{
			if (m1 > m2) return true;
			if (m1 == m2 && d1 >= d2) return true;
			return false;
		} else
		{
			if (m1 > m2) return true;
			if (m1 == m2 && d1 >= d2) return true;
			return false;
		}
	}
	return false;
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d.%d.%d", &a[1], &a[2], &a[3]);
	scanf("%d.%d.%d", &c[1], &c[2], &c[3]);

	sort(c + 1, c + 4);

	do
	{
		if (check())
		{
			cout << "YES" << endl;
			return 0;
		}
	} while (next_permutation(c + 1, c + 4));

	cout << "NO" << endl;
	
	return 0;
}