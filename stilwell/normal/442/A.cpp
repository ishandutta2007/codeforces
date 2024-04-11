#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,i,j,k,ans,tmp,a1[10],a2[10];
bool f[10][10],use1[10],use2[10];
char s[5];

void dfs(int x)
{
	if(x>10)
	{
		int i,j,k;
		k=0;
		for(i=1;i<=5;++i)a1[i]=a2[i]=0;
		for(i=1;i<=5;++i)
		for(j=1;j<=5;++j)
		if(f[i][j])
		{
			if((use1[i])&&(!use2[j]))++a1[i];
			if((!use1[i])&&(use2[j]))++a2[j];
			if((!use1[i])&&(!use2[j]))++k;
		}
		if(k>1)return;
		for(i=1;i<=5;++i)
		{
			if(a1[i]>1)return;
			if(a2[i]>1)return;
		}
		k=0;
		for(i=1;i<=5;++i)
		{
			if(use1[i])++k;
			if(use2[i])++k;
		}
		if(k<ans)ans=k;
		return;
	}
	if(x<=5)
	{
		use1[x]=true;dfs(x+1);
		use1[x]=false;dfs(x+1);
	}
	else
	{
		use2[x-5]=true;dfs(x+1);
		use2[x-5]=false;dfs(x+1);
	}
}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		if(s[1]=='R')s[1]=1;
		if(s[1]=='G')s[1]=2;
		if(s[1]=='B')s[1]=3;
		if(s[1]=='Y')s[1]=4;
		if(s[1]=='W')s[1]=5;
		s[2]-='0';
		f[s[1]][s[2]]=true;
	}
	ans=10000000;
	tmp=0;
	for(i=1;i<=5;++i)
	for(j=1;j<=5;++j)
	if(f[i][j])++tmp;
	if(tmp<=1)
	{
		printf("0\n");
		return 0;
	}
	dfs(1);
	printf("%d\n",ans);
}