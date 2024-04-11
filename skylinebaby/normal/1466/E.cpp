#pragma gcc optimize(Ofast)
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
long long w[512345];
long long cc[60];
long long pw[60];
//int cnt[60][60];
int main()
{
	int zzzzz;
	scanf("%d", &zzzzz);
	pw[0] = 1;
	for(int i = 1; i < 60; i++)
	{
		pw[i] = pw[i - 1] * 2;
		if(pw[i] > mod) pw[i] -= mod;
 	}
	while(zzzzz--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%lld", &w[i]);
		/*for(int i = 0; i < 60; i++) for(int j = 0; j < 60; j++)
		{
			cnt[i][j] = 0;
		}*/
		for(int i = 0; i < 60; i++)
		{
			cc[i] = 0;
		}
		/*for(int t = 0; t < n; t++) for(int i = 0; i < 60; i++) for(int j = 0; j < 60; j++) 
		{
			if((w[t] ^ (1ll << i)) == (w[t] - (1ll << i)) && (w[t] ^ (1ll << j)) == (w[t] - (1ll << j))) cnt[i][j] ++;
		}*/
		for(int t = 0; t < n; t++) for(int i = 0; i < 60; i++)
		{
			if((w[t] ^ (1ll << i)) == (w[t] - (1ll << i))) cc[i] ++;
		}
		/*for(int i = 0; i < 60; i++) for(int j = 0; j < 60; j++)
		{
			if(cnt[i][j] != 0) printf("%d %d %d\n", i, j, cnt[i][j]);
		}*/
		/*for(int i = 0; i < 60; i++)
		{
			if(cc[i] != 0) printf("%d %d\n", i, cc[i]);
		}*/
		long long ans = 0;
		for(int t = 0; t < n; t++)
		{
			long long z = 0;
			for(int i = 0; i < 60; i++) if((w[t] ^ (1ll << i)) == (w[t] - (1ll << i)))
			{
				z += (pw[i] * cc[i]) % mod;
				z %= mod;
			}
			//printf("%d %lld\n", t, z);
			for(int i = 0; i < 60; i++)
			{
				if((w[t] ^ (1ll << i)) == (w[t] - (1ll << i)))
				{
					long long nz = z - (pw[i] * cc[i]) % mod;
					nz = (nz + mod) % mod;
					long long vv = pw[i] * nz;
					vv %= mod;
					ans += vv * (n - cc[i]);
					ans %= mod;
				}
			}
			//printf("%d %lld\n", t, ans);			
		}
		//printf("%lld\n", ans);
		for(int i = 0; i < 60; i++) for(int j = 0; j < 60; j++)
		{
			long long inc = pw[i] * pw[j];
			long long ways = (cc[i] * cc[i]  * cc[j]);
			if(i == j) ways = (cc[i] * cc[i] * n);
			if(!ways) continue;
			inc = inc % mod;
			ways = ways % mod;
			ans += inc * ways;
			ans = ans % mod;
			//printf("%d %d %lld %lld %lld\n", i, j, ans, inc, ways);
		}
		printf("%lld\n", ans);
	}
 
	return 0;
 }