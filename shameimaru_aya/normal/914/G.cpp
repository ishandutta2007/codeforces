#include<bits/stdc++.h>
using namespace std;
int n , m = 17 , M = (1 << 17) , w , ppc[1 << 17];
long long x[18][1 << 17] , y[18][1 << 17] , a[1 << 17] , b[1 << 17] , c[1 << 17] , f[1 << 17] , ans;
const int mod = 1e9 + 7 , inv2 = (mod + 1) / 2;
void OR( long long *a , long long tp )
{
	for(int i = 0 ; i < m ; i++ )
		for(int j = 0 ; j < M ; j++ ) 
			if(j & (1 << i)) (a[j] += tp * a[j ^ (1 << i)] % mod) %= mod;
}
void AND( long long *f , int m )
{
	for(int x = 2 , k = 1 ; x <= M ; x <<= 1 , k <<= 1 )
		for(int i = 0 ; i < M ; i += x )
			for(int j = 0 ; j < k ; j++ )	//i + j ->k
				f[i + j] += f[i + j + k] * m , f[i + j] = (f[i + j] % mod + mod) % mod;
	return ;
}
void XOR( long long *f , int m )
{
	for(int x = 2 , k = 1 ; x <= M ; x <<= 1 , k <<= 1 )
	{
		for(int i = 0 ; i < M ; i += x )
		{
			for(int j = 0 ; j < k ; j++ )	//i + j ->k
			{
				f[i + j] += f[i + j + k];
				f[i + j + k] = f[i + j] - 2 * f[i + j + k] % mod;
				f[i + j] = 1ll * f[i + j] * m % mod;
				f[i + j + k] = 1ll * f[i + j + k] * m % mod;
				f[i + j] = (f[i + j] % mod + mod) % mod;
				f[i + j + k] = (f[i + j + k] % mod + mod) % mod;
			}
		}
	}
	return ;
}
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	for(int i = 0 ; i < M ; i++ ) ppc[i] = __builtin_popcount(i);
	f[1] = 1;
	for(int i = 2 ; i < M ; i++ ) f[i] = (f[i - 1] + f[i - 2]) % mod;
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &w) , y[ppc[w]][w]++ , b[w]++;
	for(int i = 0 ; i <= m ; i++ ) OR(y[i] , 1);
	for(int s = 0 ; s <= m ; s++ )
	{
		for(int t = 0 ; t <= m ; t++ )
		{
			if(s + t > m) break;
			for(int i = 0 ; i < M ; i++ ) (x[s + t][i] += y[s][i] * y[t][i] % mod) %= mod;
		}
	}
	for(int i = 0 ; i <= m ; i++ ) OR(x[i] , -1);
	for(int i = 0 ; i < M ; i++ ) a[i] = x[ppc[i]][i];
	XOR(b , 1); 
	for(int i = 0 ; i < M ; i++ ) c[i] = b[i] * b[i] % mod;
	XOR(b , inv2); XOR(c , inv2); 
	for(int i = 0 ; i < M ; i++ ) 
		a[i] = a[i] * f[i] % mod , b[i] = b[i] * f[i] % mod , c[i] = c[i] * f[i] % mod;
	AND(a , 1); AND(b , 1); AND(c , 1);  
	for(int i = 0 ; i < M ; i++ ) a[i] = a[i] * b[i] % mod * c[i] % mod;
	AND(a , -1);
	for(int i = 1 ; i < M ; i <<= 1 ) (ans += a[i]) %= mod;
	cout << ans;
	return 0;
}
/*
*/