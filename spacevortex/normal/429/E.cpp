#include<bits/stdc++.h>
using namespace std;
char gc()
{
	static char buf[1<<15],*p1,*p2;
	if(p1==p2) p2=(p1=buf)+fread(buf,1,1<<15,stdin);
	if(p1==p2) return EOF;
	else return *(p1++);
}
int rd()
{
	int rx=0,fx=1;char c=gc();
	while(c<48||c>57)
	{
		if(c=='-') fx=-1;
		c=gc();
	}
	while(c>=48&&c<=57)
	{
		rx=rx*10+c-48;
		c=gc();
	}
	return rx*fx;
}
const int N=3e5+50;
int n,tot=0,cnt=1;
int l[N],r[N],p[N],he[N],evi[N],col[N],vis[N],ds[N];
struct Edge
{
	int v,nxt;
}e[N];
void eadd(int u,int v)
{
	cnt++;e[cnt].v=v;e[cnt].nxt=he[u];he[u]=cnt;
}
void dfs(int x)
{
	int v;
	vis[x]=1;
	for(int &i=he[x];i;i=e[i].nxt)
	{
		if(evi[i>>1]) continue;
		v=e[i].v;
		evi[i>>1]=1;
		col[i>>1]=(x<v);
		dfs(v);
	}
}
int main()
{
	int i,las;
	n=rd();
	for(i=1;i<=n;i++)
	{
		l[i]=rd();r[i]=rd();r[i]++;
		p[++tot]=l[i];p[++tot]=r[i];
	}
	sort(p+1,p+tot+1);
	tot=unique(p+1,p+tot+1)-p-1;
	for(i=1;i<=n;i++)
	{
		l[i]=lower_bound(p+1,p+tot+1,l[i])-p;
		r[i]=lower_bound(p+1,p+tot+1,r[i])-p;
	}
	for(i=1;i<=n;i++) 
	{
		eadd(l[i],r[i]);eadd(r[i],l[i]);
		ds[l[i]]++;ds[r[i]]++;
	}
	for(i=1,las=-1;i<=tot;i++)
	{
		if(ds[i]&1)
		{
			if(las==-1) las=i;
			else eadd(las,i),eadd(i,las),las=-1;
		}
	}
	for(i=1;i<=tot;i++)
	{
		if(vis[i]==0) dfs(i);
	}
	for(i=1;i<=n;i++) printf("%d ",col[i]);
	return 0;
}