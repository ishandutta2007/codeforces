#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int64 f(int64 n, int64 m)
{
	if (n > m)
		swap(n, m);
	return n * n * m + n * (n - 1) * (2 * n - 1) / 6 - (n + m) * n * (n - 1) / 2;
	// n * n * n + n * (n - 1) * (2 * n - 1) / 6 - 2 * n * n * (n - 1) / 2
	// n ^ 3 / 3 + n ^ 2 / 2 + n / 6
}

int main()
{
	int64 x;
	cin >> x;
	set<pair<int64, int64>> v;
	for (int64 n = 1; n <= 1500000; ++n)
	{
		int64 L = 0, R = x * 8 / n / n;
		while (R - L > 1)
		{
			int64 M = (R + L) / 2;
			if (f(n, M) >= x)
				R = M;
			else
				L = M;
		}
		if (f(n, R) == x)
			v.insert({n, R}), v.insert({R, n});
	}
	cout << v.size() << endl;
	for (auto x : v)
		cout << x.first << ' ' << x.second << endl;
	return 0;
}