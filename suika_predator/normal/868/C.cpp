#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,k;
int cnt[16];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		int tmp,r=0;
		for(int j=0;j<k;j++)
		{
			scanf("%d",&tmp);
			r+=tmp*(1<<j);
		}
		cnt[r]++;
	}
	for(int i=0;i<1<<k;i++)
	{
		for(int j=0;j<1<<k;j++)
		{
			if(((i&j)==0)&&cnt[i]&&cnt[j])
			{
				printf("YES\n");
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}