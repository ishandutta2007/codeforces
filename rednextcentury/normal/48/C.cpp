#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
using namespace std;
long double num;
bool a[1000001];
long double a1, a2;
int main()
{
	int n;
	cin >> n;
	int h;
	for (int i = 0; i < n; i++)
	{
		cin >> h;
		a[h] = 1;
	}
	long double l = 10.0;
	long double r = 1000000000;
	num = 1;
	for (int i = 1; i <= h; i++)
	{
		if (a[i])
		{
			r = min(r, (10 + i*10) / num);
			num++;
		}
		else
		{
			l = max(l, (10 + i * 10) / num);
		}
	}
	 a1 = (l * (num)-10 * h);
	a2 = (r * (num)-10 * h);
	a2-=0.0000001;

	if ((int)a1 / 10 == (int)a2 / 10)
		cout << "unique" << endl << h + (int)(a2) / 10;
	else
		cout << "not unique" << endl;
}