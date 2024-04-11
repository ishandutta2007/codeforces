#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
bool judge(int x)
{
	int res=0;
	for(int i=1;i<=n;i++)
		res+=min(m,x/i);
	return res>=k;
}
signed main()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	int l=1,r=n*m;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(judge(mid))
			r=mid-1;
		else
			l=mid+1;
	}
	cout<<r+1<<endl;
	return 0;
}