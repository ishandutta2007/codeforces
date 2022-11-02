#include <bits/stdc++.h>
using namespace std;
int n;
long long k , p[20] , a[5500000] , b[5500000] , na , nb , lim = 1e18 , ans;
void dfs1( long long s , int k )
{
	a[++na] = s; 
	for(int i = k ; i <= n ; i += 2 )
	{
		if(lim / s >= p[i]) dfs1(s * p[i] , i);
	}
}
void dfs2( long long s , int k )
{
	b[++nb] = s; 
	for(int i = k ; i <= n ; i += 2 )
	{
//		cerr << p[i] << endl;
		if(lim / s >= p[i]) dfs2(s * p[i] , i);
	}
}
bool check( long long x )
{
	long long tot = 0;
	for(int i = 1 ; i <= na ; i++ )
	{
//		cerr << a[i] << ' ' << x / a[i] << endl;
		tot += upper_bound(b + 1 , b + nb + 1 , x / a[i]) - b - 1;
	}
	return (tot >= k);
}
void binary( long long l , long long r )
{
	if(l > r) return ;
	long long mid = l + r >> 1;
	if(check(mid)) ans = mid , binary(l , mid - 1);
	else binary(mid + 1 , r);
}
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i++ ) scanf("%lld" , &p[i]);
	scanf("%lld" , &k);
	dfs1(1 , 2); dfs2(1 , 1); 
	sort(a + 1 , a + na + 1); sort(b + 1 , b + nb + 1);
//	cerr << na << ' ' << nb << endl; 
//	for(int i = 1 ; i <= na ; i++ ) cerr << a[i] << ' '; cerr << endl;
//	for(int i = 1 ; i <= nb ; i++ ) cerr << b[i] << ' '; cerr << endl;
	binary(1 , lim);
	printf("%lld" , ans);
	check(1e18);
	return 0;
}
/*
16
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53
755104793
*/