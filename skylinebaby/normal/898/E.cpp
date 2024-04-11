#include<bits/stdc++.h>
#define int long long
using namespace std;
int fee[211111];
main()
{
	int n;
	scanf("%lld",&n);
	int iden = 0;
	int ze = 0;
	for(int i = 0;i<n;i++)
	{
		int x;
		scanf("%lld",&x);
		if (x==0) ze++;
		else
		{
			int y = (int) pow(x+0.1000,0.5000);
			if (y*y==x) continue;
			else 
			{
				int s = min(x-y*y,(y+1)*(y+1)-x);
				fee[iden++] = s;
			} 
		}
	}
	if (iden == n/2) printf("0\n");
	if (iden >n/2)
	{
		sort(fee,fee+iden);
		int ans = 0;
		for(int i = 0;i<iden-n/2;i++)
		{
			ans += fee[i];
		}
		printf("%lld\n",ans);
	}
	if (iden < n/2)
	{
		if (ze<=n/2) printf("%lld\n",n/2-iden);
		else printf("%lld\n",ze-iden);
	}
	return 0;
}