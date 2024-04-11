#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a,b,c;
signed main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		b=c=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a);
			if(i==1||i==2)
				b+=a;	
			if(i==n)
				c=a;
		}	
		if(b>c)
			puts("-1");
		else
			printf("1 2 %lld \n",n);
	}
	return 0;
}