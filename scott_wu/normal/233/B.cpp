#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int sd (ll x)
{
	int res =0 ;
	while (x)
	{
		res += x % 10;
		x /= 10;
	}
	return res;
}

ll solve (ll x)
{
	return x * x + sd(x) * x;
}

int main()
{
	ll x; cin >> x;
	
	ll hi = ((ll) sqrt (x)) + 50;
	for (ll i = max ((ll) 1, hi - 150); i < hi; i++)
	{
		if (solve (i) == x)
		{
			cout << i << "\n";
			return 0;
		}
	}
	cout << "-1\n";
	return 0;
}