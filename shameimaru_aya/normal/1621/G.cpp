#include <bits/stdc++.h>
#define lowbit(x) (x & (-x))
using namespace std;
int T , n , a[220000] , f[220000] , q[220000];
long long c[220000] , dp[220000] , pre[220000] , suf[220000] , ans;
const int mod = 1e9 + 7;
struct item
{
	int num , id;
	bool operator < ( const item &x ) const
	{
		if(num == x.num) return id > x.id;
		return num < x.num;
	}
} node[220000];
void add( int x , int a )
{
	while(x <= n)
	{
		(c[x] += a) %= mod;
		x += lowbit(x);
	}
	return ;
}
long long ask( int x )
{
	long long ans = 0;
	while(x)
	{
		(ans += c[x]) %= mod;
		x -= lowbit(x);
	}
	return ans;
}
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n); ans = 0;
		for(int i = 1 ; i <= n ; i++ ) 
			scanf("%d" , &a[i]) , c[i] = f[i] = 0 , node[i] = (item){a[i] , i};
		sort(node + 1 , node + n + 1);
		for(int i = 1 ; i <= n ; i++ ) a[node[i].id] = i , q[i] = node[i].id;
		int maxx = 0;
		for(int i = n ; i >= 1 ; i-- )
		{
			maxx = max(maxx , a[i]);
			f[i] = (maxx == a[i]);
		}
		for(int i = n ; i >= 1 ; i-- )
		{
			suf[i] = (ask(n) - ask(a[i]) + mod + 1) % mod;
			add(a[i] , suf[i]);
		}
		for(int i = 1 ; i <= n ; i++ ) c[i] = 0;
		for(int i = 1 ; i <= n ; i++ ) 
		{
			pre[i] = (ask(a[i]) + 1) % mod;
			add(a[i] , pre[i]);
		}
		for(int i = 1 ; i <= n ; i++ ) c[i] = 0;
//		for(int i = 1 ; i <= n ; i++ ) cerr << a[i] << ' '; cerr << endl;
//		for(int i = 1 ; i <= n ; i++ ) cerr << q[i] << ' '; cerr << endl;
//		for(int i = 1 ; i <= n ; i++ ) cerr << pre[i] << ' '; cerr << endl;
//		for(int i = 1 ; i <= n ; i++ ) cerr << suf[i] << ' '; cerr << endl;
		int las = n;
		for(int i = n ; i >= 1 ; i-- )
		{
			if(f[q[i]])
			{
				for(int j = i + 1 ; j <= las ; j++ ) add(q[j] , mod - dp[j]);
				dp[i] = 1; add(q[i] , dp[i]); las = i;
				(ans += pre[q[i]] * (suf[q[i]] - dp[i] + mod) % mod) %= mod;
				continue;
			}
			dp[i] = (ask(n) - ask(q[i]) + mod) % mod;
			add(q[i] , dp[i]);
			(ans += pre[q[i]] * (suf[q[i]] - dp[i] + mod) % mod) %= mod;
		}
//		for(int i = 1 ; i <= n ; i++ ) cerr << dp[a[i]] << ' '; cerr << endl;
		printf("%lld\n" , ans);
	}
	return 0;
}
/*
*/