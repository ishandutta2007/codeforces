#include <bits/stdc++.h>
#define lson (id << 1)
#define rson (id << 1 | 1)
using namespace std;
int n , m , ans[110000] , sum , tot , l[110000] , r[110000] , it , las;
struct item
{
	int l , r , val , id;
	bool operator < ( const item &x ) const
	{
		return val > x.val;
	}
} a[110000];
struct node
{
	int val , ls , rs;
} c[28800000];
void build( int l , int r , int id )
{
	tot = max(tot , id);
	if(l == r) return ;
	int mid = l + r >> 1;
	build(l , mid , lson); build(mid + 1 , r , rson);
	return ;
}
void upd_x( int l , int r , int a , int b , int &id )
{
	if(a < l || r < a) return ;
	if(!id) id = ++tot , c[tot].val = 1e9;
	if(l == r)
	{
		c[id].val = min(c[id].val , b);
		return ;
	}
	int mid = l + r >> 1;
	upd_x(l , mid , a , b , c[id].ls); upd_x(mid + 1 , r , a , b , c[id].rs); 
	c[id].val = min(c[c[id].ls].val , c[c[id].rs].val);
	return ;
}
int ask_x( int l , int r , int a , int b , int id )
{
	if(b < l || r < a || !id) return 1e9;
	if(a <= l && r <= b) return c[id].val;
	int mid = l + r >> 1;
	return min(ask_x(l , mid , a , b , c[id].ls) , ask_x(mid + 1 , r , a , b , c[id].rs)); 
}
void upd_y( int l , int r , int a , int b , int y , int id )
{
	if(a < l || r < a) return ;
	if(l == r)
	{
		upd_x(1 , n , y , b , id);
		return ;
	}
	int mid = l + r >> 1;
	upd_y(l , mid , a , b , y , lson); upd_y(mid + 1 , r , a , b , y , rson); 
	upd_x(1 , n , y , b , id);
	return ;
}
int ask_y( int l , int r , int a , int b , int ay , int by , int id )
{
	if(b < l || r < a) return 1e9;
	if(a <= l && r <= b) return ask_x(1 , n , ay , by , id);
	int mid = l + r >> 1;
	return min(ask_y(l , mid , a , b , ay , by , lson) , ask_y(mid + 1 , r , a , b , ay , by , rson)); 
}
void solve( int ll , int rr )
{
	if(ll > rr || ll <= 0 || rr > n) return ;
	int a = ask_y(1 , n , ll , rr , ll , rr , 1);
	if(a == 1e9) return ;
	int L = l[a] , R = r[a];
	sum += R - L + 1;
	solve(ll , L - 1); solve(R + 1 , rr);
	return ;
}
int main()
{
//	freopen("1.in" , "r" , stdin);
	c[0].val = 1e9;
	scanf("%d%d" , &n , &m); it = n + 1; las = n;
	for(int i = 1 ; i <= m ; i++ )
	{
		scanf("%d%d" , &a[i].l , &a[i].r) , a[i].val = a[i].r - a[i].l + 1; a[i].id = i;
		l[i] = a[i].l; r[i] = a[i].r;
	}
	sort(a + 1 , a + m + 1);
	build(1 , n , 1);
	for(int i = 1 ; i <= tot ; i++ ) c[i].val = 1e9;
	for(int i = 1 ; i <= m ; i++ )
	{
		while(it > a[i].val + 1) ans[--it] = ans[las];
		upd_y(1 , n , a[i].l , a[i].id , a[i].r , 1);
		las = a[i].val;
		if(a[i + 1].val == a[i].val) continue;
		sum = 0;
		solve(1 , n);
//		if(i == 7646) cerr << 111111;
		ans[a[i].val] = sum;
	}
	int t = 1;
//	cerr << ask_x(1 , n , 1 , n , t) << endl;
	while(it > 1) ans[--it] = ans[las];
	for(int i = 1 ; i <= n ; i++ ) printf("%d\n" , ans[i]);
	return 0;
}
/*
9 5
1 5
3 9
2 9
3 7
6 7
*/