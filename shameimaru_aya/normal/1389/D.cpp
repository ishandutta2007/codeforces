#include<bits/stdc++.h>
using namespace std;
int T;
long long n , k , l1 , r1 , l2 , r2 , ans;
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%lld%lld%lld%lld%lld%lld" , &n , &k , &l1 , &r1 , &l2 , &r2);
		ans = 0;
		if(r1 > r2) swap(r1 , r2);
		if(l1 > l2) swap(l1 , l2);
		k -= n * max(0ll , r1 - l2);
		if(k <= 0)
		{
			printf("0\n");
			continue;
		}
		if(r2 - l1 - max(0ll , r1 - l2) == 0)
		{
			printf("%lld\n" , 2ll * k);
			continue;
		}
		long long qwq = k / (r2 - l1 - max(0ll , r1 - l2));
		if(qwq == 0)
		{
			ans += max(k , l2 + k - r1);
			printf("%lld\n" , ans);
			continue;
		}
		if(qwq >= n)
		{
			ans += n * (r2 - r1 + l2 - l1);
			k -= n * (r2 - l1 - max(0ll , r1 - l2));
		}
		else
		{
			ans += qwq * (r2 - r1 + l2 - l1);
			k -= qwq * (r2 - l1 - max(0ll , r1 - l2));
			ans += min(2ll * k , max(k , l2 + k - r1));
			printf("%lld\n" , ans);
			continue;
		}
		ans += 2ll * k;
		printf("%lld\n" , ans);
	}
	return 0;
}
/*
11
3 7
1 5
2 3
3 13
1 5
2 3
3 3
1 5
2 3
3 16
3 10
1 5
3 48
3 10
1 5
3 2
3 10
1 5
3 20
1 4
6 9
3 30
6 9
1 4
3 17
6 9
1 4
3 1
6 9
1 4
*/