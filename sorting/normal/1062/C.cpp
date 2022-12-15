#include<bits/stdc++.h>

using namespace std;

const long long N = 2e5 + 7;
const long long mod = 1e9 + 7;

long long prefix[N];
long long dp[N];

long long fast_pow(long long base, long long exp)
{
	if(exp == 0)
		return 1;

	if(dp[exp])
		return dp[exp];

	long long res = 1;

	if(exp % 2 == 1)
		res *= base;

	long long half = fast_pow(base, exp/2);

	res *= half;
	res %= mod;

	res *= half;
	res %= mod;

	dp[exp] = res;

	return res;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, q;

	cin >> n >> q;

	string s;

	cin >> s;

	prefix[0] = s[0] - '0';

	for(long long i = 1; i < n; i++)
		prefix[i] = prefix[i-1] +s[i] - '0';

	for(long long i = 0; i < q; i++)
	{
		long long l, r;

		cin >> l >> r;

		l--;
		r--;

		long long sum = prefix[r];

		if(l != 0)
			sum -= prefix[l-1];

		long long zero = r-l+1-sum;

		//cout << sum << " " << zero << endl;

		long long act_res = (fast_pow(2ll, sum)-1ll)*(fast_pow(2,zero));

		act_res %= mod;

		cout << act_res << "\n";
	}

	return 0;
}