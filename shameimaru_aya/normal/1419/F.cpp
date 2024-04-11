#include <bits/stdc++.h>
#define okpoint(i , j , k) ((x[i] == x[j] || y[i] == y[j]) && abs(x[i] - x[j] + y[i] - y[j]) <= k)
using namespace std;
int n , fa[1100] , ans , tot1 , tot2 , num;
long long x[1100] , y[1100] , a[11000] , b[11000] , c[11000] , d[11000];
inline int getf( int x )
{
	if(fa[x] == x) return x;
	return fa[x] = getf(fa[x]);
}
inline bool check2( long long k )
{
//	if(k == 2) cerr << 111111;
	for(int i = 1 ; i <= n ; i++ )
	{
		if(getf(i) == getf(a[1]) || !tot1) a[++tot1] = i;
		else b[++tot2] = i;
	}
	for(int i = 1 ; i <= tot1 ; i++ )
		for(int j = 1 ; j <= tot2 ; j++ )
			if(okpoint(a[i] , b[j] , 2 * k) || 
			   (abs(x[a[i]] - x[b[j]]) <= k && abs(y[a[i]] - y[b[j]]) <= k))
			return 1;
	return 0;
}
inline bool check3( long long k )
{
	for(int i = 1 ; i <= n ; i++ )
	{
		for(int j = i + 1 ; j <= n ; j++ )
		{
			if(x[i] == x[j] && abs(y[i] - y[j]) <= 2 * k && getf(i) != getf(j)) 
			a[++tot1] = i , b[tot1] = j;
			if(y[i] == y[j] && abs(x[i] - x[j]) <= 2 * k && getf(i) != getf(j)) 
			c[++tot2] = i , d[tot2] = j;
		}
	}
	for(int i = 1 ; i <= tot1 ; i++ )
	{
		for(int j = 1 ; j <= n ; j++ )
		{
			if((y[j] - y[a[i]]) * (y[j] - y[b[i]]) < 0 && abs(y[j] - y[a[i]]) <= k &&
			   abs(y[j] - y[b[i]]) <= k && abs(x[j] - x[a[i]]) <= k && 
			   getf(a[i]) != getf(j) && getf(b[i]) != getf(j))
			return 1;
		}
	}
	for(int i = 1 ; i <= tot2 ; i++ )
	{
		for(int j = 1 ; j <= n ; j++ )
		{
			if((x[j] - x[c[i]]) * (x[j] - x[d[i]]) < 0 && abs(x[j] - x[c[i]]) <= k &&
			   abs(x[j] - x[d[i]]) <= k && abs(y[j] - y[c[i]]) <= k &&
			   getf(c[i]) != getf(j) && getf(d[i]) != getf(j))
			return 1;
		}
	}
	return 0;
}
inline bool check4( long long k ) //bug
{
	for(int i = 1 ; i <= n ; i++ )
	{
		for(int j = i + 1 ; j <= n ; j++ )
		{
			if(x[i] == x[j] && abs(y[i] - y[j]) <= 2 * k && getf(i) != getf(j)) 
			a[++tot1] = i , b[tot1] = j;
			if(y[i] == y[j] && abs(x[i] - x[j]) <= 2 * k && getf(i) != getf(j)) 
			c[++tot2] = i , d[tot2] = j;
		}
	}
	for(int i = 1 ; i <= tot1 ; i++ )
	{
		for(int j = 1 ; j <= tot2 ; j++ )
		{
			if((x[a[i]] - x[c[j]]) * (x[a[i]] - x[d[j]]) < 0 && 
			   (y[c[j]] - y[a[i]]) * (y[c[j]] - y[b[i]]) < 0 && 
			   abs(x[a[i]] - x[c[j]]) <= k && abs(x[a[i]] - x[d[j]]) <= k &&
			   abs(y[c[j]] - y[a[i]]) <= k && abs(y[c[j]] - y[b[i]]) <= k &&
			   getf(a[i]) != getf(c[j]) && getf(a[i]) != getf(d[j]) && 
			   getf(b[i]) != getf(c[j]) && getf(b[i]) != getf(d[j]))
			return 1;
			
		}
	}
	return 0;
}
inline bool check( long long k )
{
	num = n;
	for(int i = 1 ; i <= n ; i++ ) fa[i] = i;
	for(int i = 1 ; i <= n ; i++ )
	{
		for(int j = i + 1 ; j <= n ; j++ )
		{
			int A = getf(i) , B = getf(j);
			if(okpoint(i , j , k) && A != B)
			fa[B] = A , num--;
		}
	}
	tot1 = tot2 = 0;
	if(num > 4) return 0;
	if(num == 1) return 1;
	if(num == 2) return check2(k);
	if(num == 3) return check3(k);
	if(num == 4) return check4(k);
}
void binary( long long l , long long r )
{
	if(l > r) return ;
	long long mid = l + r >> 1;
	if(check(mid))
	{
		ans = mid;
		binary(l , mid - 1);
	}
	else binary(mid + 1 , r);
}
int main()
{
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i++ ) scanf("%lld%lld" , &x[i] , &y[i]);
	binary(1 , 2e9);
	if(ans) printf("%d" , ans);
	else printf("-1");
	return 0;
}
/*

*/