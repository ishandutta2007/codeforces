#include <bits/stdc++.h>
using namespace std;
int T , n , m , k , f[880000] , l[880000] , r[880000] , rp[880000];
int a[220000] , tot , id[880000] , R;
long long dp[880000] , p[880000];
struct line
{
	int l , r;
	bool operator < ( const line &x ) const
	{
		if(l == x.l) return r < x.r;
		return l > x.l;
	}
} node[220000];
struct item
{
	int l , r , tp;
	bool operator < ( const item &x ) const
	{
		return l < x.l;
	}
} x[440000];
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &T);
	while(T--)
	{
		int tst = 0;
		scanf("%d%d" , &n , &m); tot = 0;
		for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]) , p[++tot] = a[i];
		if(a[1] == 506250553) tst = 1;
		sort(a + 1 , a + n + 1);
		for(int i = 1 ; i <= m ; i++ ) 
			scanf("%d%d" , &node[i].l , &node[i].r) , p[++tot] = node[i].l , p[++tot] = node[i].r;
		sort(p + 1 , p + tot + 1);
		for(int i = 1 ; i <= n ; i++ ) a[i] = lower_bound(p + 1 , p + tot + 1 , a[i]) - p;
		for(int i = 1 ; i <= m ; i++ ) 
		{
			node[i].l = lower_bound(p + 1 , p + tot + 1 , node[i].l) - p;
			node[i].r = lower_bound(p + 1 , p + tot + 1 , node[i].r) - p;
		}
		sort(node + 1 , node + m + 1); tot = 0; R = 2e9;
		node[0].l = -2e9;
		for(int i = 1 ; i <= m ; i++ )
			if(node[i].l != node[i - 1].l)
				if(node[i].r < R) id[++tot] = i , R = node[i].r;
		for(int i = 1 ; i <= m ; i++ ) f[i] = 0;
		int it = 1;
		for(int i = 1 ; i <= tot ; i++ ) f[id[i]] = 1;
		for(int i = n ; i >= 1 ; i-- )
		{
			while(node[id[it]].r >= a[i] && it <= tot)
			{
				if(node[id[it]].l <= a[i]) f[id[it]] = 0;
				it++;
			}
		}
		tot = 0;
		for(int i = 1 ; i <= m ; i++ )
			if(f[i]) x[++tot] = (item){node[i].l , node[i].r , 0};
		for(int i = 1 ; i <= n ; i++ ) x[++tot] = (item){a[i] , a[i] , 1};
		sort(x + 1 , x + tot + 1);
		if(tst)
		{
			for(int i = 1 ; i <= tot ; i++ ) cerr << x[i].l << ' ' << x[i].r << ' ' << x[i].tp << endl;
		}
		n = tot; tot = 0; 
		for(int i = 1 ; i <= n ; i++ )
		{
			if(x[i].tp == 1)
			{
				int it = tot;
				tot++; f[tot] = 1; l[tot] = r[tot] = x[i].l;
				tot++; f[tot] = 2; l[tot] = r[tot] = x[i].l;
				while(it >= 0 && !rp[it]) rp[it] = tot - 1 , it--;
			}
			else
			{
				tot++; f[tot] = 0; l[tot] = x[i].l; r[tot] = x[i].r;
			}
		}
		n = tot; dp[0] = 0;
		for(int i = 1 ; i <= n ; i++ ) dp[i] = 1e12;
//		for(int i = 1 ; i <= n ; i++ ) cerr << rp[i] << ' '; cerr << endl;
//		for(int i = 1 ; i <= n ; i++ ) cerr << l[i] << ' '; cerr << endl;
//		for(int i = 1 ; i <= n ; i++ ) cerr << r[i] << ' '; cerr << endl;
//		cerr << n << endl;
		if(tst) cerr << rp[0] << endl;
		for(int i = 0 ; i < n ; i++ )
		{
//			if(!i) cerr << p[l[rp[i]]] << ' ' << p[r[i + 1]] << endl;
			if(rp[i])
			{
//				if(p[l[rp[i]]] - p[r[i + 1]] < 0) cerr << i << ' ' << rp[i] << ' ' << p[l[rp[i]]] << ' ' << p[r[i + 1]] << endl;
				dp[rp[i]] = min(dp[rp[i]] , dp[i] + (p[l[rp[i]]] - p[r[i + 1]]) * 2);
				dp[rp[i] + 1] = min(dp[rp[i] + 1] , dp[i] + (p[l[rp[i]]] - p[r[i + 1]]));
			}
			if(f[i])
			{
				for(int it = i + 3 - f[i] ; !f[it] && it <= n ; it++ )
					dp[it] = min(dp[it] , dp[i] + (p[l[it]] - p[l[i]]) * f[i]);
			}
//			cerr << dp[i] << ' ';
		}
		if(tst)
		{
			for(int i = 0 ; i <= n ; i++ ) cerr << dp[i] << ' '; cerr << endl;
		}
//		cerr << endl;
		printf("%lld\n" , dp[n]); 
		for(int i = 0 ; i <= n ; i++ ) f[i] = rp[i] = l[i] = r[i] = dp[i] = 0;
	}
	return 0;
}
/*
*/