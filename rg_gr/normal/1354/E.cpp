#include <stdio.h>
#include <stdlib.h>
#include <string.h>
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
    return num*f;
}
struct Edge{
	int v,nxt;
}e[200005];
int cnt=1,h[10005];
void addedge(int u,int v)
{
	e[cnt]=(Edge){v,h[u]};
	h[u]=cnt++;
}
int c[10005];
int p;
int A[10005],B[10005],bel[10005];
void dfs(int u,int fa,int cc)
{
	c[u]=cc;bel[u]=p;
	if(cc==1)A[p]++;
	else B[p]++;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa||v==u)continue;
		if(c[v])
		{
			if(c[v]==c[u])
			{
				puts("NO");
				exit(0);
			}
		}
		else dfs(v,u,3-cc);
	}
}
int mmr[5005][10005],n1,n2,n3,n;
int dfs(int i,int f)
{
	if(f>n2||i>p)return 0;
	if(mmr[i][f]!=-1)return mmr[i][f];
	if(f==n2&&i==p)return mmr[i][f]=1;
	if(dfs(i+1,f+A[i]))return mmr[i][f]=1;
	if(dfs(i+1,f+B[i]))return mmr[i][f]=1;
	return mmr[i][f]=0;
}
int ch[10005];
int fin[10005];
int main()
{
	n=read();int m=read();
	n1=read(),n2=read(),n3=read();
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		addedge(x,y);
		addedge(y,x);
	}
	for(int i=1;i<=n;i++)
	{
		if(c[i]==0)dfs(i,i,1),p++;
	}
	memset(mmr,-1,sizeof(mmr));
	if(dfs(0,0))
	{
		puts("YES");
		int i=0,f=0;
		while(f!=n2)
		{
			if(f+A[i]<=n2&&mmr[i+1][f+A[i]])
			{
				i++,f+=A[i-1],ch[i-1]=1;
			}
			else i++,f+=B[i-1],ch[i-1]=0;
		}
		for(int i=1;i<=n;i++)
		{
			int p=bel[i];
			if(ch[p]!=c[i]-1)fin[i]=2;
		}
		int u=0;
		for(int i=1;i<=n;i++)if(!fin[i])
			if(u<n1)fin[i]=1,u++;
			else fin[i]=3,u++;
		for(int i=1;i<=n;i++)printf("%d",fin[i]);
	}
	else puts("NO");
}
/*
6 3
2 2 2
3 1
5 4
2 5
*/