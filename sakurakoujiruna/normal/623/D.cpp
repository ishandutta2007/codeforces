#include <iostream>
#include <iomanip>
using namespace std;

const int N = 101;
typedef long double doublel;

doublel p[N];
doublel q[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	doublel finish = 1;
	for(int i = 0; i < n; i ++)
	{
		cin >> p[i];
		p[i] /= 100;
		q[i] = 1 - p[i];
		finish *= 1 - q[i];
	}

	doublel ans = n;
	for(int t = 0; t < 500000; t ++)
	{
		doublel mc = 0;
		int id = 0;
		for(int i = 0; i < n; i ++)
		{
			doublel old = 1 - q[i];
			doublel now = 1 - q[i] * (1 - p[i]);
			if(now / old > mc)
			{
				mc = now / old;
				id = i;
			}
		}
		q[id] *= 1 - p[id];
		ans += 1 - finish;
		finish *= mc;
		if(q[id] < 1e-200)
			q[id] = 0;
	}

	cout << setprecision(12) << ans << '\n';
	return 0;
}