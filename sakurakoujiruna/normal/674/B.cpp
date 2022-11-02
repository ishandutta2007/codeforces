#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios :: sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	if(n == 4 || k < n + 1)
		cout << -1 << '\n';
	else
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		vector <int> others;
		for(int i = 1; i <= n; i ++)
			if(i != a && i != b && i != c && i != d)
				others.push_back(i);
		cout << a << ' ' << c << ' ';
		for(auto &x : others)
			cout << x << ' ';
		cout << d << ' ' << b << '\n';
		reverse(others.begin(), others.end());

		cout << c << ' ' << a << ' ';
		for(auto &x : others)
			cout << x << ' ';
		cout << b << ' ' << d << '\n';
	}
	return 0;
}