#include <bits/stdc++.h>
#define F first
#define S second
#define pr pair< int , int >
using namespace std;
int n , m , x , y , d[220000] , rt[220000];
int fst[220000] , v[440000] , nex[440000] , tot , ans[220000];
vector< pr > q[220000];
struct D
{
	long long k , b;
	D operator + ( const D &x ) const
	{
		return (D){k + x.k , b + x.b};
	}
} qq;
struct item
{
	D val; int ls , rs;
} c[220000 * 20];
void add( int a , int b )
{
	nex[++tot] = fst[a]; fst[a] = tot;
	v[tot] = b;
}
void upd( int l , int r , int a , D d , int &id )
{
	if(a < l || r < a) return ;
	if(!id) id = ++tot;
	if(l == r)
	{
		c[id].val = c[id].val + d;
//		c[id].val.k -= d; c[id].val.b += 1ll * d * l;
		return ;
	}
	int mid = l + r >> 1;
	upd(l , mid , a , d , c[id].ls); upd(mid + 1 , r , a , d , c[id].rs); 
	c[id].val = c[c[id].ls].val + c[c[id].rs].val;
}
void clear( int l , int r , int a , int b , int &id )
{
	if(b < l || r < a || !id) return ;
	if(a <= l && r <= b) 
	{
		id = 0;
		return ;
	}
	int mid = l + r >> 1;
	clear(l , mid , a , b , c[id].ls); clear(mid + 1 , r , a , b , c[id].rs); 
	c[id].val = c[c[id].ls].val + c[c[id].rs].val;
}
D ask( int l , int r , int a , int b , int id )
{
	if(b < l || r < a || !id) return (D){0 , 0};
	if(a <= l && r <= b) return c[id].val;
	int mid = l + r >> 1;
	return ask(l , mid , a , b , c[id].ls) + ask(mid + 1 , r , a , b , c[id].rs); 
}
void merge( int l , int r , int &id1 , int id2 )
{
	if(!id1 || !id2) return id1 += id2 , void();
	if(l == r) return c[id1].val = c[id1].val + c[id2].val , void();
	int mid = l + r >> 1;
	merge(l , mid , c[id1].ls , c[id2].ls); merge(mid + 1 , r , c[id1].rs , c[id2].rs); 
	c[id1].val = c[c[id1].ls].val + c[c[id1].rs].val;
}
long long val( int x , int b , int id )
{
	D w = ask(0 , 200000 , x , 200000 , id);
	return w.k * x + b + w.b;
}
void dfs( int u , int fa )
{
	for(int i = fst[u] ; i ; i = nex[i] )
	{
		if(v[i] == fa) continue;
		dfs(v[i] , u); merge(0 , 200000 , rt[u] , rt[v[i]]);
	}
	
	
	for(pr p : q[u]) ans[p.S] = val(p.F , d[u] , rt[u]);
	upd(0 , 200000 , 200000 , (D){-1 , 0} , rt[u]);
	int l = 0 , r = 200000 , ans = 200001;
//	qq = ask(0 , 200000 , 0 , 200000 , rt[u]);
//	cerr << u << ' ' << val(0 , d[u] , rt[u]) << ' ' << qq.k << ' ' << qq.b << endl;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(val(mid , d[u] , rt[u]) <= 1) ans = mid , r = mid - 1;
		else l = mid + 1;
	}
	long long w = val(ans , d[u] , rt[u]);
	D qwq = ask(0 , 200000 , ans , 200000 , rt[u]); 
//	cerr << ans << ' ' << qwq.k << ' ' << w << ' ' << qwq.b << endl;
	qwq.b += d[u] - 1;
	clear(0 , 200000 , ans , 200000 , rt[u]); upd(0 , 200000 , ans - 1 , qwq , rt[u]); 
	
//	qq = ask(0 , 200000 , 0 , 200000 , rt[u]);
//	cerr << ans << ' ' << qwq.k << ' ' << w << ' ' << qwq.b << endl;
//	cerr << u << ' ' << val(0 , 1 , rt[u]) << ' ' << qq.k << ' ' << qq.b << endl;
//	cerr << endl; 
	return ;
}
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &n);
	for(int i = 1 ; i < n ; i++ )
	{
		scanf("%d%d" , &x , &y); add(x , y); add(y , x); d[x]++; d[y]++;
	}
	tot = 0;
	for(int i = 2 ; i <= n ; i++ ) d[i]--;
	scanf("%d" , &m);
	for(int i = 1 ; i <= m ; i++ )
	{
		scanf("%d%d" , &x , &y); q[x].push_back({y , i});
	}
	dfs(1 , 1);
	for(int i = 1 ; i <= m ; i++ ) printf("%d\n" , ans[i]);
	return 0;
} 
/*
5
1 2
2 3
3 4
3 5
1
1 0
*/