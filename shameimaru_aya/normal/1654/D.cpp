#include<bits/stdc++.h>
using namespace std;
int T , n , a[220000] , mx[220000] , b[220000] , x , y , xx , yy;
long long ans , s;
const int mod = 998244353;
vector< int > son[220000] , xval[220000] , yval[220000] , d[220000] , num[220000];
long long exp( int a , int b )
{
	long long ans = 1 , t = a;
	while(b)
	{
		if(b & 1) ans = ans * t % mod;
		t = t * t % mod; b >>= 1;
	}
	return ans;
}
void dfs1( int u , int fa )
{
	for(int i = 0 ; i < son[u].size() ; i++ )
	{
		int v = son[u][i];
		if(v == fa) continue;
		for(int j = 0 ; j < d[xval[u][i]].size() ; j++ )
		{
			int w = xval[u][i];
			b[d[w][j]] -= num[w][j]; 
		}
		for(int j = 0 ; j < d[yval[u][i]].size() ; j++ )
		{
			int w = yval[u][i];
			b[d[w][j]] += num[w][j]; mx[d[w][j]] = max(mx[d[w][j]] , b[d[w][j]]);
		}
		dfs1(v , u);
		for(int j = 0 ; j < d[xval[u][i]].size() ; j++ )
		{
			int w = xval[u][i];
			b[d[w][j]] += num[w][j]; 
		}
		for(int j = 0 ; j < d[yval[u][i]].size() ; j++ )
		{
			int w = yval[u][i];
			b[d[w][j]] -= num[w][j]; 
		}
	}
}
void dfs2( int u , int fa , long long w )
{
	(ans += w) %= mod;
	for(int i = 0 ; i < son[u].size() ; i++ )
	{
		int v = son[u][i];
		if(v == fa) continue;
		dfs2(v , u , w * xval[u][i] % mod * exp(yval[u][i] , mod - 2) % mod);
	}
}
int main()
{
	n = 200000;
	for(int i = 1 ; i <= n ; i++ )
	{
		int qwq = i;
		for(int j = 2 ; j * j <= n ; j++ )
		{
			int w = 0;
			while(qwq % j == 0) qwq /= j , w++;
			if(w) d[i].push_back(j) , num[i].push_back(w);
		}
		if(qwq) d[i].push_back(qwq) , num[i].push_back(1);
	}
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n); ans = 0;
		for(int i = 1 ; i <= n ; i++ ) 
		{
			mx[i] = b[i] = 0; son[i].clear(); xval[i].clear(); yval[i].clear(); 
		}
		for(int i = 1 ; i < n ; i++ )
		{
			scanf("%d%d%d%d" , &x , &y , &xx , &yy);
			int g = __gcd(xx , yy); xx /= g; yy /= g;
			son[x].push_back(y); xval[x].push_back(yy); yval[x].push_back(xx); 
			son[y].push_back(x); xval[y].push_back(xx); yval[y].push_back(yy); 
		}
		dfs1(1 , 1); s = 1;
		for(int i = 1 ; i <= n ; i++ ) s = s * exp(i , mx[i]) % mod;
//		cerr << s << endl;
		dfs2(1 , 1 , s);
		printf("%lld\n" , ans);
	}
	return 0;
}
/*
*/