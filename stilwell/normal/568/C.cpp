#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int n,m,l,i,j,k,u,v;
int son[1005],next[400005],ed[400005],tot;
char vc[105],s[1005],c1,c2;
bool vis[1005],vt[1005],V,C,rev;

void add(int u,int v){++tot;next[tot]=son[u];son[u]=tot;ed[tot]=v;}

void dfs(int x)
{
	vis[x]=true;
	for(int i=son[x];i;i=next[i])
	if(!vis[ed[i]])dfs(ed[i]);
}

int main()
{
	scanf("%s",vc+1);
	l=strlen(vc+1);
	if(vc[1]=='C')
	{
		for(i=1;i<=l;++i)
		if(vc[i]=='V')vc[i]='C';else vc[i]='V';
		rev=true;
	}
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d",&u);
		for(c1=getchar();c1!='V'&&c1!='C';c1=getchar());
		scanf("%d",&v);
		for(c2=getchar();c2!='V'&&c2!='C';c2=getchar());
		if(rev)
		{
			if(c1=='V')c1='C';else c1='V';
			if(c2=='V')c2='C';else c2='V';
		}
		add(u+n*(c1=='V'),v+n*(c2=='V'));
		add(v+n*(c2=='C'),u+n*(c1=='C'));
	}
	scanf("%s",s+1);
	for(i=1;i<=n;++i)s[i]=s[i]-'a'+1;
	for(i=1;i<=l;++i)
	if(vc[i]=='C')break;
	if(i>l)
	{
		for(i=1;i<=n;++i)
		add(i,i+n);
	}
	
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n+n;++j)vis[j]=false;
		dfs(i);
		if(vis[i+n])
		{
			for(j=1;j<=n+n;++j)vis[j]=false;
			dfs(i+n);
			if(vis[i])
			{
				printf("-1\n");
				return 0;
			}
		}
	}
	
	for(i=n;i>=1;--i)
	{
		V=C=false;
		for(j=s[i]+(i!=n);j<=l;++j)
		{
			for(k=1;k<=n+n;++k)vis[k]=false;
			if(vc[j]=='V')
			{
				if(V)continue;
				dfs(i+n);
				V=true;
			}
			else
			{
				if(C)continue;
				dfs(i);
				C=true;
			}
			for(k=1;k<i;++k)dfs(k+n*(vc[s[k]]=='V'));
			for(k=1;k<=n;++k)if(vis[k]&&vis[k+n])break;
			if(k<=n)continue;
			
			for(k=i+1;k<=n;++k)
			if(!vis[k]&&!vis[k+n])
			{
				for(u=1;u<=n+n;++u)vt[u]=vis[u];
				dfs(k+n);
				for(u=1;u<=n;++u)if(vis[u]&&vis[u+n])break;
				if(u<=n)
				{
					for(u=1;u<=n+n;++u)vis[u]=vt[u];
					dfs(k);
				}
			}
			
			for(k=1;k<i;++k)printf("%c",'a'+s[k]-1);
			printf("%c",'a'+j-1);
			for(u=1;u<=l;++u)if(vc[u]=='C')break;
			for(k=i+1;k<=n;++k)
			if(vis[k])printf("%c",'a'+u-1);
			else printf("a");
			return 0;
		}
	}
	printf("-1\n");
}