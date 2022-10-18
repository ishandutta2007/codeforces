#include<bits/stdc++.h>
using namespace std;
int a[12345];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long x;
		long long y;
		scanf("%lld %lld",&x,&y);
		if(x>y+1)
		{
			printf("NO\n");
			continue;
		}
		int flag = 0;
		for(long long i = 2;i*i<=x+y;i++)
		{
			if((x+y)%i==0) 
			{
				printf("NO\n");
				flag = 1;
				break;
			}
		}
		if(flag==0) printf("YES\n");
	}
	return 0;
}