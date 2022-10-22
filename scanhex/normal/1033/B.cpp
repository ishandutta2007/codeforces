#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		nagai a, b;
		cin >> a >> b;
		nagai c = a - b;
		if (c != 1)
		{
			cout << "NO\n";
			continue;
		}
		nagai ans = a * 2 - 1;
		bool ok = true;
		for (nagai i = 2; i * i <= ans; ++i)
		{
			if (ans % i == 0)
			{
				ok = false;
				break;
			}
		}
		if (ans <= 1)
			ok = false;
		if (ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}