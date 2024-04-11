#include<bits/stdc++.h>
using namespace std;
struct item
{
	int num , id;
	bool operator < ( const item &x ) const
	{
		return num < x.num;
	}
};
int T , n , k , z;
long long sum[110000] , ans , maxx , a[110000];
priority_queue< item > q;
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		while(!q.empty()) q.pop();
		scanf("%d%d%d" , &n , &k , &z); k++;
		for(int i = 1 ; i <= n ; i++ )
		{
			scanf("%d" , &a[i]);
			sum[i] = sum[i - 1] + a[i];
		}
		ans = 0;
		for(int i = 0 ; i <= z ; i++ )
		{
			maxx = 0;
			int qwq = k - i * 2;
			if(qwq <= 0) break;
			for(int j = 1 ; j <= qwq ; j++ )
			{
				if(j < n) maxx = max(maxx , a[j] + a[j + 1]);
			}
			ans = max(ans , sum[qwq] + maxx * i);
//			cerr << ans << endl;
		}
		printf("%lld\n" , ans);
	}
	return 0;
}
/*
10000
18 11 4
11 19 18 19 19 5 14 15 17 4 10 9 8 17 9 2 15 10


219
*/