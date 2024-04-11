#include<bits/stdc++.h>
using namespace std;
int ll[123456];
int rr[123456];
main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
	{
		scanf("%d %d",&ll[i],&rr[i]);
	}
	sort(ll,ll+n);
	sort(rr,rr+n);
	long long ans = (long long)n;
	for(int i = 0;i<n;i++)
	{
		ans += (long long)max(ll[i],rr[i]);
	}
	printf("%lld\n",ans);
	return 0;
}