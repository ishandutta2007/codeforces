#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n,m,Sum;
int cost[50][50],f[1<<20],to[50][50],sum[50][50];
char s[50][50];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&cost[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			to[i][j]=1<<(i-1);
			for(int k=1;k<=n;k++)
				if(i!=k&&s[i][j]==s[k][j])to[i][j]|=1<<(k-1),sum[i][j]+=cost[k][j];
		}
	memset(f,0x7f,sizeof(f));
	f[0]=0;
	Sum=1<<n;
	for(int j=1;j<=m;j++)
		for(int now=0;now<Sum;now++)
			if(f[now]!=0x7f7f7f7f)
				for(int i=1;i<=n;i++)
						f[now|1<<(i-1)]=min(f[now|1<<(i-1)],f[now]+cost[i][j]),
						f[now|to[i][j]]=min(f[now|to[i][j]],f[now]+sum[i][j]);
	printf("%d",f[Sum-1]);
}