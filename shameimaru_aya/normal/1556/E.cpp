#include <bits/stdc++.h>
using namespace std;
int T , n , m , a[110000] , b , x , y;
long long sum[110000] , minn[20][110000] , maxx[20][110000];
void init()
{
	for(int i = 1 ; i <= 18 ; i++ )
		for(int j = 1 ; j + (1 << i - 1) <= n ; j++ ) 
		{
			minn[i][j] = min(minn[i - 1][j] , minn[i - 1][j + (1 << i - 1)]);
			maxx[i][j] = max(maxx[i - 1][j] , maxx[i - 1][j + (1 << i - 1)]);
		}
}
long long askmin( int l , int r )
{
	int k = log2(r - l + 1);
	return min(minn[k][l] , minn[k][r - (1 << k) + 1]);
}
long long askmax( int l , int r )
{
	int k = log2(r - l + 1);
	return max(maxx[k][l] , maxx[k][r - (1 << k) + 1]);
}
int main() 
{
	T = 1;
	while(T--)
	{
		scanf("%d%d" , &n , &m);
		for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]);
		for(int i = 1 ; i <= n ; i++ )
		{
			scanf("%d" , &b); a[i] -= b;
			sum[i] = sum[i - 1] + a[i];
			minn[0][i] = maxx[0][i] = sum[i];
		}
		init();
		while(m--)
		{
			scanf("%d%d" , &x , &y);
			long long qwq = askmax(x , y) - sum[x - 1];
			if(qwq > 0 || sum[y] != sum[x - 1]) printf("-1\n");
			else
			{
				qwq = askmin(x , y) - sum[x - 1];
				printf("%lld\n" , -qwq);
			}
		}
	}
	return 0;
}
/*

*/