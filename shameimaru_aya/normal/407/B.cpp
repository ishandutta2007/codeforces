#include<bits/stdc++.h>
using namespace std;
int n , p[1100000];
long long sum[1100000];
const int mod = 1e9 + 7;
int main()
{
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &p[i]);
	for(int i = 1 ; i <= n ; i++ )
	{
		sum[i] = ((sum[i - 1] - sum[p[i] - 1] + 2) % mod + mod) % mod;
		sum[i] = (sum[i] + sum[i - 1]) % mod;
	}
	printf("%d" , sum[n]);
	return 0;
}