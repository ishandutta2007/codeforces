#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
const int MOD=998244353,SHIFT=29;
int n,m;
char buf[5010];
int Hash[5010][5010];
short palin[5010][5010];
int ans[15];
int main()
{
	scanf("%s",buf);
	int len=strlen(buf);
	for(int i=0;i<len;i++)
	{
		for(int j=i;j<len;j++)
		{
			Hash[i][j]=((long long)Hash[i][j-1]*SHIFT+buf[j]-'a'+1)%MOD;
		}
	}
	for(int i=0;i<len;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			Hash[i][j]=((long long)Hash[i][j+1]*SHIFT+buf[j]-'a'+1)%MOD;
		}
	}
	for(int i=0;i<len;i++)
	{
		for(int j=i;j<len;j++)
		{
			if(Hash[i][j]==Hash[j][i])
			{
				palin[i][j]=1;
				ans[1]++;
			}
		}
	}
	for(int l=2;l<=13;l++)
	{
		for(int i=0;i<len;i++)
		{
			for(int j=i+1;j<len;j++)
			{
				int d=(j-i-1)/2;
				if(palin[i][j]>=l-1&&palin[i][i+d]>=l-1&&palin[j-d][j]>=l-1)
				{
					ans[l]++;
					palin[i][j]=l;
				}
			}
		}
	}
	for(int i=1;i<=len;i++)
	{
		if(i<=13)printf("%d ",ans[i]);
		else printf("0 ");
	}
	return 0;
}