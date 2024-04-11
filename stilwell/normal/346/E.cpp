#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int T,a,n,p,h,i,j,k,ans;

int cal(int x,int y,int z)
{
	if((long long)x*y<z)
	{
		if(z==p)return x;
		else return max(x,z-x*y);
	}
	int tmp=(long long)x*y/z;
	if((long long)x*y%z+x<=z/x*x)--tmp;
	return cal(min(x-z%x,z%x),tmp,x);
}

int main()
{
	scanf("%d",&T);
	for(;T;--T)
	{
		scanf("%d%d%d%d",&a,&n,&p,&h);
		if(cal(a%p,n,p)<=h)printf("YES\n");
		else printf("NO\n");
	}
}