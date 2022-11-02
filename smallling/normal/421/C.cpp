#include<cstdio>
#include<cstring>

int n,m,ans[100010],p[100010],pre[100010],pre1[100010],a[100010],now,anssum,bo[100010];
char ch;

int main()
{
	scanf("%d%d",&n,&m);
	memset(bo,-1,sizeof(bo));
	for(int i=1;i<=m;i++)
	{
		ch=getchar();
		while(ch!='+'&&ch!='-')ch=getchar();
		if(ch=='+')p[i]=1;
		else p[i]=0;
		scanf("%d",&a[i]);
		if(bo[a[i]]==-1)bo[a[i]]=p[i]?0:1;
	}
	for(int i=1;i<=n;i++)
		if(bo[i]==1)now++;
	if(now>0)
	for(int i=1;i<=n;i++)
		if(bo[i]==0)ans[i]=1;
	for(int i=1;i<=m;i++)
		if(!p[i])pre[i]=a[i];else pre[i]=pre[i-1];
	pre1[m+1]=n+1;
	for(int i=m;i;i--)
		if(p[i])pre1[i]=a[i];else pre1[i]=pre1[i+1];
	for(int i=1;i<=m;i++)
	if(p[i]==1)
	{
		if(now>0)ans[a[i]]=1;
		if(pre[i]!=0&&pre[i]!=a[i])ans[a[i]]=1;
		now++;
	}
	else
	{
		now--;
		if(pre1[i]!=n+1&&pre1[i]!=a[i])ans[a[i]]=1;
		if(now>0)ans[a[i]]=1;
	}
	for(int i=1;i<=n;i++)
		if(!ans[i])anssum++;
	printf("%d\n",anssum);
	for(int i=1;i<=n;i++)
		if(!ans[i])printf("%d ",i);
}