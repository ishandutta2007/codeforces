#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+2,M=2e5+2;
int lj[M],nxt[M],fir[N],dep[N],md[N],f[N];
int n,c,fh,i,t,a,b,da,db,bs,x,y;
bool ed[N];
inline void add()
{
	lj[++bs]=y;
	nxt[bs]=fir[x];
	fir[x]=bs;
	lj[++bs]=x;
	nxt[bs]=fir[y];
	fir[y]=bs;
}
inline void read(int &x)
{
	c=getchar();fh=1;
	while ((c<48)||(c>57))
	{
		if (c=='-') {c=getchar();fh=-1;break;}
		c=getchar();
	}
	x=c^48;c=getchar();
	while ((c>=48)&&(c<=57))
	{
		x=x*10+(c^48);
		c=getchar();
	}
	x*=fh;
}
void dfs(int x)
{
	ed[x]=1;md[x]=dep[x];
	for (int i=fir[x];i;i=nxt[i]) if (!ed[lj[i]])
	{
		dep[lj[i]]=dep[x]+1;
		dfs(lj[i]);
		md[x]=max(md[x],md[lj[i]]);
	}
}
void dfsf(int x)
{
	ed[x]=1;md[x]=dep[x];
	for (int i=fir[x];i;i=nxt[i]) if (!ed[lj[i]])
	{
		dep[lj[i]]=dep[x]+1;
		f[lj[i]]=x;
		dfsf(lj[i]);
		md[x]=max(md[x],md[lj[i]]);
	}
}
int main()
{
	//freopen("a.in","r",stdin);
	read(t);
	while (t--)
	{
		memset(fir+1,bs=0,n<<2);
		memset(f+1,0,n<<2);
		memset(dep+1,0,n<<2);
		memset(md+1,0,n<<2);
		memset(ed+1,0,n*sizeof(bool));
		read(n);read(a);read(b);read(da);read(db);
		for (i=1;i<n;i++)
		{
			read(x);read(y);add();
		}
		if (da+da>=db) {puts("Alice");continue;}
		dep[b]=1;dfs(b);if (dep[a]-1<=da) {puts("Alice");continue;}
		for (i=1;i<=n;i++) if (md[b]==dep[i]) break;
		memset(ed+1,0,n*sizeof(bool));
		memset(dep+1,0,n<<2);
		memset(md+1,0,n<<2);
		dep[i]=1;//printf("%d\n",i);
		dfs(i);if (md[i]-1<=da+da) {puts("Alice");continue;}/*
		memset(ed+1,0,n*sizeof(bool));
		memset(dep+1,0,n<<2);
		memset(md+1,0,n<<2);
		ed[b]=1;dfs(a);
		memset(md+1,0,n<<2);
		memset(dep+1,0,n<<2);
		dep[b]=1;dfs(b);
		for (i=1;i<=n;i++) if (dep[i]==md[b]) break;
		memset(ed+1,0,n*sizeof(bool));
		memset(dep+1,0,n<<2);
		memset(md+1,0,n<<2);
		dfs(i);
		for (i=1;i<=n;i++) if (md[i]-1>da+da+1) {n=0;puts("Bob");break;}
		if (!n) continue;
		memset(ed+1,0,n*sizeof(bool));
		dfsf(b);*/
		puts("Bob");
	}
}