#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
	ll x;
	int ncount = 0;
	cin >> x;
	
	while (x)
	{
		if (x % 10 == 4 || x % 10 == 7)
			ncount++;
		x /= 10;
	}
	
	bool check = false;
	if (ncount)
	{
		check = true;
		while (ncount)
		{
			if (ncount % 10 != 4 && ncount % 10 != 7)
				check = false;
			ncount /= 10;
		}
	}
	if (check) cout << "YES\n";
	else cout << "NO\n";
}