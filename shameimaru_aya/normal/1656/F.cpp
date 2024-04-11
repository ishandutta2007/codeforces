#include <bits/stdc++.h>
using namespace std;
int T , n;
long long a[220000] , s[220000] , mn , mx , sum;
long long val( long long t )
{
	long long mnn = mn + t , mxx = mx + t , qwq = t * t;
	if(mnn <= 0 && mxx >= 0)
	{
		int num = lower_bound(a + 1 , a + n + 1 , -t) - a - 1;
		long long ans = (s[num] + num * t) * mxx + (s[n] - s[num] + (n - num) * t) * mnn;
		ans -= mxx * mnn; ans -= qwq * (n - 1);
		return ans;
	}
	if(mxx <= 0)
		return -qwq * (n - 1) + (s[n - 1] + (n - 1) * t) * mxx;
	if(mnn >= 0)
		return -qwq * (n - 1) + (s[n] - s[1] + (n - 1) * t) * mnn;
}
long long solve( long long l , long long r )
{
	if(l == r) return l;
	if(l == r - 1)
	{
		if(val(l) < val(r)) return r;
		return l;
	}
	if(l == r - 2)
	{
		long long ans = l;
		if(val(ans) < val(l + 1)) ans = l + 1;
		if(val(ans) < val(l + 2)) ans = l + 2;
		return ans;
	}
	long long mid = l + r >> 1 , mmid = mid + 1;
	if(val(mid) > val(mmid)) return solve(l , mmid);
	return solve(mid , r);
}
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n); mn = 1e18 , mx = -1e18 , sum = 0;
		for(int i = 1 ; i <= n ; i++ ) 
		{
			scanf("%lld" , &a[i]); 
			mn = min(mn , a[i]); mx = max(mx , a[i]); sum += a[i];
		}
		sort(a + 1 , a + n + 1);
		for(int i = 1 ; i <= n ; i++ ) s[i] = s[i - 1] + a[i];
		if((n - 2) * mx + sum < 0)
		{
			printf("INF\n");
			continue;
		}
		if((n - 2) * mn + sum > 0)
		{
			printf("INF\n");
			continue;
		}
		printf("%lld\n" , val(solve(-1e6 , 1e6)));
	}
	return 0;
}
/*
*/