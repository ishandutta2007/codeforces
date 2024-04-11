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
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int lastr = 0, lastg = 0, lastb = 0;
	long long ans = 0;
	int mxr = 0, mxb = 0;
	for(int i = 1; i <= n; i ++)
	{
		int p;
		char c;
		cin >> p >> c;
		if(c == 'R')
		{
			if(lastr)
			{
				int now = p - lastr;
				ans += now;
				mxr = max(mxr, now);
			}
			lastr = p;
		}
		else if(c == 'B')
		{
			if(lastb)
			{
				int now = p - lastb;
				ans += now;
				mxb = max(mxb, now);
			}
			lastb = p;
		}
		else if(c == 'G')
		{
			if(lastr)
			{
				int now = p - lastr;
				ans += now;
				mxr = max(mxr, now);
			}
			if(lastb)
			{
				int now = p - lastb;
				ans += now;
				mxb = max(mxb, now);
			}
			if(lastg)
				ans += min(p - lastg - mxr - mxb, 0);
			lastr = lastg = lastb = p;
			mxr = mxb = 0;
		}
	}
	cout << ans << endl;
	
	return 0;
}