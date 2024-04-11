#include<bits/stdc++.h>
using namespace std;
int n , a[220000] , noww = 1;
long long ans , sum;
int main()
{
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]);
	while(noww <= n) 
	{
		sum += a[noww];
		noww += 2;
	}
	noww -= n;
	ans = sum;
	while(noww <= n) 
	{
		sum += a[noww];
		sum -= a[noww - 1];
		noww += 2;
		ans = max(ans , sum);
	}
	noww -= n;
	sum += a[1];
	sum -= a[n];
	ans = max(ans , sum);
	noww += 2;
	while(noww <= n) 
	{
		sum += a[noww];
		sum -= a[noww - 1];
		noww += 2;
		ans = max(ans , sum);
	}
	ans = max(ans , sum);
	printf("%lld" , ans);
	return 0;
}