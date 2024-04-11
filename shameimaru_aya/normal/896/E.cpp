#include<bits/stdc++.h>
using namespace std;
int n , m , a[1100000] , rt[330000] , fa[1100] , siz[1100];
int pl[1100000] , ans[550000] , mx , tag , L , R; 
const int sz = 1000; 
struct query
{
	int opt , l , r , x;
} q[550000];
inline int getf( int x )
{
	int u = x;
	while(u != fa[u]) u = fa[u];
	while(x != u)
	{
		int qwq = fa[x];
		fa[x] = u;
		x = qwq;
	}
	return u;
}
inline void trans( int s , int t )
{
	if(!rt[s]) return ;
	if(!rt[t]) 
	{
		swap(rt[s] , rt[t]);
		pl[rt[s]] = 0; pl[rt[t]] = t;
		return ;
	}
	if(rt[t] < rt[s])
	{
		siz[rt[t]] += siz[rt[s]] , siz[rt[s]] = 0;
		fa[rt[s]] = rt[t] , pl[rt[s]] = 0 , rt[s] = 0;
	}
	else
	{
		siz[rt[s]] += siz[rt[t]] , siz[rt[t]] = 0;
		fa[rt[t]] = rt[s] , pl[rt[s]] = t;
		rt[t] = rt[s] , rt[s] = 0;
	}
}
int main()
{
//	freopen("out.txt" , "r" , stdin);
//	freopen("test.txt" , "w" , stdout);
	scanf("%d%d" , &n , &m);
	for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]);
	for(int i = 1 ; i <= m ; i++ ) scanf("%d%d%d%d" , &q[i].opt , &q[i].l , &q[i].r , &q[i].x);
	for( L = 1 , R = min(sz , n) ; R <= n ; L = R + 1 , R = max(R + 1 , min(R + sz , n)) )
	{
		memset(fa , 0 , sizeof(fa)); memset(rt , 0 , sizeof(rt));
		memset(siz , 0 , sizeof(siz)); memset(pl , 0 , sizeof(pl)); mx = tag = 0;
		for(int i = L ; i <= R ; i++ )
		{
			if(!rt[a[i]]) rt[a[i]] = i - L + 1 , pl[i - L + 1] = a[i];
			fa[i - L + 1] = rt[a[i]];
			siz[rt[a[i]]]++;
			mx = max(mx , a[i]);
		}
		for(int i = 1 ; i <= m ; i++ )
		{
			if(q[i].r < L || R < q[i].l) continue;
			if(q[i].opt == 1)
			{
				if(q[i].x >= mx - tag) continue;
				if(q[i].l <= L && R <= q[i].r) 
				{
					if(2 * q[i].x < (mx - tag))
					{
						for(int j = tag + q[i].x ; j >= tag + 1 ; j-- ) trans(j , j + q[i].x);
						tag += q[i].x;
					}
					else
					{
						for(int j = q[i].x + tag + 1 ; j <= mx ; j++ ) trans(j , j - q[i].x);
						mx = q[i].x + tag; 
					}
				}
				else
				{
					for(int j = L ; j <= R ; j++ ) a[j] = pl[getf(j - L + 1)] - tag;
					for(int j = max(L , q[i].l) ; j <= min(R , q[i].r) ; j++ )
						if(a[j] > q[i].x) a[j] -= q[i].x;
					
					mx = tag = 0;
					for(int j = L ; j <= R ; j++ ) rt[pl[getf(j - L + 1)]] = 0;
					for(int j = L ; j <= R ; j++ ) pl[j - L + 1] = siz[j - L + 1] = 0;
					for(int j = L ; j <= R ; j++ ) fa[j - L + 1] = 0;
					
					for(int j = L ; j <= R ; j++ )
					{
						if(!rt[a[j]]) rt[a[j]] = j - L + 1 , pl[j - L + 1] = a[j];
						fa[j - L + 1] = rt[a[j]];
						siz[rt[a[j]]]++;
						mx = max(mx , a[j]);
					}
					
				}
			}
			else
			{
				if(q[i].l <= L && R <= q[i].r) ans[i] += siz[rt[q[i].x + tag]];
				else
				{
					for(int j = max(L , q[i].l) ; j <= min(R , q[i].r) ; j++ )
						ans[i] += (getf(j - L + 1) == rt[q[i].x + tag]);
				}
			} 
//			for(int j = L ; j <= R ; j++ ) cerr << pl[getf(j - L + 1)] - tag << ' '; cerr << endl;
		}
//		cerr << endl;
	}
	for(int i = 1 ; i <= m ; i++ ) 
		if(q[i].opt == 2) printf("%d\n" , ans[i]);
    return 0;
}
/*

*/