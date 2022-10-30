#include <bits/stdc++.h>
using namespace std;
int n , m , q , lim , p[660000] , sum[660000] , tot , rt[330000] , cg[330000] , fr;
int ls[330000 * 20] , rs[330000 * 20] , only[330000] , k;
set< int > s;
vector< int > pl[660000];
struct item
{
	int l , r , c;
	bool operator < ( const item &x ) const
	{
		return c < x.c;
	}
} node[330000];
struct D
{
	int num , id;
	D operator + ( const D &x ) const
	{
		if(num + only[id] > x.num + only[x.id]) return (*this);
		return x;
	}
} c[330000 * 20];
void upd( int l , int r , int a , int d , int &id )
{
	if(a < l || r < a) return ;
	if(!id) id = ++tot;
	if(l == r)
	{
		c[id].num += d; c[id].id = l;
		return ;
	}
	int mid = l + r >> 1;
	upd(l , mid , a , d , ls[id]); upd(mid + 1 , r , a , d , rs[id]); 
	c[id] = c[ls[id]] + c[rs[id]];
}
D ask( int l , int r , int a , int b , int id )
{
	if(b < l || r < a || !id) return (D){-(int)1e8 , 0};
	if(a <= l && r <= b) return c[id];
	int mid = l + r >> 1;
	return ask(l , mid , a , b , ls[id]) + ask(mid + 1 , r , a , b , rs[id]);
}
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d%d" , &n , &lim);
	for(int i = 1 ; i <= n ; i++ ) 
	{
		scanf("%d%d%d" , &node[i].l , &node[i].r , &node[i].c);// node[i].r++;
		p[++m] = node[i].l , p[++m] = node[i].r; 
	}
	p[++m] = 0; p[++m] = 2e9;
	sort(node + 1 , node + n + 1);
	int it = 0; node[n + 1].c = lim + 1;
	for(int i = n ; i >= 1 ; i-- )
	{
		while(node[it + 1].c + node[i].c <= lim) it++;
		cg[i] = it;
	}
	sort(p + 1 , p + m + 1); m = unique(p + 1 , p + m + 1) - p - 1; 
	for(int i = 1 ; i <= n ; i++ )
	{
		node[i].l = lower_bound(p + 1 , p + m + 1 , node[i].l) - p; pl[node[i].l].push_back(i);
		node[i].r = lower_bound(p + 1 , p + m + 1 , node[i].r) - p; pl[node[i].r].push_back(-i);
	}
	for(int i = 1 ; i < m ; i++ )
	{
		int len = p[i + 1] - p[i];
		for(int u : pl[i])
		{
//			cerr << i << ' ' << u << endl;
			if(u > 0) s.insert(u);
			else s.erase(-u);
		}
//		cerr << s.size() << ' ';
		if(s.size() > 2) 
		{
			sum[i] = sum[i - 1];
			continue;
		}
		if(s.size() == 0)
		{
			sum[i] = sum[i - 1] + len; fr += len;
			continue;
		}
		if(s.size() == 2)
		{
			int a = *s.begin() , b = *s.rbegin();
			if(node[a].c + node[b].c <= lim)
			{
				upd(1 , n , a , len , rt[b]);
				upd(1 , n , b , len , rt[a]);
				int qwq = only[a] + only[b] + ask(1 , n , a , a , rt[b]).num;
//				cerr << qwq << endl;
				sum[i] = max(sum[i - 1] , fr + qwq);
			}
			else sum[i] = sum[i - 1];
		}
		if(s.size() == 1)
		{
			int a = *s.begin();
			only[a] += len;
			upd(1 , n , a , 0 , rt[0]); 
			D pp = c[rt[a]];
			int la = ask(1 , n , 1 , min(a - 1 , cg[a]) , rt[0]).id;
			int ra = ask(1 , n , a + 1 , cg[a] , rt[0]).id;
			int qwq = only[a] + max(0 , max(pp.num + only[pp.id] , max(only[la] , only[ra])));
			if(node[a].c <= lim) sum[i] = max(sum[i - 1] , fr + qwq);
			else sum[i] = sum[i - 1];
		}
	}
//	for(int i = 1 ; i < m ; i++ ) cerr << sum[i] << ' '; cerr << endl;
	scanf("%d" , &q);
	while(q--)
	{
		scanf("%d" , &k);
		int l = 1 , r = m - 1 , ans = 0;
		while(l <= r)
		{
			int mid = l + r >> 1;
			if(sum[mid] >= k) ans = mid , r = mid - 1;
			else l = mid + 1;
		}
//		cerr << ans << ' ' << sum[ans] << ' ' << k << endl;
		int d = sum[ans] - k;
		printf("%d\n" , p[ans + 1] - d);
	}
	return 0;
} 
/*
*/