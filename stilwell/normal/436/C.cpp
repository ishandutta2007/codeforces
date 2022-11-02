#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,K,w,i,j,k,a,b,tmp,aim;
char s[1005][15][15];
int cost[1005][1005];
int q[1005],fa[1005],Min[1005],from[1005],ans;
bool use[1005];

int main()
{
	scanf("%d%d%d%d",&n,&m,&K,&w);
	for(i=1;i<=K;++i)
	for(j=1;j<=n;++j)
	scanf("%s",s[i][j]+1);
	for(i=1;i<=K;++i)
	for(j=i+1;j<=K;++j)
	{
		tmp=0;
		for(a=1;a<=n;++a)
		for(b=1;b<=m;++b)
		if(s[i][a][b]!=s[j][a][b])
		++tmp;
		cost[i][j]=cost[j][i]=tmp*w;
	}
	for(i=1;i<=K;++i)cost[0][i]=cost[i][0]=n*m;
	for(i=1;i<=K;++i)Min[i]=n*m;
	for(i=1;i<=K;++i)
	{
		aim=0;
		for(j=1;j<=K;++j)
		if(!use[j])
		{
			if((!aim)||(Min[j]<Min[aim]))
			aim=j;
		}
		q[i]=aim;
		fa[aim]=from[aim];
		use[aim]=true;
		ans+=Min[aim];
		for(j=1;j<=K;++j)if(cost[aim][j]<Min[j])Min[j]=cost[aim][j],from[j]=aim;
	}
	printf("%d\n",ans);
	for(i=1;i<=K;++i)printf("%d %d\n",q[i],fa[q[i]]);
}