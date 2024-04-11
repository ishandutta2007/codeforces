#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n,i,j,k,l,r;
int f[2605][2605];
char s[100005],ans[100005];

void Max(int &x,int y){if(y>x)x=y;}

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	if(n>2600)n=2600;
	s[n+1]=0;
	for(i=1;i<n;++i)if(s[i]==s[i+1])f[i][i+1]=2;
	for(k=0;k<n;++k)
	for(i=n-k;i>=1;--i)
	{
		j=i+k;
		Max(f[i-1][j],f[i][j]);
		Max(f[i][j+1],f[i][j]);
		if(s[i-1]==s[j+1])Max(f[i-1][j+1],f[i][j]+2);
	}
	if(f[1][n]>=100)
	{
		k=0;l=1;r=n;
		while(l<=r)
		{
			if(s[l]==s[r])
			{
				ans[++k]=s[l];
				++l;--r;
				continue;
			}
			if(f[l][r]==f[l+1][r]){++l;continue;}
			if(f[l][r]==f[l][r-1]){--r;continue;}
		}
		for(i=1;i<=50;++i)printf("%c",ans[i]);
		for(i=50;i>=1;--i)printf("%c",ans[i]);
		printf("\n");
		return 0;
	}
	for(i=1;i<=n;++i)f[i][i]=1;
	for(k=0;k<n;++k)
	for(i=n-k;i>=1;--i)
	{
		j=i+k;
		Max(f[i-1][j],f[i][j]);
		Max(f[i][j+1],f[i][j]);
		if(s[i-1]==s[j+1])Max(f[i-1][j+1],f[i][j]+2);
	}
	k=0;l=1;r=n;
	while(l<=r)
	{
		if(s[l]==s[r])
		{
			ans[++k]=s[l];
			++l;--r;
			continue;
		}
		if(f[l][r]==f[l+1][r]){++l;continue;}
		if(f[l][r]==f[l][r-1]){--r;continue;}
	}
	for(i=1;i<=k;++i)printf("%c",ans[i]);
	for(i=k+1;i<=f[1][n];++i)printf("%c",ans[f[1][n]-i+1]);
	printf("\n");
}