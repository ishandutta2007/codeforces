#include <bits/stdc++.h>
#define lowbit(x) (x & (-x))
using namespace std;
int T = 1 , n , m , a[2200000] , b[2200000] , t[2200000];
long long fac[2200000] , inv[2200000] , inc[2200000] , c[2200000] , coe = 1 , ans;
const int mod = 998244353;
void init()
{
	fac[0] = fac[1] = inv[0] = inv[1] = inc[0] = inc[1] = 1;
	for(int i = 2 ; i <= 1000000 ; i++ ) fac[i] = fac[i - 1] * i % mod;
	for(int i = 2 ; i <= 1000000 ; i++ ) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
	for(int i = 2 ; i <= 1000000 ; i++ ) inc[i] = inc[i - 1] * inv[i] % mod;
}
void upd( int x , int a )
{
	while(x <= 200000)
	{
		c[x] += a;
		x += lowbit(x);
	}
}
long long ask( int x )
{
	long long ans = 0;
	while(x)
	{
		ans += c[x];
		x -= lowbit(x);
	}
	return ans;
}
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
//	scanf("%d" , &T);
	while(T--)
	{
		init();
		scanf("%d%d" , &n , &m); 
		for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]) , t[a[i]]++;
		for(int i = 1 ; i <= m ; i++ ) scanf("%d" , &b[i]);
		for(int i = 1 ; i <= 200000 ; i++ ) coe = coe * inc[t[i]] % mod , upd(i , t[i]);
		for(int i = 1 ; i <= min(n , m) ; i++ )
		{
			(ans += fac[n - i] * coe % mod * ask(b[i] - 1) % mod) %= mod;
			if(n < m && i == n && t[b[i]]) ans++ , ans %= mod;
			if(t[b[i]]) t[b[i]]-- , upd(b[i] , -1) , coe = coe * (t[b[i]] + 1) % mod;
			else break;
		}
		cout << ans;
	}
	return 0;
}
/*
*/