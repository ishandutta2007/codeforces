#include <bits/stdc++.h>
#define lowbit(x) (x & (-x))
using namespace std;
int T , n , m , a[99000] , c[330][330] , ans;
struct item
{
	int num , id , pl;
	bool operator < ( const item &x ) const
	{
		if(num == x.num) return id > x.id;
		return num < x.num;
	}
} node[99000];
bool cmp( item a , item b )
{
	return a.id < b.id;
}
void add( int y , int x , int a )
{
	while(x <= m)
	{
		c[y][x] += a;
		x += lowbit(x);
	}
	return ;
}
int ask( int y , int x )
{
	int ans = 0;
	while(x)
	{
		ans += c[y][x];
		x -= lowbit(x);
	}
	return ans;
}
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d%d" , &n , &m); ans = 0;
		for(int i = 1 ; i <= n ; i++ ) memset(c[i] , 0 , sizeof(c[i]));
		for(int i = 1 ; i <= n * m ; i++ ) scanf("%d" , &node[i].num) , node[i].id = i;
		sort(node + 1 , node + n * m + 1);
		for(int i = 1 ; i <= n * m ; i++ ) node[i].pl = i;
		sort(node + 1 , node + n * m + 1 , cmp);
		for(int i = 1 ; i <= n * m ; i++ )
		{
			ans += ask(1 , node[i].pl - 1);  add(1 , node[i].pl , 1);
		}
		printf("%d\n" , ans);
	}
	return 0;  
}
/*
1
2
00
11
*/