#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int w,x;
	Node(){}
	Node(int _w,int _x){w=_w;x=_x;}
};
Node qmin(Node a,Node b)
{
	if(a.w<b.w) return a;
	else return b;
}
const int N=1e6+50,inf=1e7;
int n,m,tot,now,id;
int a[N];
Node f[N];
char sa[N],sb[N];
int len[N],fail[N],slk[N],nxt[N][26];
Node g[N];
void ins(int c)
{
	int x;
	while(a[id]!=a[id-len[now]-1]) now=fail[now];
	//printf("U%d %d %d   %d\n",id,now,c,len[now]);
	if(nxt[now][c]) now=nxt[now][c];
	else
	{
		x=now;
		now=nxt[x][c]=++tot;
		len[now]=len[x]+2;
		x=fail[x];
		while(x>0&&(nxt[x][c]==0||a[id]!=a[id-len[x]-1])) x=fail[x];
		if(x) fail[now]=nxt[x][c];
		else fail[now]=2;
		if(len[fail[fail[now]]]*2>=len[fail[now]]&&len[fail[now]]*2==len[now]+len[fail[fail[now]]]) slk[now]=slk[fail[now]];
		else slk[now]=now;
	}
}
void query()
{
	int x,nl;
	x=now;
	//printf("!!! %d %d  %d %d\n",len[6],len[3],fail[6],slk[6]);
	while(x>2)
	{
		if(slk[x]==x) g[slk[x]]=Node(inf,0);
		x=slk[x];
		/*
		if(id==626) 
		{
			printf("P %d %d   %d %d  G %d %d\n",x,len[x],slk[x],len[slk[x]],g[x].w,g[x].x);
			printf("R %d %d\n",g[15].w,g[15].x);
		}
		*/
		nl=len[x];
		g[x]=qmin(g[x],Node(f[id-nl].w,id-nl));
		if((id&1)==0) f[id]=qmin(f[id],Node(g[x].w+1,g[x].x));
		
		x=fail[x];
	}
}
int main()
{
	int i,x;
	scanf("%s",sa+1);
	scanf("%s",sb+1);
	n=strlen(sa+1);m=0;
	for(i=1;i<=n;i++)
	{
		a[++m]=sa[i]-'a';a[++m]=sb[i]-'a';
	}
	tot=2;
	len[1]=-1;fail[2]=1;
	now=1;
	a[0]=-1;
	for(id=1;id<=m;id++)
	{
		f[id]=Node(inf,0);
		ins(a[id]);
		query();
		if((id&1)==0&&a[id-1]==a[id]) f[id]=qmin(f[id],Node(f[id-2].w,id-2));
		//if((id&1)==0) printf("#%d  %d %d\n",id,f[id].w,f[id].x);
	}
	if(f[m].w==inf)
	{
		puts("-1");
		return 0;
	}
	printf("%d\n",f[m].w);
	x=m;
	while(x!=0)
	{
		if(f[x].x!=x-2) printf("%d %d\n",(f[x].x>>1)+1,x>>1);
		x=f[x].x;
	}
	return 0;
}