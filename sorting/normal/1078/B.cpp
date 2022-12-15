#include<bits/stdc++.h>

using namespace std;

const short N = 107;
short n;

short a[N];
short dp[2][N*N][N];

short solve(short pos, short sum, short cnt)
{
	if(sum < 0)
		return 0;
	if(cnt < 0)
		return 0;

	return dp[pos][sum][cnt];
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	short diff = 0;

	for(short i = 0; i < n; i++)
	{
		short x;

		cin >> x;

		a[x]++;

		if(a[x] == 1)
			diff++;
	}

	dp[1][0][0] = 1;

	for(short pos = 100; pos >= 1; pos--)
	{
		for(short sum = 0; sum <= 10000; sum++)
			for(short cnt = 0; cnt <= n; cnt++)
			{
				short curr = pos%2, next_ = (pos+1)%2;
				short& res = dp[curr][sum][cnt];

				res = 0;

				for(long long i = 0; i <= a[pos] && res < 2; i++)
					res += solve(next_, sum - pos*i, cnt - i);


				if(res >= 2)
					res = 2;

				//if(sum <= 24)
				//	cout << res << " " << pos << " " << sum << " " << cnt << endl;
 			}
	}

	short res = 0;

	for(short i = 1; i <= 100; i++)
	{
		for(short j = 1; j < a[i]; j++)
			if(solve(1, j*i, j) == 1)
			{
				res = max(res, j);
			}

		if(a[i])
		{
			//cout << solve(1, a[i]*i, a[i]) << endl;
			if(solve(1, a[i]*i, a[i]) == 1)
			{
				res = max(res, a[i]);

				if(diff == 2)
					res = n;
			}
		}
	}

	cout << res << "\n";

	return 0;
}