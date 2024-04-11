#include<bits/stdc++.h>
#define pb push_back
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
void wrt(int x)
{
	if(x>=10) wrt(x/10);
	putchar(x%10+48);
}
const int N=5e5+50;
int n,ans=0;
int fa2[N],fa[N],a[N],b[N],c[N],d[N];
vector<int> e1[N],e2[N];
int getft(int x)
{
	if(x==fa[x]) return x;
	else return fa[x]=getft(fa[x]);
}
void dfs2(int x,int nf)
{
	fa2[x]=nf;
	for(int v:e2[x])
	{
		if(v==nf) continue;
		dfs2(v,x);
	}
}
void dfs1(int x,int nf)
{
	for(int v:e1[x])
	{
		if(v==nf) continue;
		dfs1(v,x);
	}
	if(x!=1)
	{
		if(fa2[x]==nf) fa[x]=nf;
		else if(fa2[nf]==x) fa[nf]=x;
		else
		{
			int bf=getft(x);
			ans++;
			a[ans]=x;b[ans]=nf;c[ans]=bf;d[ans]=fa2[bf];
			fa[bf]=fa2[bf];
		}
	}
}
int main()
{
	int i,u,v;
	n=rd();
	for(i=1;i<n;i++)
	{
		u=rd();v=rd();
		e1[u].pb(v);e1[v].pb(u);
	}
	for(i=1;i<n;i++)
	{
		u=rd();v=rd();
		e2[u].pb(v);e2[v].pb(u);
	}
	dfs2(1,0);
	for(i=1;i<=n;i++) fa[i]=i;
	dfs1(1,0);
	wrt(ans);putchar('\n');
	for(i=1;i<=ans;i++)
	{
		wrt(a[i]);putchar(' ');wrt(b[i]);putchar(' ');
		wrt(c[i]);putchar(' ');wrt(d[i]);putchar('\n');
	}
	return 0;
}