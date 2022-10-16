#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,m;
int c[2][333333];
long long ans=0;
char s[333333];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		int l=strlen(s+1),cnt=0,minn=0;
		for(int j=1;j<=l;j++)
		{
			cnt+=(s[j]=='('?1:-1);
			minn=min(minn,cnt);
		}
		if(minn>=0)c[0][cnt]++;
		cnt=minn=0;
		for(int j=l;j>=1;j--)
		{
			cnt+=(s[j]==')'?1:-1);
			minn=min(minn,cnt);
		}
		if(minn>=0)c[1][cnt]++;
	}
	for(int i=0;i<=300000;i++)ans+=1ll*c[0][i]*c[1][i];
	printf("%lld\n",ans);
	return 0;
}