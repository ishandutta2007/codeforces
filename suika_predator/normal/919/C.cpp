#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,m,k;
char a[2333][2333];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	int cn=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf(" %c",&a[i][j]);
			if(a[i][j]=='.')cn++;
		}
	}
	if(k==1)return printf("%d\n",cn),0;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='.')cnt++;
			else cnt=0;
			if(cnt>=k)ans++;
		}
	}
	for(int j=1;j<=m;j++)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i][j]=='.')cnt++;
			else cnt=0;
			if(cnt>=k)ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}