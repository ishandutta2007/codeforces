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
	vector<int> pos(n + 1, -1);
	for (int i = 0; i < n; ++i)
		pos[a[i]] = i;
	vector<bool> ans(n);
	for (int i = n; i >= 1; --i)
	{
		if (pos[i] == -1)
			continue;
		int x = pos[i];
		for (int j = x - i; j >= 0; j -= i)
		{
			if (!ans[j] && a[j] > a[x])
				ans[x] = true;
		}
		for (int j = x + i; j < n; j += i)
		{
			 if (!ans[j] && a[j] > a[x])
				 ans[x] = true;
		}
	}
	for (int i = 0; i < n; ++i)
		if (ans[i])
			cout << "A";
		else
			cout << "B";
	cout << '\n';
	return 0;
}