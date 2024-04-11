#include <bits/stdc++.h>



using namespace std;

#define mod 1000000007



int n, k, d;

long long dp[110][110];

int main()

{

//	freopen ("in.txt", "r", stdin);

	scanf ("%d%d%d", &n, &k, &d);

	dp[0][0]=1;

	for (int i=1; i<=n; i++){

		for (int j=1; j<=min(d-1, i); j++){

			dp[i][0]=(dp[i][0]+dp[i-j][0])%mod;

			dp[i][1]=(dp[i][1]+dp[i-j][1])%mod;

		}

		for (int j=d; j<=min(i, k); j++){

			dp[i][1]=(dp[i][1]+dp[i-j][0]+dp[i-j][1])%mod;

		}

	}

	cout<<dp[n][1]<<endl;

	return 0;

}