#include <bits/stdc++.h>
using namespace std;
int T , n , m , k;
long long f[3300][3300];
const int mod = 1e9 + 7 , inv2 = (mod + 1) / 2;
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	for(int i = 1 ; i <= 2000 ; i++ )
	{
		f[i][0] = 0; f[i][i] = i;
		for(int j = 1 ; j < i ; j++ )
			f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) * inv2 % mod;
	}
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d%d%d" , &n , &m , &k);
		printf("%lld\n" , f[n][m] * k % mod);
	}
	return 0;
}
/*
*/