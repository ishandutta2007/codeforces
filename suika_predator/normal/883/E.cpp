#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,m;
int vis[50],cnt[50],ttt[50];
char str[233],buf[233];
int main()
{
	memset(cnt,0,sizeof(cnt));
	scanf("%d %s%d",&n,str,&m);
	int t=m;
	for(int i=0;i<n;i++)
	{
		if(str[i]!='*')vis[str[i]-'a']=1;
	}
	for(int i=1;i<=m;i++)
	{
		scanf(" %s",buf);
		bool flag=true;
		for(int j=0;j<n;j++)
		{
			if(str[j]=='*'&&vis[buf[j]-'a']==1)
			{
				flag=false;
				t--;
				break;
			}
			if(str[j]!='*'&&str[j]!=buf[j])
			{
				flag=false;
				t--;
				break;
			}
		}
		if(!flag)continue;
		for(int j=0;j<n;j++)
		{
			if(str[j]=='*')ttt[buf[j]-'a']=1;
		}
		for(int j=0;j<26;j++)cnt[j]+=ttt[j],ttt[j]=0;
	}
	int ans=0;
	for(int i=0;i<26;i++)
	{
		if((!vis[i])&&cnt[i]==t)
		{
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}