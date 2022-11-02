#include<bits/stdc++.h>
using namespace std;
int n , d , m , a[110000] , l[110000] , s[110000] , totl , tots;
long long suml[110000] , sums[110000] , ans;
int main()
{
	scanf("%d%d%d" , &n , &d , &m);
	for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]);
	sort(a + 1 , a + n + 1); reverse(a + 1 , a + n + 1);
	for(int i = 1 ; i <= n ; i++ )
	{
		if(a[i] > m) l[++totl] = a[i] , suml[totl] = suml[totl - 1] + a[i];
		else s[++tots] = a[i] , sums[tots] = sums[tots - 1] + a[i];
	}
	ans = sums[tots];
	for(int i = 1 ; i <= totl ; i++ )
	{
		int qwq = min(tots , n - (i - 1) * (d + 1) - 1);
		if(qwq < 0) break;
		ans = max(ans , suml[i] + sums[qwq]);
	}
	printf("%lld" , ans);
    return 0;
}