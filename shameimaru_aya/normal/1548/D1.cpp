#include <bits/stdc++.h>
using namespace std;
int n , x[6600] , y[6600] , num[2][2];
long long ans;
struct pnt
{
	int x , y;
} p[6600];
// (a.x - b.x) / __gcd(a.x - b.x , a.y - b.y);
int main()
{
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i++ ) scanf("%d%d" , &x[i] , &y[i]);
	for(int i = 1 ; i <= n ; i++ )
	{
		memset(num , 0 , sizeof(num));
		for(int j = i + 1 ; j <= n ; j++ )
		{
			int a = abs(x[j] - x[i]) % 4 / 2 , b = abs(y[j] - y[i]) % 4 / 2;
			if(a == 0 && b == 0) ans += num[0][0] + num[0][1] + num[1][0] + num[1][1];
			if(a == 0 && b == 1) ans += num[0][0] + num[0][1];
			if(a == 1 && b == 0) ans += num[0][0] + num[1][0];
			if(a == 1 && b == 1) ans += num[0][0] + num[1][1];
			num[a][b]++;
		}
	}
	printf("%lld" , ans);
	return 0;
}
/*

*/