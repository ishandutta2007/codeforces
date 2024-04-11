#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int n,m,K,i,j,k;
char p[1000005],q[2005],s[205],ans[2005];
bool founded;

bool check(int x,int y,int z)
{
	int i,j;
	if(!z)return false;
	for(i=z,j=y;i<=n;i+=K,j+=x)
	{
		if(j>m)return false;
		if(p[i]!=s[j])return false;
	}
	if(j<=m)return false;
	return true;
}

int main()
{
	gets(p+1);n=strlen(p+1);
	gets(s+1);m=strlen(s+1);
	scanf("%d",&K);
	founded=false;
	for(i=1;i<=m;++i)
	{
		k=i;
		for(j=K;j;--j)
		if(check(i,k,j))
		{
			--k;
			q[j]='1';
		}else q[j]='0';
		if(!k)
		{
			if(!founded)
			{
				memcpy(ans,q,sizeof(ans));
				founded=true;
			}
			else
			{
				for(j=1;j<=K;++j)if(ans[j]!=q[j])break;
				if(q[j]<ans[j])memcpy(ans,q,sizeof(ans));
			}
		}
	}
	if(!founded)printf("0\n");
	else printf("%s\n",ans+1);
}