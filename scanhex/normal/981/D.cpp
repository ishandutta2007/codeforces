#include <bits/stdc++.h>

using namespace std;

using nagai = long long;

int main()
{
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<nagai> a(n);
	for (auto& x : a)
		cin >> x;
	const int C = 62;
	nagai ans = 0;
	vector<nagai> pref(n + 1);
	for (int i = 0; i < n; ++i)
		pref[i + 1] = pref[i] + a[i];
	for (int i = C - 1; i >= 0; --i)
	{
		ans += (1LL << i);
		vector<vector<bool>> mem(n + 1, vector<bool>(k + 1));
		mem[0][0] = true;
		for (int j = 0; j < n; ++j)
			for (int l = 0; l < k; ++l)
				for (int a = j + 1; a <= n; ++a)
				{
					if (!mem[j][l])
						continue;
					if (((pref[a] - pref[j]) & ans) == ans)
						mem[a][l + 1] = true;
				}
		if (!mem[n][k])
			ans -= 1LL << i;
	}
	cout << ans << '\n';
}