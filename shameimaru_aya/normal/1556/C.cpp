#include <bits/stdc++.h>
using namespace std;
int T , n , a[1100];
long long ans , sum[1100] , st[20][1100];
void init()
{
	for(int i = 1 ; i <= 18 ; i++ )
		for(int j = 1 ; j + (1 << i - 1) <= n ; j++ ) 
			st[i][j] = min(st[i - 1][j] , st[i - 1][j + (1 << i - 1)]);
}
long long ask( int l , int r )
{
	if(l > r) return 1e16;
	int k = log2(r - l + 1);
	return min(st[k][l] , st[k][r - (1 << k) + 1]);
}
int main() 
{
	T = 1;
	while(T--)
	{
		scanf("%d" , &n); 
		for(int i = 1 ; i <= n ; i++ ) 
			scanf("%d" , &a[i]) , st[0][i] = sum[i] = sum[i - 1] + a[i] * (i & 1 ? 1 : -1);
		init();
		for(int i = 1 ; i <= n ; i += 2 )
		{
			for(int j = i + 1 ; j <= n ; j += 2 ) 
			{
				long long qwq = sum[j - 1] - sum[i] , x = a[i] , y = a[j] , minn = min(0ll , ask(i + 1 , j - 1) - sum[i]);
				x += minn; qwq -= minn;
				if(qwq < 0) x += qwq;
				if(qwq > 0) y -= qwq;
				ans += max(0ll , min(x , y) + (j != i + 1));
//				cerr << i << ' ' << j << ' ' << x << ' ' << y << ' ' << minn << endl;
			}
		}
		printf("%lld\n" , ans);
	}
	return 0;
}
/*

*/