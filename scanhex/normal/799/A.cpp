#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, t, k, d;
	cin >> n >> t >> k >> d;
	int L = 0, R = 3000;
	while (R - L > 1)
	{
		int M = (L + R) / 2;
		if (M / t * k + (M - d) / t * k >= n)
			R = M;
		else
			L = M;
	}
	if (R / t * k >= n)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
}