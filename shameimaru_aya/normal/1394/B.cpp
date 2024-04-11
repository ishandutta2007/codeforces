#include<bits/stdc++.h>
using namespace std;
struct item
{
	int val , v;
	bool operator < ( const item &x )
	{
		return val < x.val;
	}
} e[220000][11];
int n , m , k , a , b , c , tot[220000] , val[220000] , ans;
const int mod[3] = {998244353 , (int)1e9 + 9 , (int)1e9 + 7};
struct hash_number
{
	int a[3];
	void init()
	{
		a[0] = a[2] = 0; a[1] = 1;
	}
	hash_number operator + ( const hash_number &x ) const
	{
		hash_number ans;
		ans.a[0] = (a[0] + x.a[0]) % mod[0];
		ans.a[1] = 1ll * a[1] * x.a[1] % mod[1];
		ans.a[2] = (a[2] + x.a[2]) % mod[2];
		return ans;
	}
	bool operator == ( const hash_number &x ) const
	{
		return (a[0] == x.a[0] && a[1] == x.a[1] && a[2] == x.a[2]);
	}
} s[10][10] , qwq , full;
inline hash_number create( int x )
{
	hash_number ans;
	ans.a[0] = ans.a[1] = ans.a[2] = x;
	return ans;
}
void dfs( int u , hash_number a )
{
	if(u > k)
	{
		if(a == full) ans++;
		return ;
	}
	for(int i = 1 ; i <= u ; i++ ) dfs(u + 1 , a + s[u][i]);
	return ;
}
int main()
{
	srand((unsigned)time(NULL));
	scanf("%d%d%d" , &n , &m , &k);
	full.init(); qwq.init();
	for(int i = 0 ; i <= k ; i++ )
		for(int j = 0 ; j <= i ; j++ ) s[i][j].init();
	for(int i = 1 ; i <= n ; i++ ) 
	{
		val[i] = 1ll * rand() * rand() % 1000000;
		full = full + create(val[i]);
	}
	for(int i = 1 ; i <= m ; i++ )
	{
		scanf("%d%d%d" , &a , &b , &c);
		e[a][++tot[a]] = (item){c , b};
	}
	for(int i = 1 ; i <= n ; i++ )
	{
		sort(&e[i][1] , &e[i][tot[i] + 1]);
		for(int j = 1 ; j <= tot[i] ; j++ )
			s[tot[i]][j] = s[tot[i]][j] + create(val[e[i][j].v]);
	}
	dfs(1 , qwq);
	printf("%d" , ans);
    return 0;
}//