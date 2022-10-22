#include <bits/stdc++.h>

using namespace std;
typedef long double dbl;

dbl sqr(dbl x)
{
	return x * x;
}

int main()
{
	int n, r;
	cin >> n >> r;
	vector<dbl> coords(n);
	vector<int> xs(n);
	cout.precision(30);
	for (int i = 0; i < n; ++i)
	{
		cin >> xs[i];
		dbl mx = r;
		for (int j = 0; j < i; ++j)
		{
			if (abs(xs[i] - xs[j]) > 2 * r)
				continue;
			dbl l = sqrt(4 * sqr(r) - sqr(xs[i] - xs[j]));
			mx = max(mx, coords[j] + l);
		}
		coords[i] = mx;
		cout << coords[i] << ' ';
	}
	cout << endl;
}