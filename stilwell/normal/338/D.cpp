#include <stdio.h>
#include <stdlib.h>
using namespace std;

long long n,m,a[10005],Lcm,g,tmp,t,rem,ans;
long long K,i,j,k;

long long gcd(long long a,long long b){if(!b)return a;return gcd(b,a%b);}
void ex_gcd(long long a, long long b, long long &x, long long &y)
{
    if(!b)x=1,y=0;
    else ex_gcd(b,a%b,y,x),y-=a/b*x;
}
inline long long Div(long long a, long long p) {
    long long x, y;
    ex_gcd(a,p,x,y);
    if(x<0)x+=p;
    return x;
}
void fail(){printf("NO\n");exit(0);}

int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&K);
	Lcm=1;
	for(i=0;i<K;++i)
	{
		scanf("%I64d",&a[i]);
		g=gcd(Lcm,a[i]);
		if(Lcm>n/(a[i]/g))fail();
		if(a[i]>n||a[i]>m)fail();
		Lcm/=g;Lcm*=a[i];
	}
	tmp=Lcm;
	for(i=2;i<=tmp;++i)
	{
		if((long long)i*i>tmp)i=tmp;
		if(tmp%i==0)
		{
			for(t=1;tmp%i==0;t*=i)tmp/=i;
			rem=-1;
			for(j=0;j<K;++j)
			if(a[j]%t==0)
			{
				if(rem==-1)
				{
					ans=(ans-Div(Lcm/t,t)*(Lcm/t)%Lcm*j)%Lcm;
					rem=j%t;
				}
				else
				{
					if(j%t!=rem)fail();
				}
			}
		}
	}
	ans=(ans+Lcm)%Lcm;
	if(ans+K-1>m)fail();
	for(i=0;i<K;++i)if(gcd(ans+i,Lcm)!=a[i])fail();
	printf("YES\n");
}