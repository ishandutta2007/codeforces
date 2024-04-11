#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int c = 0;
	int t = 1;
	while (t <= n)
	{
		n -= t, ++c, t *= 2;
	}
	if (n)
		++c;
	cout << c << '\n';
	return 0;
}