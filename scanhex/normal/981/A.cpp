#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int mx = 0;
	int n = s.size();
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j <= n; ++j)
		{
			string a = s.substr(i, j - i);
			string b = a;
			reverse(b.begin(), b.end());
			if (a != b)
				mx = max(mx, j - i);
		}
	cout << mx << '\n';
}