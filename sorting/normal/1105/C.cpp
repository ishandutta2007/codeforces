#include <bits/stdc++.h>

using namespace std;

const long long N = 2e5 + 7;
const long long mod = 1e9 + 7;

pair<long long, bool> dp[N][3];

long long p[3];

long long solve(long long n, long long rem)
{
	if(n == 0){
		if(rem == 0){
			return 1;
		}else{
			return 0;
		}
	}

	if(dp[n][rem].second){
		return dp[n][rem].first;
	}

	dp[n][rem].second = true;

	long long &res = dp[n][rem].first;

	res += solve(n - 1, 0) * p[(3 - rem) % 3];
	res += solve(n - 1, 1) * p[(4 - rem) % 3];
	res += solve(n - 1, 2) * p[(5 - rem) % 3];

	res %= mod;

	return res;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, l, r;

	cin >> n >> l >> r;

	p[0] = r / 3 - (l-1) / 3;
	p[1] = (r+1) / 3 - (l) / 3;
	p[2] = (r+2) / 3 - (l+1) / 3; 

	cout << solve(n, 0) << "\n";

	return 0;
}