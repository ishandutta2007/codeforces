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
	string s,t ;
	cin >> s >> t;
	int ans = 0;
	for (int i = 0; i + 1 < n; ++i)
	{
		if (t[i] == s[i + 1] && s[i] == t[i + 1] && t[i] != s[i])
		{
			swap(s[i], s[i + 1]);
			ans += 1;
		}
	}
	for (int i = 0; i < n; ++i)
		if (s[i] != t[i])
			++ans;
	cout << ans << '\n';
	return 0;
}