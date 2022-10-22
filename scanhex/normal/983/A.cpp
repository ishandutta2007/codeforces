#include <bits/stdc++.h>

using namespace std;
typedef long long nagai;



inline nagai gcd(nagai a, nagai b)
{
	while (b > 0)
	{
		nagai c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	while (n--)
	{
		nagai p, q, b;
		cin >> p >> q >> b;
		q /= gcd(q, p);
		nagai d = gcd(b, q);
		while (d > 1)
		{
			q /= d;
			d = gcd(q, d);
		}
		if (q == 1)
			cout << "Finite\n";
		else
			cout << "Infinite\n";
	}
}