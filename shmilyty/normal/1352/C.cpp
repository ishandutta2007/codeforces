#include<bits/stdc++.h>
#define int long long//1
using namespace std;
int t,n,k;
signed main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		if(k%(n-1)==0)
		{
			cout<<k/(n-1)*n-1<<endl;
			continue;
		}
		else
			cout<<k/(n-1)*n+k%(n-1)<<endl;
	}
	return 0;
 }