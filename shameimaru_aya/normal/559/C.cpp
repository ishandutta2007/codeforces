#include <bits/stdc++.h>
#define N 200000
using namespace std;
struct item
{
	long long x , y;
	bool operator < ( const item &a ) const
	{
		if(a.x == x) return y < a.y;
		return x < a.x;
	}
} node[2200];
int n , w , h;
long long val[2200] , dis[2200][2200] , jc[220000] , inv[220000] , ans;
const int mod = 1e9 + 7;
inline void init()
{
	jc[0] = inv[0] = inv[1] = 1;
	for(int i = 1 ; i <= N ; i++ ) jc[i] = jc[i - 1] * i % mod;
	for(int i = 2 ; i <= N ; i++ ) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
	for(int i = 2 ; i <= N ; i++ ) inv[i] = inv[i - 1] * inv[i] % mod;
	return ;
}
inline long long C( int a , int b )
{
	if(a < b || !a) return 0;
	return jc[a] * inv[b] % mod * inv[a - b] % mod;
}
int main()
{
	init();
	scanf("%d%d%d" , &h , &w , &n); ans = C(h + w - 2 , h - 1);
	for(int i = 1 ; i <= n ; i++ ) scanf("%lld%lld" , &node[i].x , &node[i].y);
	sort(node + 1 , node + n + 1);
	for(int i = 1 ; i <= n ; i++ )
	{
		for(int j = i + 1 ; j <= n ; j++ )
		{
			if(node[i].y > node[j].y) continue;
			int dx = node[j].x - node[i].x , dy = node[j].y - node[i].y;
			dis[i][j] = C(dx + dy , dx);
		}
	}
	for(int i = 1 ; i <= n ; i++ )
	{
		val[i] = C(node[i].x + node[i].y - 2 , node[i].x - 1);
		for(int j = 1 ; j < i ; j++ )
			val[i] = ((val[i] - val[j] * dis[j][i] % mod) % mod + mod) % mod;
		int dx = h - node[i].x , dy = w - node[i].y;
		ans = ((ans - val[i] * C(dx + dy , dx) % mod) % mod + mod) % mod;
	}
	printf("%lld" , ans);
	return 0;
}
/*
4 4 4
3 3
3 2
2 2
2 3
*/