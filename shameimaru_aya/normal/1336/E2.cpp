#include <bits/stdc++.h> 
#define ppc(x) __builtin_popcountll(x)
using namespace std;
int n , m , k , t;
long long x , b[60] , ans[60] , s = 1 , fac[100] , inv[100] , inc[100] , num[60] , ss = 1;
const int mod = 998244353 , inv2 = (mod + 1) / 2;
void insert( long long x )
{
	for(int i = m - 1 ; i >= 0 ; i-- )
	{
		if(!((x >> i) & 1)) continue;
		if(b[i]) x ^= b[i];
		else 
		{
			k++; b[i] = x;
			for(int j = i - 1 ; j >= 0 ; j-- ) 
				if((b[i] >> j) & 1) b[i] ^= b[j];
			for(int j = m - 1 ; j > i ; j-- ) 
				if((b[j] >> i) & 1) b[j] ^= b[i];
			return ;
		}
	}
}
void dfs( int u , long long s )
{
	if(u == m)
	{
		ans[ppc(s)]++;
		return ;
	}
	dfs(u + 1 , s);
	if(b[u]) dfs(u + 1 , s ^ b[u]);
}
void init()
{
	fac[0] = fac[1] = inv[0] = inv[1] = inc[0] = inc[1] = 1;
	for(int i = 2 ; i <= 60 ; i++ ) fac[i] = fac[i - 1] * i % mod;
	for(int i = 2 ; i <= 60 ; i++ ) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
	for(int i = 2 ; i <= 60 ; i++ ) inc[i] = inc[i - 1] * inv[i] % mod;
	return ;
}
long long C( int a , int b )
{
	if(a < b || b < 0) return 0;
	return fac[a] * inc[b] % mod * inc[a - b] % mod;
}
void trans( long long &x , int a , int b )
{
	long long w1 = (x >> a) & 1 , w2 = (x >> b) & 1;
	x ^= (w1 << a) | (w2 << b);
	x |= (w1 << b) | (w2 << a);
}
void dfs2( int u , long long s )
{
	if(u > t)
	{
		num[ppc(s)]++;
		return ;
	}
	dfs2(u + 1 , s);
	dfs2(u + 1 , s ^ b[u]);
}
long long w( int c , int d )
{
	long long ans = 0;
	for(int i = 0 ; i <= m ; i++ )
		(ans += (i & 1 ? mod - 1 : 1) * C(d , i) % mod * C(m - d , c - i) % mod) %= mod;
	return ans;
}
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	init();
	scanf("%d%d" , &n , &m);
	for(int i = 1 ; i <= n ; i++ ) scanf("%lld" , &x) , insert(x);
	for(int i = 1 ; i <= n - k ; i++ ) s = s * 2 % mod;
	if(k <= 27)
	{
		dfs(0 , 0);
		for(int i = 0 ; i <= m ; i++ ) printf("%lld " , ans[i] * s % mod);
		return 0;
	}
	
	for(int i = 1 ; i <= m - k ; i++ ) ss = ss * inv2 % mod;
	t = m - 1;
	for(int i = m - 1 ; i >= 0 ; i-- )
	{
		if(!b[i]) continue;
		swap(b[t] , b[i]);
		for(int j = 0 ; j < m ; j++ ) trans(b[j] , i , t);
		t--;
	}
	for(int i = m - 1 ; i > t ; i-- )
		for(int j = t ; j >= 0 ; j-- ) 
			if((b[i] >> j) & 1) b[j] |= (1ll << i);
	for(int j = t ; j >= 0 ; j-- ) b[j] |= (1ll << j);
	dfs2(0 , 0);
	for(int i = 0 ; i <= m ; i++ )
	{
		for(int j = 0 ; j <= m ; j++ )
			(ans[i] += ss * num[j] % mod * w(i , j) % mod) %= mod;
		printf("%lld " , ans[i] * s % mod);
	}
    return 0;
} 
/*
2 2 2
1 2

*/