#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
int n,m;
char t[200010],p[200010];
int pos[200010],del[200010];
int main()
{
	scanf("%s%s",t+1,p+1);
	int len=strlen(p+1),len2=strlen(t+1);
	for(int i=1;i<=len2;i++)scanf("%d",&pos[i]);
	int l=0,r=strlen(t+1);
	while(l<r)
	{
		memset(del,0,sizeof(del));
		int mid=(l+r+1)/2;
		for(int i=1;i<=mid;i++)
		{
			del[pos[i]]=1;
		}
		int cur=0;
		for(int i=1;i<=len2;i++)
		{
			if(del[i]==1)continue;
			if(t[i]==p[cur+1])cur++;
			if(cur==len)break;
		}
		if(cur==len)l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
	return 0;
}