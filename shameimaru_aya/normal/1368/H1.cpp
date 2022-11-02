#include<bits/stdc++.h>
using namespace std;
int n , m , q , a[4][110000] , lazy1[880000] , lazy2[880000] , opt , x , y;
string s;
inline int read_opt()
{
	char c = getchar();
	while(c != 'L' && c != 'R' && c != 'U' && c != 'D') c = getchar();
	if(c == 'L') return 0;
	if(c == 'R') return 1;
	if(c == 'U') return 2;
	if(c == 'D') return 3;
}
struct matrix
{
	int a[3][3] , r , c;
	inline void init( int x , int y , int m )
	{
		r = c = 2;
		a[1][1] = x; a[2][1] = y + m;
		a[1][2] = x + m; a[2][2] = y;
		return ;
	}
	matrix operator + ( const matrix &x ) const
	{
		matrix ans; ans.r = r; ans.c = c;
		for(int i = 1 ; i <= r ; i++ )
			for(int j = 1 ; j <= c ; j++ ) ans.a[i][j] = a[i][j] + x.a[i][j];
		return ans;
	}
	matrix operator * ( const matrix &x ) const
	{
		matrix ans; ans.r = r; ans.c = x.c;
		for(int i = 1 ; i <= r ; i++ )
		{
			for(int j = 1 ; j <= x.c ; j++ )
			{
				ans.a[i][j] = 5e8;
				for(int k = 1 ; k <= c ; k++ )
					ans.a[i][j] = min(ans.a[i][j] , a[i][k] + x.a[k][j]);
			}
		}
		return ans;
	}
	inline void print()
	{
		for(int i = 1 ; i <= r ; i++ )
		{
			for(int j = 1 ; j <= c ; j++ ) printf("%d " , a[i][j]);
			printf("\n");
		}
		printf("\n");
		return ;
	}
} hst , hfn , lst , lfn;
struct sgt
{
	#define lson (id << 1)
	#define rson (id << 1 | 1)
	int c1[880000] , c2[880000] , c[880000] , lazy[880000] , xx , yy;
	inline void push_down( int l , int r , int id )
	{
		int mid = l + r >> 1;
		if(lazy[id] & 1)
			c1[lson] = mid - l + 1 - c1[lson] , c1[rson] = r - mid - c1[rson];
		if(lazy[id] & 2)
			c2[lson] = mid - l + 1 - c2[lson] , c2[rson] = r - mid - c2[rson];
		lazy[lson] ^= lazy[id]; lazy[rson] ^= lazy[id]; lazy[id] = 0; 
	}
	void build( int l , int r , int id )
	{
		if(l == r)
		{
			c1[id] = a[xx][l]; c2[id] = a[yy][l]; 
			return ;
		}
		int mid = l + r >> 1;
		build(l , mid , lson); build(mid + 1 , r , rson);
		c1[id] = c1[lson] + c1[rson]; c2[id] = c2[lson] + c2[rson]; 
		return ;
	}
	void upd( int l , int r , int a , int b , int d , int id )
	{
		if(b < l || r < a) return ;
		if(a <= l && r <= b)
		{
			if(d & 1) c1[id] = r - l + 1 - c1[id];
			if(d & 2) c2[id] = r - l + 1 - c2[id];
			lazy[id] ^= d;
			return ;
		}
		push_down(l , r , id);
		int mid = l + r >> 1;
		upd(l , mid , a , b , d , lson); upd(mid + 1 , r , a , b , d , rson);
		c1[id] = c1[lson] + c1[rson]; c2[id] = c2[lson] + c2[rson]; 
		return ;
	}
	#undef lson
	#undef rson
} t1 , t2;
struct sgt_mtx
{
	#define lson (id << 1)
	#define rson (id << 1 | 1)
	matrix c[880000][2][2]; int lazy[880000] , xx , yy , m;
	inline void push_down( int id )
	{
		if(lazy[id] & 1)
		{
			swap(c[lson][0][0] , c[lson][1][0]) , swap(c[lson][0][1] , c[lson][1][1]);
			swap(c[rson][0][0] , c[rson][1][0]) , swap(c[rson][0][1] , c[rson][1][1]);
		}
		if(lazy[id] & 2)
		{
			swap(c[lson][0][0] , c[lson][0][1]) , swap(c[lson][1][0] , c[lson][1][1]);
			swap(c[rson][0][0] , c[rson][0][1]) , swap(c[rson][1][0] , c[rson][1][1]);
		}
		lazy[lson] ^= lazy[id]; lazy[rson] ^= lazy[id]; lazy[id] = 0; 
	}
	inline void push_up( int id )
	{
		for(int i = 0 ; i <= 1 ; i++ )
			for(int j = 0 ; j <= 1 ; j++ ) c[id][i][j] = c[lson][i][j] * c[rson][i][j];
		return ;
	}
	void build( int l , int r , int id )
	{
		if(l == r)
		{
			c[id][0][0].init(a[xx][l] + a[yy][l] , (a[xx][l] ^ 1) + (a[yy][l] ^ 1) , m);
			c[id][1][0].init((a[xx][l] ^ 1) + a[yy][l] , a[xx][l] + (a[yy][l] ^ 1) , m); 
			c[id][0][1].init(a[xx][l] + (a[yy][l] ^ 1) , (a[xx][l] ^ 1) + a[yy][l] , m);
			c[id][1][1].init((a[xx][l] ^ 1) + (a[yy][l] ^ 1) , a[xx][l] + a[yy][l] , m);
//			cerr << l << endl; c[id][0][0].print();
			return ;
		}
		int mid = l + r >> 1;
		build(l , mid , lson); build(mid + 1 , r , rson);
		push_up(id);
		return ;
	}
	void upd( int l , int r , int a , int b , int d , int id )
	{
		if(b < l || r < a) return ;
		if(a <= l && r <= b)
		{
			if(d & 1) swap(c[id][0][0] , c[id][1][0]) , swap(c[id][0][1] , c[id][1][1]);
			if(d & 2) swap(c[id][0][0] , c[id][0][1]) , swap(c[id][1][0] , c[id][1][1]);
			lazy[id] ^= d;
			return ;
		}
		push_down(id);
		int mid = l + r >> 1;
		upd(l , mid , a , b , d , lson); upd(mid + 1 , r , a , b , d , rson);
		push_up(id);
		return ;
	}
	#undef lson
	#undef rson
} h , l;
inline void get_sf()
{
	hst.r = hfn.r = lst.r = lfn.r = 1; hst.c = hfn.c = lst.c = lfn.c = 2;
	hst.a[1][1] = t1.c1[1]; hst.a[1][2] = n - t1.c1[1];
	hfn.a[1][1] = t1.c2[1]; hfn.a[1][2] = n - t1.c2[1];
	lst.a[1][1] = t2.c1[1]; lst.a[1][2] = m - t2.c1[1];
	lfn.a[1][1] = t2.c2[1]; lfn.a[1][2] = m - t2.c2[1];
	return ;
}
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d%d%d" , &n , &m , &q);
	h.xx = 2 , h.yy = 3 , h.m = n; l.xx = 0 , l.yy = 1 , l.m = m;
	t1.xx = 0 , t1.yy = 1; t2.xx = 2 , t2.yy = 3; 
	cin >> s;
	for(int i = 0 ; i < n ; i++ ) a[0][i + 1] = (s[i] == 'B');
	cin >> s;
	for(int i = 0 ; i < n ; i++ ) a[1][i + 1] = (s[i] == 'B');
	cin >> s;
	for(int i = 0 ; i < m ; i++ ) a[2][i + 1] = (s[i] == 'B');
	cin >> s;
	for(int i = 0 ; i < m ; i++ ) a[3][i + 1] = (s[i] == 'B');
	t1.build(1 , n , 1); t2.build(1 , m , 1); h.build(1 , m , 1); l.build(1 , n , 1); 
	get_sf();  
//	l.c[1][0][0].print();
	matrix hqwq = (hst * h.c[1][0][0]) + hfn;
	matrix lqwq = (lst * l.c[1][0][0]) + lfn;
	printf("%d\n" , min(min(hqwq.a[1][1] , hqwq.a[1][2]) , min(lqwq.a[1][1] , lqwq.a[1][2])));
	while(q--)
	{
		opt = read_opt(); scanf("%d%d" , &x , &y); 
		if(opt == 0) t1.upd(1 , n , x , y , 1 , 1) , l.upd(1 , n , x , y , 1 , 1);
		if(opt == 1) t1.upd(1 , n , x , y , 2 , 1) , l.upd(1 , n , x , y , 2 , 1);
		if(opt == 2) t2.upd(1 , m , x , y , 1 , 1) , h.upd(1 , m , x , y , 1 , 1);
		if(opt == 3) t2.upd(1 , m , x , y , 2 , 1) , h.upd(1 , m , x , y , 2 , 1);
		get_sf();
		hqwq = (hst * h.c[1][0][0]) + hfn;
		lqwq = (lst * l.c[1][0][0]) + lfn;
		printf("%d\n" , min(min(hqwq.a[1][1] , hqwq.a[1][2]) , min(lqwq.a[1][1] , lqwq.a[1][2])));
	}
	return 0;
}