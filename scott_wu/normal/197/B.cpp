#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int gcd (int a, int b)
{
	return ((b == 0) ? a : gcd (b, a % b));
}

int main()
{
	int n, m;
	cin >> n >> m;
	int x, y, t;
	cin >> x;
	for (int i = 0; i < n; i++)
		cin >> t;
	cin >> y;
	for (int i = 0; i < m; i++)
		cin >> t;
	if (n < m)
		cout << "0/1\n";
	if (n > m)
	{
		if (x * y < 0)
			cout << "-Infinity\n";
		else
			cout << "Infinity\n";
	}
	if (n == m)
	{
		if (y < 0)
			x = -x, y = -y;
		cout << x / gcd (abs(x), abs(y)) << "/" << y / gcd (abs(x), abs(y)) << "\n";
	}
	return 0;
}