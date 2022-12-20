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
int xa[15], xb[15];
int ya[15], yb[15];
int get(const int &x, const int &y)
{
	if(xa[x] == ya[y] && xb[x] == yb[y])
		return 0;
	if(xa[x] == ya[y] || xa[x] == yb[y])
		return xa[x];
	else if(xb[x] == ya[y] || xb[x] == yb[y])
		return xb[x];
	else
		return 0;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		cin >> xa[i] >> xb[i];
		if(xa[i] > xb[i])
			swap(xa[i], xb[i]);
	}
	for(int i = 1; i <= m; i ++)
	{
		cin >> ya[i] >> yb[i];
		if(ya[i] > yb[i])
			swap(ya[i], yb[i]);
	}
	for(int i = 1; i <= n; i ++)
	{
		int v = 0;
		for(int j = 1; j <= m; j ++)
		{
			int now = get(i, j);
			if(!now)
				continue;
			if(v && now != v)
			{
				cout << -1 << endl;
				return 0;
			}
			v = now;
		}
	}
	for(int i = 1; i <= m; i ++)
	{
		int v = 0;
		for(int j = 1; j <= n; j ++)
		{
			int now = get(j, i);
			if(!now)
				continue;
			if(v && now != v)
			{
				cout << -1 << endl;
				return 0;
			}
			v = now;
		}
	}
	bool ok = 1;
	int ans = 0;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
		{
			int now = get(i, j);
			if(!now)
				continue;
			if(ans && now != ans)
				ok = 0;
			ans = now;
		}
	if(ok)
		cout << ans << endl;
	else
		cout << 0 << endl;
	
	return 0;
}