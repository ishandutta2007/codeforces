#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
long long a,b;
int main()
{
	scanf("%I64d%I64d",&a,&b);
	if(b-a>100)return printf("0\n"),0;
	else
	{
		int ans=1;
		for(long long i=a+1;i<=b;i++)
		{
			ans=(ans*(i%10))%10;
		}
		printf("%d\n",ans);
	}
	return 0;
}