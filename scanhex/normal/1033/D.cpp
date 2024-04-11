#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
using ll = long long;

nagai gcd(nagai a, nagai b)
{
	 while (b)
	 {
		  a = a % b;
		  swap(a, b);
	 }
	 return a;
}

#define sqrt aoeusnthoaeu
nagai sqrt(nagai x)
{
	nagai L = 0, R = 2e9;
	while (R - L > 1)
	{
		 nagai M = (L + R) / 2;
		 if (M * M < x)
			 L = M;
		 else
			 R = M;
	}
	if (R * R == x)
		return R;
	return -1;
}
nagai cbrt(nagai x)
{
	nagai L = 0, R = 1.5e6;
	while (R - L > 1)
	{
		 nagai M = (L + R) / 2;
		 if (M * M * M < x)
			 L = M;
		 else
			 R = M;
	}
	if (R * R * R == x)
		return R;
	return -1;
}

int main()
{
	int n;
	cin >> n;
	vector<nagai> a(n);
	for (auto& x : a)
		cin >> x;
	vector<nagai> divs;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			nagai g = gcd(a[i], a[j]);
			if (g < a[i] && g < a[j] && g > 1)
				divs.push_back(g);
		}
	for (auto x : a)
	{
		nagai y = sqrt(x);
		if (y != -1)
		{
			nagai z = sqrt(y);
			if (z != -1)
				divs.push_back(z);
			else
				divs.push_back(y);
		}
		y = cbrt(x);
		if (y != -1)
			divs.push_back(y);
	}
	sort(divs.begin(), divs.end());
	divs.erase(unique(divs.begin(), divs.end()), divs.end());
	if (divs.size() && divs[0] == 1)
		divs.erase(divs.begin());
	nagai ans = 1;
	const nagai mod = 998244353;
	vector<int> cnt(n);
	for (auto& x : divs)
	{
		int cur = 0;
		for (int i = 0; i < n; ++i)
		{
			while (a[i] % x == 0)
				a[i] /= x, ++cur, ++cnt[i];
		}
		ans *= (cur + 1);
		ans %= mod;
	}
	map<nagai, int> mp1, mp2;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] == 1)
			continue;
		if (cnt[i] == 0)
			++mp1[a[i]];
		else
			++mp2[a[i]];
	}
	for (auto& x : mp1)
	{
		ans *= (x.second + 1);
		ans %= mod; 
		ans *= (x.second + 1);
		ans %= mod;
	}
	for (auto& x : mp2)
	{
		ans *= (x.second + 1);
		ans %= mod;
	}
	cout << ans << '\n';
	cout.flush();
	return 0;
}