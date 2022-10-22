#include <bits/stdc++.h>

using namespace std;

using db = long double;

int main()
{
	ios::sync_with_stdio(false);
	int n, r;
	cin >> n >> r;
	vector<db> c(1 << n);
	for (auto& x : c)
		cin >> x;
	db sum = accumulate(c.begin(), c.end(), 0.0);
	db mem = (1 << n);
	cout.precision(30);
	cout << sum / mem << '\n';
	while (r--)
	{
		int z, g;
		cin >> z >> g;
		sum -= c[z];
		c[z] = g;
		sum += g;
		cout << sum / mem << '\n';
	}

}