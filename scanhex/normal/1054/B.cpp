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
	vector<int> a(n);
	for (auto& x : a)
		cin >> x;
	int mx = -1;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > mx + 1)
		{
			 cout << i + 1 << '\n';
			 return 0;
		}
		mx = max(mx, a[i]);
	}
	cout << -1 << '\n';
	return 0;
}