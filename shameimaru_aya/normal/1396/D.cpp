#include<bits/stdc++.h>
#define lson id << 1
#define rson id << 1 | 1
using namespace std;
int n , m , k , xx , yy , px[2200] , py[2200] , noww , s[2200];
int num[2200] , l , r , nex[2200][2200] , pre[2200][2200] , las[2200];
long long ans;
vector< int > xc[2200] , xid[2200];
const int mod = 1e9 + 7; 
struct sgt
{
	int maxx[8800] , minn[8800] , lazy[8800];
	long long c[8800];
	void push_up( int id )
	{
		c[id] = c[lson] + c[rson];
		minn[id] = min(minn[lson] , minn[rson]);
		maxx[id] = max(maxx[lson] , maxx[rson]);
	}
	void build( int l , int r , int id )
	{
		if(l == r)
		{
			c[id] = 1ll * (px[l] - px[l - 1]) * (k - px[s[l]] + 1) % mod;
			maxx[id] = minn[id] = s[l];
			return ;
		}
		int mid = l + r >> 1;
		build(l , mid , lson); 
		build(mid + 1 , r , rson);
		push_up(id);
		return ;
	}
	void push_down( int l , int r , int id )
	{
		if(!lazy[id]) return ;
		int mid = l + r >> 1;
		maxx[lson] = minn[lson] = lazy[lson] = lazy[id];
		maxx[rson] = minn[rson] = lazy[rson] = lazy[id];
		c[lson] = 1ll * (px[mid] - px[l - 1]) * (k - px[lazy[id]] + 1) % mod;
		c[rson] = 1ll * (px[r] - px[mid]) * (k - px[lazy[id]] + 1) % mod;
		lazy[id] = 0;
		return ;
	}
	long long ask( int l , int r , int a , int b , int id )
	{
		if(b < l || r < a) return 0;
		if(a <= l && r <= b) return c[id];
		push_down(l , r , id);
		int mid = l + r >> 1;
		return (ask(l , mid , a , b , lson) + ask(mid + 1 , r , a , b , rson)) % mod;
	}
	void upd( int l , int r , int a , int b , int val , int id )
	{
		if(b < l || r < a || minn[id] >= val) return ;
		if(a <= l && r <= b && maxx[id] <= val)
		{
			lazy[id] = maxx[id] = minn[id] = val;
			c[id] = 1ll * (px[r] - px[l - 1]) * (k - px[val] + 1) % mod;
			return ;
		}
		push_down(l , r , id);
		int mid = l + r >> 1;
		upd(l , mid , a , b , val , lson);
		upd(mid + 1 , r , a , b , val , rson);
		push_up(id);
		return ;
	}
} t[2200];
struct item
{
	int x , y , c;
	bool operator < ( const item &a ) const
	{
		if(y == a.y) return x < a.x;
		return y < a.y;
	}
} node[2200];
int main()
{
	scanf("%d%d%d" , &n , &m , &k);
	for(int i = 1 ; i <= n ; i++ )
	{
		scanf("%d%d%d" , &node[i].x , &node[i].y , &node[i].c);
		node[i].x++; node[i].y++;
		px[i] = node[i].x , py[i] = node[i].y;
	}
	sort(px + 1 , px + n + 1); xx = unique(px + 1 , px + n + 1) - px - 1;
	sort(py + 1 , py + n + 1); yy = unique(py + 1 , py + n + 1) - py - 1;
	for(int i = 1 ; i <= n ; i++ )
	{
		node[i].x = lower_bound(px + 1 , px + xx + 1 , node[i].x) - px;
		node[i].y = lower_bound(py + 1 , py + yy + 1 , node[i].y) - py;
	}
	sort(node + 1 , node + n + 1);
	node[n + 1].x = xx + 1; px[xx + 1] = k + 1;
	node[n + 1].y = yy + 1; py[yy + 1] = k + 1;
	for(int i = 1 ; i <= yy ; i++ )
	{
		while(node[++noww].y <= i)
		{
			xc[node[noww].x].push_back(node[noww].c);
			xid[node[noww].x].push_back(noww);
		}
		noww--;
		r = 0; l = 1;
		memset(las , 0 , sizeof(las));
		for(int j = 1 ; j <= xx ; j++ )
		{
			for(int qwq = 0 ; qwq < xc[j].size() ; qwq++ ) 
			{
				pre[i][xid[j][qwq]] = las[xc[j][qwq]];
				nex[i][las[xc[j][qwq]]] = xid[j][qwq];
				las[xc[j][qwq]] = xid[j][qwq];
			}
		}
//		for(int qwq = 1 ; qwq <= noww ; qwq++ ) cerr << pre[i][qwq] << ' ';
//		cerr << endl;
//		for(int qwq = 1 ; qwq <= noww ; qwq++ ) cerr << nex[i][qwq] << ' ';
//		cerr << endl;
		while(r < xx)
		{
			r++;
			for(int j = 0 ; j < xc[r].size() ; j++ ) 
			{
				num[xc[r][j]]++;
				if(num[xc[r][j]] == 1) num[0]++;
			}
			while(num[0] == m)
			{
				s[l] = r;
				for(int j = 0 ; j < xc[l].size() ; j++ ) 
				{
					num[xc[l][j]]--;
					if(!num[xc[l][j]]) num[0]--;
				}
				l++;
			}
		}
		while(l <= xx)
		{
			s[l] = xx + 1;
			for(int j = 0 ; j < xc[l].size() ; j++ ) 
			{
				num[xc[l][j]]--;
				if(!num[xc[l][j]]) num[0]--;
			}
			l++;
		}
//		for(int j = 1 ; j <= xx ; j++ ) cerr << s[j] << ' '; cerr << endl;
		t[i].build(1 , xx , 1);
//		cerr << t[i].ask(1 , xx , 1 , xx , 1) << ' ';
	}
	noww = 0;
	for(int i = 1 ; i <= yy ; i++ )
	{
		for(int j = i ; j <= yy ; j++ )
			ans = (ans + 1ll * t[j].ask(1 , xx , 1 , xx , 1) * (py[j + 1] - py[j]) % mod * (py[i] - py[i - 1])) % mod;
//		for(int j = i ; j <= yy ; j++ ) cerr << t[j].ask(1 , xx , 1 , xx , 1) << ' ';
		while(node[++noww].y <= i)
		{
			for(int j = i ; j <= yy ; j++ )
			{
				int val = node[nex[j][noww]].x;
//				cerr << noww << ' ' << nex[j][noww] << endl;
				if(!val) val = xx + 1;
				t[j].upd(1 , xx , node[pre[j][noww]].x + 1 , node[noww].x , val , 1);
				pre[j][nex[j][noww]] = pre[j][noww];
				nex[j][pre[j][noww]] = nex[j][noww];
			}
		}
		noww--;
	}
	printf("%lld" , ans);
    return 0;
}
/*
4 2 4
2 2 2
3 1 2
1 1 1
1 2 1
*/