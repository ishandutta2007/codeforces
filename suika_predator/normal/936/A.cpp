#include<iostream>
#include<cstdio>
using namespace std;
long long k,d,t;
int main()
{
	scanf("%lld%lld%lld",&k,&d,&t);
	t*=2;
	long long cyc=(k/d+(k%d!=0))*d,prog=k+cyc,left=t%prog;
	double ans=t/prog*cyc;
	if(left<k*2)ans+=1.0*left/2;
	else ans+=k+1.0*(left-k*2);
	printf("%.10lf",ans);
	return 0;
}