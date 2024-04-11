#include<bits/stdc++.h>
#define lson id << 1
#define rson id << 1 | 1
using namespace std;
struct item
{
	int num , l , r , id;
} sav[440000];
bool cmp1( item a , item b )
{
	if(a.num == b.num) return a.id < b.id;
	return a.num < b.num;
}
bool cmp2( item a , item b )
{
	if(a.num == b.num) return a.id < b.id;
	return a.num > b.num;
}
int n , m , opt , x[110000] , ly[110000] , ry[110000] , tot , totx , toty;
int y[110000] , lx[110000] , rx[110000] , px[440000] , py[440000];
long long c[2000000] , ans , tag[2000000];
void build( int l , int r , int id )
{
	tag[id] = 0;
	if(l == r)
	{
		c[id] = 0;
		return ;
	}
	int mid = l + r >> 1;
	build(l , mid , lson);
	build(mid + 1 , r , rson);
	c[id] = c[lson] + c[rson];
	return ;
}
inline void push_down( int l , int r , int id )
{
	int mid = l + r >> 1;
	c[lson] += tag[id] * (mid - l + 1); c[rson] += tag[id] * (r - mid);
	tag[lson] += tag[id]; tag[rson] += tag[id]; 
	tag[id] = 0;
}
void upd( int l , int r , int a , int b , int x , int id )
{
	if(b < l || r < a) return ;
	if(a <= l && r <= b)
	{
		c[id] += 1ll * (r - l + 1) * x;
		tag[id] += x;
		return ;
	}
	push_down(l , r , id);
	int mid = l + r >> 1;
	upd(l , mid , a , b , x , lson);
	upd(mid + 1 , r , a , b , x , rson);
	c[id] = c[lson] + c[rson];
}
long long ask( int l , int r , int a , int id )
{
	if(a < l || r < a) return 0;
	if(a <= l && r <= a) return c[id];
	push_down(l , r , id);
	int mid = l + r >> 1;
	return ask(l , mid , a , lson) + ask(mid + 1 , r , a , rson);
}
int main()
{
	scanf("%d%d" , &n , &m);
	for(int i = 1 ; i <= n ; i++ )
	{
		scanf("%d%d%d" , &y[i] , &lx[i] , &rx[i]);
		if(lx[i] == 0 && rx[i] == 1e6) ans++;
		py[++toty] = y[i] , px[++totx] = lx[i] , px[++totx] = rx[i]; 
	}
	for(int i = 1 ; i <= m ; i++ )
	{
		scanf("%d%d%d" , &x[i] , &ly[i] , &ry[i]);
		if(ly[i] == 0 && ry[i] == 1e6) ans++;
		px[++totx] = x[i] , py[++toty] = ly[i] , py[++toty] = ry[i]; 
	}
	px[++totx] = 0; px[++totx] = 1e6; py[++toty] = 0; py[++toty] = 1e6; 
	sort(px + 1 , px + totx + 1); totx = unique(px + 1 , px + totx + 1) - px - 1;
	sort(py + 1 , py + toty + 1); toty = unique(py + 1 , py + toty + 1) - py - 1;
	for(int i = 1 ; i <= n ; i++ )
	{
		y[i] = lower_bound(py + 1 , py + toty + 1 , y[i]) - py;
		lx[i] = lower_bound(px + 1 , px + totx + 1 , lx[i]) - px;
		rx[i] = lower_bound(px + 1 , px + totx + 1 , rx[i]) - px;
	}
	for(int i = 1 ; i <= m ; i++ )
	{
		x[i] = lower_bound(px + 1 , px + totx + 1 , x[i]) - px;
		ly[i] = lower_bound(py + 1 , py + toty + 1 , ly[i]) - py;
		ry[i] = lower_bound(py + 1 , py + toty + 1 , ry[i]) - py;
	}
	for(int i = 1 ; i <= n ; i++ ) sav[++tot] = (item){y[i] , lx[i] , rx[i] , 0};
	for(int i = 1 ; i <= m ; i++ )
		if(ly[i] == 1) sav[++tot] = (item){ry[i] , x[i] , x[i] , 1};
	sort(sav + 1 , sav + tot + 1 , cmp1);
	for(int i = 1 ; i <= tot ; i++ )
	{
		if(!sav[i].id)
			upd(1 , totx , sav[i].l , sav[i].r , 1 , 1);
		else
			ans += ask(1 , totx , sav[i].l , 1);
	}
//	cerr << ans << endl;
	tot = 0; build(1 , totx , 1);
	for(int i = 1 ; i <= n ; i++ ) sav[++tot] = (item){y[i] , lx[i] , rx[i] , 0};
	for(int i = 1 ; i <= m ; i++ )
		if(ly[i] != 1) sav[++tot] = (item){ly[i] , x[i] , x[i] , 1};
	sort(sav + 1 , sav + tot + 1 , cmp2);
	for(int i = 1 ; i <= tot ; i++ )
	{
//		cerr << sav[i].num << '\n';
		if(!sav[i].id)
			upd(1 , totx , sav[i].l , sav[i].r , 1 , 1);
		else
			ans += ask(1 , totx , sav[i].l , 1);
	}
	printf("%lld" , ans + 1);
    return 0;
}