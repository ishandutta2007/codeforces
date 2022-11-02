#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n,m,i,j,k;
char s[1005],t[1005];

void print()
{
	for(int i=1;i<=n;++i)printf("%c",t[i]+'a');
	exit(0);
}

int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(i=1;i<=n;++i)s[i]-='a';
	++s[n];
	for(i=n;i>=1;--i)
	if(s[i]==m)s[i]=0,++s[i-1];
	if(s[0]!=0)
	{
		printf("NO\n");
		return 0;
	}
	for(i=2;i<=n;++i)
	{
		if(s[i]==s[i-1])break;
		if(i>2&&s[i]==s[i-2])break;
	}
	for(--i;i>=0;--i)
	{
		for(j=1;j<=i;++j)t[j]=s[j];
		if(i==n)print();
		for(t[i+1]=s[i+1]+1;t[i+1]<m;++t[i+1])
		{
			if(i>0&&t[i+1]==t[i])continue;
			if(i>1&&t[i+1]==t[i-1])continue;
			if(i+1==n)print();
			for(j=i+2;j<=n;++j)
			{
				for(k=0;k<m;++k)
				if(k!=t[j-1]&&((i==0&&j==2)||k!=t[j-2]))
				break;
				if(k==m)break;
				t[j]=k;
			}
			if(j>n)print();
		}
	}
	printf("NO\n");
}