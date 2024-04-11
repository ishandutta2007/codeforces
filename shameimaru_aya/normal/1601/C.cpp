#include <bits/stdc++.h>
#define lson (id << 1)
#define rson (id << 1 | 1)
#define lowbit(x) (x & (-x))
using namespace std;
int T , n , m , a[2200000] , b[2200000] , t[4400000] , p[4400000] , lazy[8800000] , L;
long long ans;
struct item
{
	int num , id;
	item operator + ( const item &x ) const
	{
		if(num < x.num) return *this;
		if(num > x.num) return x;
		return (item){num , min(id , x.id)};
	}
} c[8800000];
void build( int l , int r , int id )
{
	lazy[id] = 0;
	if(l == r)
	{
		c[id] = (item){l , l};
		return ;
	}
	int mid = l + r >> 1;
	build(l , mid , lson); build(mid + 1 , r , rson);
	c[id] = c[lson] + c[rson];
}
void push_down( int id )
{
	if(!lazy[id]) return ;
	lazy[lson] += lazy[id]; c[lson].num += lazy[id];
	lazy[rson] += lazy[id]; c[rson].num += lazy[id];
	lazy[id] = 0;
}
void upd( int l , int r , int a , int b , int d , int id )
{
	if(b < l || r < a) return ;
	if(a <= l && r <= b)
	{
		lazy[id] += d; c[id].num += d;
		return ;
	}
	push_down(id);
	int mid = l + r >> 1;
	upd(l , mid , a , b , d , lson); upd(mid + 1 , r , a , b , d , rson); 
	c[id] = c[lson] + c[rson];
}
item ask( int l , int r , int a , int b , int id )
{
	if(b < l || r < a) return (item){(int)1e9 , 0};
	if(a <= l && r <= b) return c[id];
	push_down(id);
	int mid = l + r >> 1;
	return ask(l , mid , a , b , lson) + ask(mid + 1 , r , a , b , rson); 
}
void add( int x , int a )
{
	while(x <= L)
	{
		t[x] += a;
		x += lowbit(x);
	}
}
int ask( int x )
{
	int ans = 0;
	while(x)
	{
		ans += t[x];
		x -= lowbit(x);
	}
	return ans;
}
long long getinv( int a[] , int n )
{
	L = n;
	long long ans = 0;
	for(int i = 1 ; i <= n ; i++ ) p[i] = a[i];
	sort(p + 1 , p + n + 1);
	for(int i = 1 ; i <= n ; i++ ) a[i] = lower_bound(p + 1 , p + n + 1 , a[i]) - p;
	for(int i = 1 ; i <= n ; i++ )
	{
		ans += ask(n) - ask(a[i]);
		add(a[i] , 1);
	}
	for(int i = 1 ; i <= n ; i++ ) add(a[i] , -1);
	return ans;
}
bool cmp( int x , int y )
{
	return a[x] < a[y];
}
int main()
{
//	freopen("1.in" , "r" , stdin);
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d%d" , &n , &m); ans = 0;
		for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]);
//		cerr << ans << endl;
		for(int i = 1 ; i <= n ; i++ ) p[i] = i;
		sort(p + 1 , p + n + 1 , cmp);
//		for(int i = 1 ; i <= n ; i++ ) cerr << p[i] << ' '; cerr << endl;
		for(int i = 1 ; i <= m ; i++ ) scanf("%d" , &b[i]);
		sort(b + 1 , b + m + 1);
		int lim = 0 , it1 = 1 , it2 = 1; build(0 , n , 1);
		for(int i = 1 ; i <= m ; i++ )
		{
//			if(!T && i >= 499900) cerr << i << endl;
			while(it1 <= n && a[p[it1]] < b[i])
			{
//				if(!T && i == 499991) cerr << p[it1] << ' ' << a[p[it1]] << ' ' << b[i] << endl;
//				cerr << p[it1] << ' ' << a[p[it1]] << ' ' << b[i] << endl;
				upd(0 , n , 0 , p[it1] - 1 , 1 , 1);
				it1++;
			}
//			if(!T && i == 499991) cerr << p[it1] << ' ' << a[p[it1]] << ' ' << b[i] << endl;
			while(it2 <= n && a[p[it2]] <= b[i])
			{
				upd(0 , n , p[it2] , n , -1 , 1);
				it2++;
			}
			item qwq = ask(0 , n , lim , n , 1);
//			cerr << qwq.id << ' ';
//			cerr << qwq.id << ' ' << qwq.num << endl;
			ans += qwq.num;
			lim = qwq.id;
		}
//		cerr << 111111 << endl;
//		cerr << endl;
		ans += getinv(a , n);
		printf("%lld\n" , ans);
	}
	return 0;
}
/*
3
10 10

*/