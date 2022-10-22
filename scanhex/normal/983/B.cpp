#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& x : a)
		cin >> x;
	vector<vector<int>> f(n, vector<int>(n + 1));
	for (int len = 1; len <= n; ++len)
	{
		for (int l = 0; l + len <= n; ++l)
		{
			int r = l + len;
			if (len == 1)
			{
				f[l][r] = a[l];
				continue;
			}
			f[l][r] = f[l][r - 1] ^ f[l + 1][r];
		}
	}
	for (int len = 2; len <= n; ++len)
		for (int l = 0; l + len <= n; ++l)
		{
			int r = l + len;
			f[l][r] = max(f[l][r], f[l][r - 1]);
			f[l][r] = max(f[l][r], f[l + 1][r]);
		}
	int q;
	cin >> q;
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		--l;
		cout << f[l][r] << '\n';
	}
}