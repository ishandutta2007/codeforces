#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <complex>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const long long mod = 1e9 + 7;
long long ksm(const long long &a, const long long &k)
{
	long long ans = 1;
	for(long long x = a % mod, asd = k; asd; asd >>= 1, (x *= x) %= mod)
		if(asd & 1)
			(ans *= x) %= mod;
	return ans;
}
long long dp[55][10005], q[55][10005];
long long inv[55];
long long work(const long long &p, const int &cnt, const int &k)
{
	dp[0][0] = q[0][0] = 1;
	for(int i = 1; i <= cnt; i ++)
	{
		dp[i][0] = dp[i - 1][0] * p % mod;
		q[i][0] = (q[i - 1][0] + dp[i][0]) % mod;
	}
	for(int i = 0; i <= cnt; i ++)
		for(int j = 1; j <= k; j ++)
		{
			dp[i][j] = inv[i + 1] * q[i][j - 1] % mod;
			q[i][j] = i == 0 ? dp[i][j] : (q[i - 1][j] + dp[i][j]) % mod;
		}
	return dp[cnt][k];
}
int main()
{
	std::ios::sync_with_stdio(false);
	long long n;
	int k;
	cin >> n >> k;
	for(int i = 1; i <= 51; i ++)
		inv[i] = ksm(i, mod - 2);
	long long ans = 1;
	for(long long i = 2; i * i <= n; i ++)
		if(n % i == 0)
		{
			int cnt = 0;
			while(n % i == 0)
			{
				n /= i;
				cnt ++;
			}
			(ans *= work(i, cnt, k)) %= mod;
		}
	if(n > 1)
		(ans *= work(n, 1, k)) %= mod;
	cout << ans << endl;
	
	return 0;
}