#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,g,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&g,&b);
		int q=((n+1>>1)-1)/g,r=((n+1>>1)-1)%g+1;
		printf("%lld\n",max(0ll+n,1ll*q*(g+b)+r));
	}
	return 0;
}