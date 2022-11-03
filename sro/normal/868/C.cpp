#include<iostream>
#include<cstdio>
using namespace std;
int n,k;
bool f[16];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		int s=0;
		for(int j=1;j<=k;j++)
		{
			int x;
			scanf("%d",&x);
			s=s*2+x;
		}
		f[s]=true;
	}
	if(f[0])
	{
		printf("YES");
		return 0;
	}
	for(int i=0;i<(1<<k);i++)
	{
		if(!f[i])continue;
		for(int j=i+1;j<(1<<k);j++)
		{
			if(!f[j])continue;
			bool ff=true;
			for(int t=0;t<k;t++)
			{
				if(((i>>t)&1)+((j>>t)&1)>1)
				{
					ff=false;break;
				}
			}
			if(!ff)continue;
			printf("YES");
			return 0;
		}
	}
	printf("NO");
	return 0;
}