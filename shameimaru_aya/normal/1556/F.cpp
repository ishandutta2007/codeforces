#include <bits/stdc++.h>
using namespace std;
int n , ln , rn , N , a[20] , L , R;
long long inv[2200000] , f[1 << 14] , p[1 << 14] , g[4][1 << 7][1 << 7] , vis[4][1 << 7][1 << 7] , ans;
const int mod = 1e9 + 7;
long long win( int x , int y )
{
	return a[x] * inv[a[x] + a[y]] % mod;
}
long long G( int X , int Y )
{
//	cerr << X << ' ' << Y << ' ' << (X & L) << ' ' << ((X & R) >> (n / 2)) << ' ' << (Y & L) << ' ' << ((Y & R) >> (n / 2)) << ": ";
//	cerr << g[0][X & L][Y & L] << ' ' << g[1][X & L][(Y & R) >> (n / 2)] << ' ' << g[2][(X & R) >> (n / 2)][Y & L] << ' ' << g[3][(X & R) >> (n / 2)][(Y & R) >> (n / 2)] << endl;
	return g[0][X & L][Y & L] * g[1][X & L][(Y & R) >> (n / 2)] % mod
		 * g[2][(X & R) >> (n / 2)][Y & L] % mod
		 * g[3][(X & R) >> (n / 2)][(Y & R) >> (n / 2)] % mod;
}
int main()
{
	inv[0] = inv[1] = 1;
	for(int i = 2 ; i <= 2000000 ; i++ ) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
	scanf("%d" , &n); L = (1 << (n / 2)) - 1; N = (1 << n) - 1; R = N ^ L; ln = n / 2; rn = n - ln;
	for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]);
	g[0][0][0] = g[1][0][0] = g[2][0][0] = g[3][0][0] = 1;
	for(int i = 0 ; i <= N ; i++ )
	{
		int ll = i & L , rr = (i & R) >> (n / 2); 
		for(int j = 0 ; j < ln ; j++ )
		{
			int vl = ll | (1 << j);
			if(vis[0][vl][rr]) continue;
			vis[0][vl][rr] = 1;
			g[0][vl][rr] = g[0][ll][rr]; 
			for(int k = 1 ; k <= ln ; k++ )
			{
				if(!(rr & (1 << k - 1))) continue;
				g[0][vl][rr] = g[0][vl][rr] * win(j + 1 , k) % mod;
			}
		}
		for(int j = 0 ; j < ln ; j++ )
		{
			int vl = ll | (1 << j);
			if(vis[1][vl][rr]) continue;
			vis[1][vl][rr] = 1;
			g[1][vl][rr] = g[1][ll][rr]; 
			for(int k = ln + 1 ; k <= n ; k++ )
			{
				if(!(rr & (1 << k - ln - 1))) continue;
				g[1][vl][rr] = g[1][vl][rr] * win(j + 1 , k) % mod;
			}
		}
		for(int j = 0 ; j < rn ; j++ )
		{
			int vl = ll | (1 << j);
			if(vis[2][vl][rr]) continue;
			vis[2][vl][rr] = 1;
			g[2][vl][rr] = g[2][ll][rr]; 
			for(int k = 1 ; k <= ln ; k++ )
			{
				if(!(rr & (1 << k - 1))) continue;
				g[2][vl][rr] = g[2][vl][rr] * win(j + 1 + ln , k) % mod;
			}
		} 
		for(int j = 0 ; j < rn ; j++ )
		{
			int vl = ll | (1 << j);
			if(vis[3][vl][rr]) continue;
			vis[3][vl][rr] = 1;
			g[3][vl][rr] = g[3][ll][rr]; 
			for(int k = ln + 1 ; k <= n ; k++ )
			{
				if(!(rr & (1 << k - ln - 1))) continue;
				g[3][vl][rr] = g[3][vl][rr] * win(j + 1 + ln , k) % mod;
			}
		} 
		
		for(int j = 0 ; j < ln ; j++ )
		{
			int vr = rr | (1 << j);
			if(vis[0][ll][vr]) continue;
			vis[0][ll][vr] = 1;
			g[0][ll][vr] = g[0][ll][rr]; 
			for(int k = 1 ; k <= ln ; k++ )
			{
				if(!(ll & (1 << k - 1))) continue;
				g[0][ll][vr] = g[0][ll][vr] * win(k , j + 1) % mod;
			}
		}
		for(int j = 0 ; j < ln ; j++ )
		{
			int vr = rr | (1 << j);
			if(vis[2][ll][vr]) continue;
			vis[2][ll][vr] = 1;
			g[2][ll][vr] = g[2][ll][rr]; 
			for(int k = ln + 1 ; k <= n ; k++ )
			{
				if(!(ll & (1 << k - ln - 1))) continue;
				g[2][ll][vr] = g[2][ll][vr] * win(k , j + 1) % mod;
			}
		}
		for(int j = 0 ; j < rn ; j++ )
		{
			int vr = rr | (1 << j);
			if(vis[1][ll][vr]) continue;
			vis[1][ll][vr] = 1;
			g[1][ll][vr] = g[1][ll][rr]; 
			for(int k = 1 ; k <= ln ; k++ )
			{
				if(!(ll & (1 << k - 1))) continue;
				g[1][ll][vr] = g[1][ll][vr] * win(k , j + 1 + ln) % mod;
			}
		} 
		for(int j = 0 ; j < rn ; j++ )
		{
			int vr = rr | (1 << j);
			if(vis[3][ll][vr]) continue;
			vis[3][ll][vr] = 1;
			g[3][ll][vr] = g[3][ll][rr]; 
			for(int k = ln + 1 ; k <= n ; k++ )
			{
				if(!(ll & (1 << k - ln - 1))) continue;
				g[3][ll][vr] = g[3][ll][vr] * win(k , j + 1 + ln) % mod;
			}
		} 
	}
//	cerr << g[1][1][1] << endl;
	for(int i = 0 ; i <= N ; i++ )
	{
		p[i] = 1;
		for(int j = (i - 1) & i ; j ; j = (j - 1) & i )
			p[i] = (p[i] + mod - p[j] * G(j , i ^ j) % mod) % mod;
		f[i] = G(i , N ^ i) * p[i] % mod;
		(ans += f[i] * __builtin_popcount(i) % mod) %= mod;
	}
//	cerr << f[0] << ' ' << f[1] << ' ' << f[2] << ' ' << f[3] << endl;
//	cerr << G(1 , 2) << endl;
	printf("%lld" , ans);
	return 0; 
}
/*
*/