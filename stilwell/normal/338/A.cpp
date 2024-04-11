#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,p,i,j,k,t1,t2,ans;

int Power(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b%2)ans=(long long)ans*a%1000000009;
		a=(long long)a*a%1000000009;
		b/=2;
	}
	return ans;
}

int main()
{
	scanf("%d%d%d",&n,&m,&p);
	k=n-m;
	if((long long)(k+1)*(p-1)>=m)
	{
		printf("%d\n",m);
		return 0;
	}
	t1=m-k*(p-1);t2=k*(p-1);
	ans=(long long)(Power(2,t1/p+1)+1000000008)*p%1000000009;
	ans+=1000000009-p;if(ans>=1000000009)ans-=1000000009;
	ans+=t1%p;if(ans>=1000000009)ans-=1000000009;
	ans+=t2;if(ans>=1000000009)ans-=1000000009;
	printf("%d\n",ans);
}