#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,s,cnt,tot,ans,a[20];
int qp(int x)
{
	if(x==0)
		return 1;
	if(x==1)
		return 10;
	int ans=qp(x/2);
	ans*=ans;
	if(x&1)
		ans*=10;
	return ans;
}
signed main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&s);
		cnt=tot=ans=0;
		memset(a,0,sizeof(a)); 
		while(n)
		{
			a[++tot]=n%10;
			cnt+=n%10;
			n/=10;
		}
//		for(int i=1;i<=tot;i++)
//			cout<<a[i]<<" ";
//		cout<<endl;
		for(int i=1;i<=tot+1;i++)
		{
			if(cnt<=s)
				break;
//			cout<<i<<" "<<a[i]<<endl;
			ans+=(10-a[i])*qp(i-1);
//			cout<<ans<<endl;
			cnt=cnt-a[i]+1;
//			cout<<cnt<<endl;
//			cout<<endl;
			a[i+1]++; 
		}
		cout<<ans<<endl;
	}
	return 0;
}