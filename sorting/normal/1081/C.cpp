#include <bits/stdc++.h>

const long long N = 2007;
const long long mod = 998244353;

long long m;
std::pair<long long, long long> dp[N][N];

long long solve(long long n, long long k)
{
	if(k == 0)
		return 1;
	if(n <= 0)
		return 0;
	if(dp[n][k].second)
		return dp[n][k].first;

	dp[n][k].second = true;

	long long &res = dp[n][k].first;

	res = solve(n-1, k) + (solve(n-1, k-1)*(m-1)) % mod;
	res %= mod;

	return res;
}

int main ()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	long long n, k;

	std::cin >> n >> m >> k;

	std::cout << (solve(n-1, k)*m) % mod << "\n";

	return 0;
}