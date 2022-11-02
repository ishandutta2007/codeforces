#include <bits/stdc++.h> 
using namespace std;
struct item
{
	int c , num;
	bool operator < ( const item &x ) const 
	{
		return num < x.num;
	}
} node[660000];
int n , a[10] , b[110000] , f[110000] , l , r , cnt , tot , ans = 1e9;
inline void del( int x )
{
	f[x]--;
	tot -= (!f[x]);
}
inline void add( int x )
{
	tot += (!f[x]);
	f[x]++;
}
int main()
{
	scanf("%d%d%d%d%d%d%d" , &a[1] , &a[2] , &a[3] , &a[4] , &a[5] , &a[6] , &n);
	for(int i = 1 ; i <= n ; i++ ) 
	{
		scanf("%d" , &b[i]);
		for(int j = 1 ; j <= 6 ; j++ ) node[++cnt] = (item){i , b[i] - a[j]};
	}
	sort(node + 1 , node + cnt + 1);
	l = r = 1;
	while(r <= cnt)
	{
		while(r <= cnt && tot != n) add(node[r++].c);
		if(tot != n) break;
		while(tot == n) del(node[l++].c);
		ans = min(ans , node[r - 1].num - node[l - 1].num);
	}
	printf("%d" , ans);
	return 0;
}
/*

*/