#include <bits/stdc++.h>

using namespace std;
typedef long long nagai;

nagai MOD = 1000000007;

nagai mpow(nagai a, int pow)
{
	if (pow == 0)
		return 1;
	if (pow == 1)
		return a;
	nagai kek = a * a % MOD;
	nagai ans = mpow(kek, pow / 2);
	if (pow & 1)
		ans *= a, ans %= MOD;
	return ans;
}

int main()
{
	int n;
	cin >> n;
	vector<nagai> arr(n);
	for (auto& x : arr)
		cin >> x;
	int n1 = (n - 1) / 2;
	if (n % 4 == 3)
		--n1;
	int k = 0;
	nagai cur = 1;
	vector<nagai> coef(n1 + 1, 1);
	for (int i = 0; i <= n1; ++i)
	{
		if (i > 0)
		{
			cur *= (n1 - (i - 1));
			cur %= MOD;
			nagai a = mpow(i, MOD - 2);
			cur *= a;
			cur %= MOD;
			coef[i] = cur;
		}
	}
	nagai ans = 0;
	int c = n % 4;
	if (c == 0)
	{
		for (int i = 0; i < n; ++i)
			ans += coef[i / 2] * arr[i] * (int(i % 2 == 0) * 2 - 1), ans %= MOD;
	}
	if (c == 1)
	{
		for (int i = 0; i <= n1; ++i)
			ans += coef[i] * arr[i * 2], ans %= MOD;
	}
	if (c == 2)
	{
		for (int i = 0; i < n; ++i)
			ans += coef[i / 2] * arr[i], ans %= MOD;
	}
	if (c == 3)
	{
		for (int i = 0; i < n - 1; ++i)
			ans += coef[i / 2] * arr[i], ans %= MOD;
		for (int i = 0; i < n - 1; ++i)
			ans += coef[i / 2] * arr[i + 1] * (int(i % 2 == 0) * 2 - 1), ans %= MOD;
	}
	if (ans < 0)
		ans += MOD;
	cout << ans << endl;
}