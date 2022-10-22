#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& x : a)
		cin >> x;
	for (int i = 0; i < 1 << n; ++i)
	{
		 int x = 0;
		 for (int j = 0; j < n; ++j)
			 if (i >> j & 1)
				 x += a[j];
			 else 
				 x -= a[j];
		 if (x % 360 == 0)
		 {
			  cout << "YES\n";
			  return 0;
		 }
	}
	cout << "NO\n";
	return 0;
}