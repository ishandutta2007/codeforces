#include <bits/stdc++.h>

using namespace std;

using nagai = long long;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	map<int, int> mem;
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		mem[a] = b;
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		mem[a] = max(mem[a], b);
	}
	nagai ans = 0;
	for (auto p : mem)
		if (p.second > 0)
			ans += p.second;
	cout << ans << '\n';
}