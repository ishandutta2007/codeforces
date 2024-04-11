#include <bits/stdc++.h>
#define lson (id << 1)
#define rson (id << 1 | 1)
using namespace std;
int T , n , m , x[220000] , y[220000] , f[550000] , cnt , tot , c[2200000] , id[550000];
long long fac[550000] , inv[550000] , inc[550000];
const int mod = 998244353 , N = 200000;
void init()
{
	fac[0] = inv[0] = inv[1] = inc[0] = 1;
	for(int i = 1 ; i <= 500000 ; i++ ) fac[i] = fac[i - 1] * i % mod;
	for(int i = 2 ; i <= 500000 ; i++ ) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
	for(int i = 1 ; i <= 500000 ; i++ ) inc[i] = inc[i - 1] * inv[i] % mod;
}
long long C( int a , int b )
{
	return fac[a] * inc[b] % mod * inc[a - b] % mod;
}
void build( int l , int r , int id )
{
	if(l == r) 
	{
		c[id] = 1;
		return ;
	}
	int mid = l + r >> 1;
	build(l , mid , lson); build(mid + 1 , r , rson);
	c[id] = c[lson] + c[rson];
	return ;
}
void upd( int l , int r , int a , int b , int id )
{
	if(r < a || a < l) return ;
	if(l == r) 
	{
		c[id] = b;
		return ;
	}
	int mid = l + r >> 1;
	upd(l , mid , a , b , lson); upd(mid + 1 , r , a , b , rson);
	c[id] = c[lson] + c[rson];
	return ;
}
int find( int l , int r , int k , int id )
{
	if(l == r) return l;
	int mid = l + r >> 1;
	if(c[lson] >= k) return find(l , mid , k , lson);
	return find(mid + 1 , r , k - c[lson] , rson);
}
int main()
{
	init(); build(1 , N , 1);
	scanf("%d" , &T);
	for(int ttt = 1 ; ttt <= T ; ttt++ )
	{
		scanf("%d%d" , &n , &m); cnt = tot = 0;
		for(int i = 1 ; i <= m ; i++ ) scanf("%d%d" , &x[i] , &y[i]);
		for(int i = m ; i >= 1 ; i-- )
		{
			int qwq = find(1 , N , y[i] + 1 , 1);
			if(f[qwq] != ttt) f[qwq] = ttt , cnt++;
			qwq = find(1 , N , y[i] , 1);
			upd(1 , N , qwq , 0 , 1); id[++tot] = qwq;
		}
//		cerr << cnt << endl;
		printf("%lld\n" , C(n + n - cnt - 1 , n - cnt - 1));
		while(tot)
		{
			upd(1 , N , id[tot] , 1 , 1); tot--;
		}
	}
	return 0;
}
/*
4
3 0
3 2
2 1
3 1
5 3
3 1
4 1
5 3
5 3
3 1
4 1
5 3
*/