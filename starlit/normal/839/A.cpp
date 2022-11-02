#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,k,a,now;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);now+=a;
		if(now>=8)now-=8,k-=8;
		else k-=now,now=0;
		if(k<=0)
		{
			printf("%d",i);
			return 0;
		}
	}
	puts("-1");
}