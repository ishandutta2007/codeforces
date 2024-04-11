#include <bits/stdc++.h>
#define lowbit(x) (x & (-x))
using namespace std;
int T , n , m , a[99000] , c[99000] , ans , ppl[99000] , st , id[99000] , t[330];
struct item
{
	int num , id , pl;
	bool operator < ( const item &x ) const
	{
		if(num == x.num) return id < x.id;
		return num < x.num;
	}
} node[99000];
bool cmp( item a , item b )
{
	return a.id < b.id;
}
void add( int x , int a )
{
	while(x <= n * m)
	{
		c[x] += a;
		x += lowbit(x);
	}
	return ;
}
int ask( int x )
{
	int ans = 0;
	while(x)
	{
		ans += c[x];
		x -= lowbit(x);
	}
	return ans;
}
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d%d" , &n , &m); ans = 0; st = 1;
		for(int i = 1 ; i <= n * m ; i++ ) scanf("%d" , &node[i].num) , node[i].id = i;
		sort(node + 1 , node + n * m + 1);
		for(int i = 1 ; i <= n * m ; i++ ) 
		{
			ppl[i] = i;
			if(i % m == 0 || node[i].num != node[i + 1].num)
			{
				reverse(ppl + st , ppl + i + 1);
				st = i + 1;
			}
		}
//		for(int i = 1 ; i <= n * m ; i++ ) cerr << ppl[i] << ' '; cerr << endl;
		for(int i = 1 ; i <= n * m ; i++ ) node[i].pl = ppl[i] , id[ppl[i]] = node[i].id;
		sort(node + 1 , node + n * m + 1 , cmp);
		for(int i = 1 ; i <= n ; i++ )
		{
			for(int j = (i - 1) * m + 1 ; j <= i * m ; j++ ) t[j - (i - 1) * m] = id[j];
			for(int j = 1 ; j <= m ; j++ )
			{
//				cerr << t[j] << ' ';
				ans += ask(t[j] - 1); add(t[j] , 1);
			}
			for(int j = 1 ; j <= m ; j++ ) add(t[j] , -1);
//			cerr << ans << endl;
//			cerr << endl;
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