#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define long long long

using namespace std;

int main()
{
	x:
	bool debug = 0;
	long c, hr, hb, wr, wb;
	if (debug)
	{
		c = rand() % 10000 + 1;
		hr = rand() % 300 + 1;
		hb = rand() % 300 + 1;
		wr = rand() % 300 + 1;
		wb = rand() % 300 + 1;
	}
	else
		cin >> c >> hr >> hb >> wr >> wb;
	if (wr > wb)
	{
		swap(wr, wb);
		swap(hr, hb);
	}
 
	long maxx = -1;
	if (debug || wb <= 50000)
	{
		for (int x = c / wb; x >= 0 && x >= c / wb - wb * 3; --x)
		{
			maxx = max(maxx, hb * x + hr * ((c - wb * x) / wr));
		}
		for (int x = 0; x < 3 * wb + 5 && x <= c / wb; ++x)
		{
			maxx = max(maxx, hb * x + hr * ((c - wb * x) / wr));
		}
		cout << maxx << endl;
	}
	long maxx1 = -1;
	if (debug || wb > 50000)
	{
		for (int x = 0; x <= c / wb; ++x)
		{
			maxx1 = max(maxx1, hb * x + hr * ((c - wb * x) / wr));
		}
		cout << maxx1 << endl;
	}
	if (debug && maxx != maxx1)
	{
		cout << "!!!!!!! " << c << ' ' << hr << ' ' << hb << ' ' << wr << ' ' << wb << endl;
	}
	else if (debug)
	{
		goto x;
	}
}