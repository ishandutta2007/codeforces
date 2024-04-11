#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <map>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int MAXB = 33;

int K;
ll ans;
int bk[MAXB];
int nk[MAXB];

ll find ()
{
	ll dp[MAXB]; // # ways for x gens
	for (int i = 0; i < MAXB; i++)
		dp[i] = 0;
	dp[0] = 1;
	
	/*int end = MAXB - 1;
	while (end >= 0 && nk[end] == 0)
		end--;*/
	
	for (int i = MAXB - 1; i >= 0; i--)
	{
		ll ndp[MAXB];
		for (int j = 0; j < MAXB; j++)
			ndp[j] = 0;
		
		if (nk[i] == 0)
		{
			for (int j = 1; j < MAXB; j++)
				ndp[j] = (dp[j] * (1LL << (j - 1))) % MOD;
			ndp[0] = dp[0];
		}
		else if (nk[i] == 1)
		{
			for (int j = 1; j < MAXB; j++)
				ndp[j] = (dp[j] * (1LL << (j - 1))) % MOD;
			for (int j = MAXB - 1; j >= 0; j--)
				ndp[j+1] = (ndp[j+1] + dp[j]) % MOD;
		}
		else
		{
			for (int j = 0; j < MAXB; j++)
				ndp[j] = (dp[j] * (1LL << j)) % MOD;
			for (int j = MAXB - 1; j >= 0; j--)
				ndp[j+1] = (ndp[j+1] + dp[j]) % MOD;
		}
		
		//cout << i << "\n";
		for (int j = 0; j < MAXB; j++)
		{
			dp[j] = ndp[j];
			//if (i < 5 && j < 5)
				//cout << i << " " << j << " " << dp[j] << " " << nk[i] << "\n";
		}
	}
	
	ll res = 0;
	for (int i = 0; i < MAXB; i++)
		res = (res + dp[i]) % MOD;
	return res;
}

ll solve (int x)
{
	//cout << x << "\n";
	
	for (int i = x + 1; i < MAXB; i++)
		nk[i] = bk[i];
	nk[x] = 0;
	for (int i = x - 1; i >= 0; i--)
		nk[i] = 2;
	return find();
}

int main()
{
	cin >> K;
	int tk = K;
	for (int i = 0; i < MAXB; i++)
	{
		bk[i] = tk % 2;
		tk /= 2;
	}
	
	ans = 0;
	for (int i = 0; i < MAXB; i++)
		if (bk[i] == 1)
			ans = (ans + solve (i)) % MOD;
	
	for (int i = 0; i < MAXB; i++)
		nk[i] = bk[i];
	ans = (ans + find()) % MOD;
	cout << ans << "\n";
	return 0;
}