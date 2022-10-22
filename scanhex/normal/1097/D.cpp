#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define div aeouaoe
const int mod = 1e9 + 7;
int mult(int a, int b)
{
	 return (nagai)a*b%mod;
}
int add(int a, int b)
{
	a += b;
	if (a >= mod)
		a -= mod;
	return a;
}

int pw(int a, int b)
{
	int c = 1;
	while (b)
	{
		 if (b & 1)
			 c = mult(a, c);
		 a = mult(a, a);
		 b /= 2;
	}
	return c;
}

int div(int a, int b)
{
	return mult(a, pw(b, mod - 2));
}



vector<pair<nagai, int>> fact(nagai n)
{
	vector<pair<nagai, int>> ans;
	for (nagai i = 2; i * i <= n; ++i)
	{
		pair<nagai, int> p(i, 0);
		while (n % i == 0)
			n /= i, p.second++;
		if (p.second)
			ans.push_back(p);
	}
	if (n > 1)
		ans.emplace_back(n, 1);
	return ans;
}

nagai solve(nagai a, nagai b, nagai k)
{
	a %= mod;
	vector<nagai> arr(b + 1);
	vector<nagai> inv(100);
	for (int i = 1; i < 100; ++i)
		inv[i] = div(1, i);
	arr[0] = 1;
	for (int i = 0; i < b; ++i)
		arr[i + 1] = mult(arr[i], a);
	vector<vector<nagai>> prob(k + 1, vector<nagai>(b + 1));
	prob[0][b] = 1;
	for (int k1 = 0; k1 < k; ++k1)
	{
		for (int i = 0; i <= b; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				prob[k1 + 1][j] = add(prob[k1 + 1][j], mult(prob[k1][i], inv[i + 1]));
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= b; ++i)
		ans = add(ans, mult(prob[k][i], arr[i]));
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	nagai n, k;
	cin >> n >> k;
	auto mem = fact(n);
	int ans = 1;
	for (auto& [x, y] : mem)
		ans = mult(ans, solve(x, y, k));
	cout << ans << '\n';
}