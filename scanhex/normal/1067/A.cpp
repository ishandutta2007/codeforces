#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
using ll = long long;

const int N = 100000 + 10;
const int MX = 201;
const int mod = 998244353;
int mult(int a, int b)
{
	 return (nagai)a * b % mod;
}
int add(int a, int b)
{
	a += b;
	if (a >= mod)
		a -= mod;
	return a;
}

int md(int x)
{
	if (x < 0)
		x += mod;
	if (x >= mod)
		x -= mod;
	return x;
}
int dp[N][MX][2];

bool check(int a, int b, int c)
{
	return a == -1 || c == -1 || b <= max(a, c);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& x : a)
		cin >> x;
	if (a[0] == -1)
	{
		for (int i = 1; i < MX; ++i)
			dp[0][i][0] = 1;
			//if (check(-2, i, a[1]))
				//dp[0][i][0] = 1;
	}
	else 
		dp[0][a[0]][0] = 1;
			
	vector<int> pref0(MX + 1), pref1(MX + 1);
	for (int i = 0; i < MX; ++i)
	{
		pref0[i + 1] = add(pref0[i], dp[0][i][0]);
		pref1[i + 1] = add(pref1[i], dp[0][i][1]);
	}
	int ans = 0;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j < MX; ++j)
		{
			if (a[i] != -1 && a[i] != j)
				continue;
			// a[i - 1] < j
			dp[i][j][0] = add(dp[i][j][0], pref0[j]);
			dp[i][j][0] = add(dp[i][j][0], pref1[j]);
			// a[i - 1] = j
			dp[i][j][1] = add(dp[i][j][1], add(dp[i - 1][j][0], dp[i - 1][j][1]));
			// a[i - 1] > j
			dp[i][j][1] = add(dp[i][j][1], md(pref1.back() - pref1[j + 1]));
			if (i == n - 1)
				ans = add(ans, dp[i][j][1]);
		}
		for (int j = 0; j < MX; ++j)
		{
			pref0[j + 1] = add(pref0[j], dp[i][j][0]);
			pref1[j + 1] = add(pref1[j], dp[i][j][1]);
		}
	}
	cout << ans << '\n';
	return 0;
}