#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;

long long n,m;

int main()
{
	scanf("%lld",&n);
	//for(long long n=50;n<=100;n++)
	{
		if(n<5)
		{
			printf("%lld\n",n*(n-1)/2);
			return 0;
		}
		long long tmp=5;
		while(tmp<=n)tmp*=10;
		tmp/=10;
		long long d=tmp*2,q=n/d,r=n%d;
		//cout<<q<<' '<<r<<endl;
		long long ans=tmp*q*q;
		if(r>=tmp)ans+=r*q+r-tmp+1;
		else ans+=r*q;
		printf("%lld\n",ans-(n%d==d-1));
	}
	return 0;
}