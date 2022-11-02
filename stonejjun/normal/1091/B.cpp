#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int a,b=0,c=0,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
	scanf("%lld",&n);
	for(i=1;i<=2*n;i++)
	{
		scanf("%lld %lld",&x,&y);
		b+=x;
		c+=y;
	}
	b=b/n;
	c=c/n;
	printf("%lld %lld",b,c);
}