#include <bits/stdc++.h>
using namespace std;
int n , qwq , a[70] , in[70] , s[70] , t[70] , tot , tt , ts , cnt[1 << 15] , f[70] , num[70] , ss;
long long ans = 1 , sum , dp[65][1 << 15] , fac[70] , inv[70] , inc[70];
queue< int > q;
const int mod = 1e9 + 7;
void init()
{
	fac[0] = inv[0] = inv[1] = inc[0] = inc[1] = 1;
	for(int i = 1 ; i <= 60 ; i++ ) fac[i] = fac[i - 1] * i % mod;
	for(int i = 2 ; i <= 60 ; i++ ) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
	for(int i = 2 ; i <= 60 ; i++ ) inc[i] = inc[i - 1] * inv[i] % mod;
	return ;
}
inline long long C( int a , int b )
{
	return fac[a] * inc[b] % mod * inc[a - b] % mod;
}
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	init();
	scanf("%d" , &n); qwq = n;
	for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]);
	for(int S = 1 ; S <= n ; S++ )
	{
		if(f[S]) continue;
		memset(in , 0 , sizeof(in)); memset(dp , 0 , sizeof(dp));
		memset(cnt , 0 , sizeof(cnt)); ts = tt = sum = 0;
		q.push(S); f[S] = S;
		while(!q.empty())
		{
			int u = q.front(); q.pop();
//			cerr << a[u] << ' ';
			for(int i = 1 ; i <= n ; i++ )
				if(!f[i] && (a[i] % a[u] == 0 || a[u] % a[i] == 0)) q.push(i) , f[i] = S;
		}
//		cerr << endl;
		for(int i = 1 ; i <= n ; i++ )
		{
			if(f[i] != S) continue;
			for(int j = 1 ; j <= n ; j++ )
			{
				if(i == j || f[j] != S) continue;
				if(a[i] % a[j] == 0) in[i]++;
			}
		}
		for(int i = 1 ; i <= n ; i++ ) 
		{
			if(f[i] != S) continue;
			if(in[i]) t[++tt] = a[i];
			else s[++ts] = a[i];
		}
		if(tt <= 1) continue;
		memset(in , 0 , sizeof(in));
		for(int i = 1 ; i <= tt ; i++ )
		{
			for(int j = 1 ; j <= ts ; j++ ) in[i] |= (t[i] % s[j] == 0) << (j - 1);
			for(int j = in[i] ; j < (1 << ts) ; j++ ) cnt[j] += ((in[i] & j) == in[i]);
		}
		for(int i = 1 ; i <= tt ; i++ ) dp[1][in[i]]++; 
		for(int i = 1 ; i <= tt ; i++ )
		{
			for(int j = 0 ; j < (1 << ts) ; j++ ) 
			{
				for(int k = 1 ; k <= tt ; k++ )
					if((j & in[k]) && (j | in[k]) != j) (dp[i + 1][j | in[k]] += dp[i][j]) %= mod;
				(dp[i + 1][j] += dp[i][j] * max(0 , cnt[j] - i) % mod) %= mod;
			}
		}
		for(int j = 0 ; j < (1 << ts) ; j++ ) sum = (sum + dp[tt][j]) % mod;
		ans = ans * sum % mod; num[++tot] = tt - 1; ss += tt - 1;
//		cerr << sum << endl;
	}
	for(int i = 1 ; i <= tot ; i++ ) ans *= C(ss , num[i]) , ss -= num[i];
	printf("%lld" , ans);
	return 0;
}
/*
20
10 50 39 6 47 35 37 26 12 15 11 9 46 45 7 16 21 31 18 23
*/