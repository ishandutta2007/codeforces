#include<bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

const long long mod = 1e9 + 7;
const long long N = 1e5 + 7;

long long fact_dp[N];
long long inv[N];

map<long long, long long> mp[N];

long long make_normal(long long &x)
{
	//x %= mod;

	while(x < 0)
		x += mod;

	return x;
}

long long fast_pow(long long base, long long exp)
{
	if(base == 0ll)
		return 0ll;
	if(exp == 0ll)
		return 1ll;

	long long res = 1ll;

	if(exp & 1)
		res = base;

	long long tmp = fast_pow(base, exp >> 1);

	res *= tmp;
	res %= mod;

	res *= tmp;
	res %= mod;

	return res;
}

long long factorial(long long n)
{
	if(n == 0ll)
		return 1ll;
	if(fact_dp[n])
		return fact_dp[n];

	fact_dp[n] = factorial(n-1) * n;
	fact_dp[n] %= mod;

	return fact_dp[n];
}

long long combination(long long n, long long k)
{
	long long res = factorial(n);

	res *= inv[k];
	res %= mod;

	res *= inv[n - k];
	res %= mod;

	return res;
}

long long dp[N], used[N];

void solve()
{
	long long n, f;

	cin >> n >> f;

	if(mp[f].find(n) != mp[f].end())
	{
		cout << mp[f][n] << "\n";

		return ;
	}

	long long cnt = 0, i;

	for(i = 1; i*i <= n; i++)
		if(n % i == 0)
		{
			used[cnt] = i;
			cnt++;
		}

	for(i = i - 1; i >= 1; i--)
		if(n % i == 0 && i*i != n)
		{
			used[cnt] = n / i;
			cnt++;
		}

	for(i = 0; i < cnt; i++)
	{
		int curr = used[i];

		if(curr < f)
		{
			dp[curr] = 0;
			continue; 
		}

		dp[curr] = combination(curr - 1, f - 1);

		for(int j = 0; j < i; j++)
		{
			if(used[j] * used[j] > curr)
				break;

			if(curr % used[j] == 0)
			{
				dp[curr] -= dp[ used[j] ];

				if(used[j] * used[j] != curr && j != 0)
					dp[curr] -= dp[ curr / used[j] ];

				make_normal(dp[curr]);
			}
		}

		mp[f][curr] = dp[curr];
	}

	cout << dp[n] << "\n";

	return ;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long q;

	cin >> q;

	for(long long i = 0; i <= 100000; i++)
		inv[i] = fast_pow(factorial(i), mod - 2);

	for(long long i = 0; i < q; i++)
		solve();

	return 0;
}