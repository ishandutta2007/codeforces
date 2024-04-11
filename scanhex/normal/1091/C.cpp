#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	nagai n;
	cin >> n;
	vector<nagai> divs;
	for (nagai i = 1; i * i <= n; ++i)
	{
		if (n % i == 0)
		{
			divs.push_back(i);
			if (i * i != n)
				divs.push_back(n / i);
		}
	}
	set<nagai> ans;
	for (auto& x : divs)
	{
		ans.insert(n / x + x * (n / x) * (n / x + 1) / 2 - n);
	}
	for (auto& x :ans)
		cout << x << ' ';
	cout << '\n';
	return 0;
}