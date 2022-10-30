#include<bits/stdc++.h>
#define ppc(x) __builtin_popcountll(x)
using namespace std;
int n;
unsigned long long a[2200000] , b[2200000] , c[2200000] , mod;
char s[2200000];
long long exp( int a , int b )
{
	long long ans = 1 , t = a;
	while(b)
	{
		if(b & 1) ans = ans * t % mod;
		t = t * t % mod;
		b >>= 1;
	}
	return ans;
}
void OR( unsigned long long *f , int m )
{
	for(int i = 1 ; i < n ; i <<= 1 )
		for(int j = 0 ; j < n ; j++ )
			if(j & i) f[j] += f[j ^ i] * m;
	return ;
}
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	mod = (1ll << 44);
	scanf("%d" , &n); n = 1 << n;
	scanf("%s" , s);
	for(int i = 0 ; i < n ; i++ ) a[i] = (unsigned long long)(s[i] - '0') << (ppc(i) << 1);
	scanf("%s" , s);
	for(int i = 0 ; i < n ; i++ ) b[i] = (unsigned long long)(s[i] - '0') << (ppc(i) << 1);
	OR(a , 1); OR(b , 1); 
	for(int i = 0 ; i < n ; i++ ) c[i] = a[i] * b[i];
	OR(c , -1); 
	for(int i = 0 ; i < n ; i++ ) printf("%lld" , ((c[i] >> (ppc(i) * 2)) + 4) % 4);
	return 0;
}