#include<bits/stdc++.h>
#define int long long
using namespace std;
main()
{
	int n,m;
	scanf("%lld %lld",&n,&m);
	int y = n/m;
	int x = n%m;
	long long ans = 0;
	for(int i = 1;i<=m;i++)for(int j = 1;j<=m;j++)
	{
		if((i*i+j*j)%m==0)
		{
			long long t = i<=x? 1:0;
			long long s = j<=x? 1:0;
			t+=y;
			s+=y;
			ans += t*s;
			//printf("%lld %lld %lld %lld %lld\n",ans,i,j,t,s);
		}
	}
	printf("%lld\n",ans);
	return 0;
}