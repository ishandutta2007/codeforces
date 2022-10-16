#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int check(int k)
{
	int tot=0,nn=n;
	while(nn)
	{
		tot+=min(k,nn);
		nn=max(0ll,nn-k);
		nn-=(nn/10);
	}
	return tot;
}
signed main()
{
	scanf("%lld",&n);
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
//		cout<<mid<<" "<<check(mid)<<endl;
		if(check(mid)>=(n+1)/2)
			r=mid-1;
		else
			l=mid+1;
	}
	cout<<l;
	return 0;
}