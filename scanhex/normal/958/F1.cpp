#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (auto& x : a)
		cin >> x, --x;
	vector<int> k(m);
	for (auto& x : k)
		cin >> x;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j <= n; ++j)
		{
			vector<int> cur(m);
			for (int l = i; l < j; ++l)
				++cur[a[l]];
			if (cur == k)
			{
				cout << "YES\n";
				return 0;
			}
		}
	cout << "NO\n";
}