#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,k;
int a[10010];
int fs,ts,os;
int main()
{
	scanf("%d%d",&n,&k);
	fs=n,ts=2*n;
	for(int i=1;i<=k;i++)scanf("%d",&a[i]);
	for(int i=1;i<=k;i++)
	{
		if(a[i]%2)
		{
			if(fs)
				fs--,ts++,a[i]--;
			else if(ts)
				ts--,a[i]--;
			else
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	for(int i=1;i<=k;i++)
	{
		if(fs)
		{
			int r=min(a[i]/4,fs);
			fs-=r,a[i]-=r*4;
		}
	}
	if(fs>0)ts+=fs,os=fs,fs=0;
	for(int i=1;i<=k;i++)
	{
		if(a[i]/2<=ts) ts-=a[i]/2;
		else if(a[i]<=os) os-=a[i];
		else
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}