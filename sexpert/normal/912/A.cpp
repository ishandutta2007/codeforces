#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long a, b, x, y, z, yellow, blue;
	cin >> a >> b;
	cin >> x >> y >> z;
	yellow = 2*x + y;
	blue = 3*z + y;
	cout << max(0ll, blue - b) + max(0ll, yellow - a);
}