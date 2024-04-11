#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,m,a,b;
long long ans=0;
int main()
{
	scanf("%d%d%d%d",&n,&m,&a,&b);
	if(m==1)
	{
		printf("%lld\n",1ll*(n-1)*a);
		return 0;
	}
	while(n!=1)
	{
		int q=n/m,r=n%m,t=q*m;
		//cout<<n<<' '<<ans<<' '<<q<<' '<<r<<' '<<t<<endl;
		if(q==0)
		{
			ans+=1ll*(n-1)*a;
			break;
		}
		ans+=1ll*r*a+min(1ll*(t-q)*a,1ll*b);
		n=q;
	}
	printf("%lld\n",ans);
	return 0;
}