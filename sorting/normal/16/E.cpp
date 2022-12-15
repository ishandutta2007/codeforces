#include<bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

using namespace std;

const int N = 1e6;

double a[20][20];
double res[20], dp[N];

int main ()
{
	int n;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> a[i][j];

	dp[(1<<n)-1] = 1.0;

	for(int i = (1<<n)-1; i >= 1; i--)
	{
		int cnt = 0, last;

		for(int j = 0; j < n; j++)
			if((1<< j) & i)
			{
				cnt++;
				last = j;
			}

		if(cnt == 1)
		{
			//cout << last <<endl;
			//cout << res[last] << endl;
			res[last] += dp[i];
			continue;
		}

		double del = (double)(2.0/( cnt*(cnt-1) ) );

		for(int j = 0; j < n; j++)
		{
			if(!(i & (1<<j)))
				continue;
			for(int k = j+1; k < n; k++)
			{
				if(!(i & (1<<k)))
					continue;

				dp[i ^ (1<<j)] += dp[i]*a[k][j]*del;
				dp[i ^ (1<<k)] += dp[i]*a[j][k]*del;
			}
		}
	}
		

	for(int i = 0; i < n-1; i++)
		cout << res[i] << " ";
	cout<< res[n-1] << "\n";

	return 0;
}