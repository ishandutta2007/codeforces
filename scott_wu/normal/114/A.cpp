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
	ll k, l;
	cin >> k >> l;
	
	ll val = k, cur = 0;
	while (val < l)
	{
		val *= k;
		cur++;
	}
	
	if (val == l)
	{
		cout << "YES\n";
		cout << cur << "\n";
	}
	else
	{
		cout << "NO\n";
	}
	return 0;
}