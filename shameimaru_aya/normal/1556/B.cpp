#include <bits/stdc++.h>
using namespace std;
int T , n , a[110000] , t[2] , it[2];
long long ans , sum;
int main() 
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n); t[0] = t[1] = 0; ans = 1e18;
		for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]) , t[a[i] & 1]++;
		if(abs(t[0] - t[1]) > 1) 
		{
			printf("-1\n");
			continue;
		}
		if(t[0] >= t[1])
		{
			it[0] = 1; it[1] = 2; sum = 0;
			for(int i = 1 ; i <= n ; i++ )
			{
				sum += abs(i - it[a[i] & 1]); it[a[i] & 1] += 2;
			}
			ans = min(ans , sum);
		}
		if(t[1] >= t[0])
		{
			it[0] = 2; it[1] = 1; sum = 0;
			for(int i = 1 ; i <= n ; i++ )
			{
				sum += abs(i - it[a[i] & 1]); it[a[i] & 1] += 2;
			}
			ans = min(ans , sum);
		}
		printf("%lld\n" , ans / 2);
	}
	return 0;
}
/*

*/