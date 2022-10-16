#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,len;
char buf[233333];
int pre[233],nex[233];
int f[26],ff[26];
int main()
{
	memset(pre,-1,sizeof(pre));
	memset(nex,-1,sizeof(nex));
	scanf("%d",&n);
	for(int t=1;t<=n;t++)
	{
		scanf(" %s",buf);
		len=strlen(buf);
		memset(f,0,sizeof(f));
		for(int i=0;i<len;i++)
		{
			if(f[buf[i]-'a'])
			{
				printf("NO\n");
				return 0;
			}
			f[buf[i]-'a']=1;
			ff[buf[i]-'a']=1;
		}
		for(int i=1;i<len;i++)
		{
			if(pre[buf[i]-'a']!=-1&&pre[buf[i]-'a']!=buf[i-1]-'a')
			{
				printf("NO\n");
				return 0;
			}
			pre[buf[i]-'a']=buf[i-1]-'a';
			//cout<<buf[i]<<' '<<char(pre[buf[i]-'a']+'a')<<endl;
			if(nex[buf[i-1]-'a']!=-1&&nex[buf[i-1]-'a']!=buf[i]-'a')
			{
				printf("NO\n");
				return 0;
			}
			nex[buf[i-1]-'a']=buf[i]-'a';
		}
	}
	int cnt=0,cnt2=0;
	for(int i=0;i<26;i++)
	{
		if(ff[i])
		{
			cnt++;
			if(pre[i]==-1)
			{
				for(int j=i;j!=-1;j=nex[j])
				{
					cnt2++;
				}
			}
		}
	}
	if(cnt!=cnt2)
	{
		printf("NO\n");
		return 0;
	}
	for(int i=0;i<26;i++)
	{
		if(ff[i])
		{
			if(pre[i]==-1)
			{
				for(int j=i;j!=-1;j=nex[j])
				{
					printf("%c",j+'a');
				}
			}
		}
	}
	printf("\n");
	return 0;
}