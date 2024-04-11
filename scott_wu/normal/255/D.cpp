#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;

ll N, X, Y, C;
ll xd[2], yd[2];
ll dlist[4];

ll solve (ll d)
{
	ll res = d * d + (d + 1) * (d + 1);
	for (int i = 0; i < 4; i++)
	{
		if (d >= dlist[i])
		{
			res -= (d - dlist[i] + 1) * (d - dlist[i] + 1);
		}
	}
	
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			if (xd[i] + yd[j] <= d)
			{
				ll wid = d - xd[i] - yd[j] + 1;
				res += (wid * (wid + 1)) / 2;
			}
		}
	return res;
}

int main()
{
	cin >> N >> X >> Y >> C;
	xd[0] = X; xd[1] = N - X + 1;
	yd[0] = Y; yd[1] = N - Y + 1;
	dlist[0] = xd[0]; dlist[1] = xd[1];
	dlist[2] = yd[0]; dlist[3] = yd[1];
	
	for (ll i = 0; i < 1000000; i++)
		if (solve (i) >= C)
		{
			cout << i << "\n";
			return 0;
		}
	return 0;
}