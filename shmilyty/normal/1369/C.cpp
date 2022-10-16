#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,k,w[200001],a[200001];
signed main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		int ans=0,cnt=1,single=0;
		for(int i=1;i<=n;i++)
			scanf("%lld",&w[i]);
		for(int i=1;i<=k;i++)
		{
			scanf("%lld",&a[i]);
			if(a[i]==1)
				single++;
		}		
		sort(w+1,w+1+n);
		for(int i=1;i<=k;i++)
		{
			ans+=w[n-i+1];
			if(i<=single)
				ans+=w[n-i+1];
		}
		sort(a+1,a+1+k);
		for(int i=k;i>=1;i--)
			if(a[i]-1!=0)
			{
				ans+=w[cnt];
				cnt+=a[i]-1;
			}
		cout<<ans<<endl;
	}
	return 0;
}//3