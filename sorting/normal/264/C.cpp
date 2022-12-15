#include<bits/stdc++.h>

using namespace std;

const long long N = 1e5 + 7;
const long long C = 500 + 7;
const long long maxi = 1e16;

long long n, q;
long long v[N], c[N];

long long dp[N];

long long solve(long long a, long long b)
{
	swap(a,b);

	long long res = 0, res2 = 0, tmp;

	for(long long i = 0; i < N; i++)
		dp[i] = -maxi;

	for(long long i = 0; i < n; i++)
	{
		tmp = dp[c[i]];

		if(dp[c[i]] == res)
			tmp = max(tmp, res2+v[i]*a);
		else
			tmp = max(tmp, res+v[i]*a);

		tmp = max(tmp, dp[c[i]]+v[i]*b);

		if(tmp >= res)
		{
			if(res != dp[c[i]])
				res2 = res;
			res = tmp;
		}
		else
			res2 = max(res2, tmp);

		dp[c[i]] = tmp;

		//cout<<dp[1]<<" "<<dp[2]<<" "<<dp[3]<<endl;
		//cout<<res<<" - "<<res2<<endl;
		//cout<<endl;
	}

	return res;
}

int main ()
{
	ios :: sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> q;

	for(long long i = 0; i < n; i++)
		cin >> v[i];

	for(long long i = 0; i < n; i++)
		cin >> c[i];

	for(long long i = 0; i < q; i++)
	{
		long long a, b;

		cin >> a >> b;

		cout << solve(a, b) << "\n";
	}

	return 0;
}
/*
6 1
3 4 2 3 1 4
1 2 1 1 2 2
*/