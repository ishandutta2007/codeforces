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
	int n, x, y;
	cin >> n >>  x >>  y;
	if (n == 2)
		cout << "NO\n";
	else
	{
		//cout << x << " " << y << " " << n /2  << "\n";
		if (x >= n / 2 && (x <= n / 2 + 1))
			if (y >= n / 2 && (y <= n / 2 + 1))
			{
				cout << "NO\n";
				return 0;
			}
		cout << "YES\n";
	}
}