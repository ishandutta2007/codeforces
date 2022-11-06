#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int a,b,c,d,l=0,r=2147483647,mid;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	while(l<r)
	{
		mid=(long long)l+r>>1;
		if(mid-mid/c/d>=a+b&&mid-mid/c>=a&&mid-mid/d>=b)
			r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
}