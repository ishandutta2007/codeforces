#include <bits/stdc++.h>

using namespace std;
typedef long long nagai;

int main()
{
	nagai l;
	int n;
	cin >> n >> l;
	vector<nagai> c(n);
	for (auto& x : c)
		cin >> x;
	for (int i = 0; i < n - 1; ++i)
		c[i + 1] = min(c[i + 1], 2 * c[i]);
	for (int i = n - 1; i > 0; --i)
		c[i - 1] = min(c[i - 1], c[i]);
	int n1 = 1 << (n - 1);
	nagai ans = 0;
	ans += 1LL * l / n1 * c.back();
	l %= n1;
	nagai ans1 = 0;
	for (int i = 0; i < n; ++i)
		if (l >> i & 1)
			ans1 += c[i];
	for (int i = 0; i < n; ++i)
	{
		nagai ans2 = c[i];
		for (int j = i; j < n; ++j)
			if (l >> j & 1)
				ans2 += c[j];
		ans1 = min(ans1, ans2);
	}
	cout << ans + ans1 << endl;
	return 0;
}