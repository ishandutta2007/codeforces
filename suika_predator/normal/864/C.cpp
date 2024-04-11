#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int a,b,f,k;

int main()
{
	scanf("%d%d%d%d",&a,&b,&f,&k);
	int cur=b-f,dir=1,ans=0;
	if(cur<0)
	{
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=k-1;i++)
	{
		if(dir==1)
		{
			if((a-f)*2>b)
			{
				printf("-1\n");
				return 0;
			}
			else if((a-f)*2>cur)
			{
				cur=b-(a-f)*2;
				ans++;
			}
			else
			{
				cur-=(a-f)*2;
			}
		}
		else
		{
			if(f*2>b)
			{
				printf("-1\n");
				return 0;
			}
			else if(f*2>cur)
			{
				cur=b-f*2;
				ans++;
			}
			else
			{
				cur-=f*2;
			}
		}
		dir^=1;
	}
	if(dir==1)
	{
		if(b<a-f)
		{
			printf("-1\n");
			return 0;
		}
		else if(cur<a-f)
		{
			ans++;
		}
	}
	else
	{
		if(b<f)
		{
			printf("-1\n");
			return 0;
		}
		else if(cur<f)
		{
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}