#include<bits/stdc++.h>
#define int long long
#define N 200010
using namespace std;
int n,k,d[N*2],sd[N*2],sh[N*2],ans;
signed main()
{
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;++i) 
	{
		scanf("%lld",&d[i]);
		d[i+n]=d[i];
	}
	for(int i=1;i<=2*n;++i)
	{
		sd[i]=d[i]+sd[i-1];
		sh[i]=sh[i-1]+(d[i]*(d[i]+1)/2);
	}
	for(int i=1,j=0;i<=2*n;++i)
	{
		while(sd[i]-sd[j]>k) 
			++j;
		if(sd[i]>=k)
		{
			int tmp=sh[i]-sh[j];
			int res=k-sd[i]+sd[j];
			tmp+=(2*d[j]+1-res)*res/2;
			ans=max(ans,tmp);
		}
	}
	cout<<ans;
    return 0;
}