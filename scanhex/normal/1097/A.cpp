#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	vector<string> mem(5);
	cin >> s;
	for (auto& x : mem)
	{
		cin >> x;
		if (x[0] == s[0] || x[1] == s[1])
		{
			 cout << "YES\n";
			 return 0;
		}
	}
	cout << "NO\n";
	return 0;
}