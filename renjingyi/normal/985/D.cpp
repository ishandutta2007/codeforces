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
const long long oo = 2e9;
int main()
{
	std::ios::sync_with_stdio(false);
	long long n, h;
	cin >> n >> h;
	if(h > oo || h <= oo && h * (h + 1) / 2 >= n)
	{
		long long l = 1, r = min(h, oo);
		while(l < r)
		{
			long long mid = (l + r) >> 1;
			if(mid * (mid + 1) / 2 >= n)
				r = mid;
			else
				l = mid + 1;
		}
		cout << l << endl;
		return 0;
	}
	n += h * (h - 1) / 2;
	long long l = 1, r = oo;
	while(l < r)
	{
		long long mid = (l + r) >> 1;
		if(mid * (mid + 1) - mid >= n)
			r = mid;
		else
			l = mid + 1;
	}
	long long ans = 2 * l - h;
	l = 1, r = oo;
	while(l < r)
	{
		long long mid = (l + r) >> 1;
		if(mid * (mid + 1) >= n)
			r = mid;
		else
			l = mid + 1;
	}
	ans = min(ans, 2 * l - h + 1);
	cout << ans << endl;
	
	return 0;
}