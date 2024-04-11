#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=500005;
bool ans[N];
int n,m,x,y,p,u[N],v[N],c[N],q,k,tot,top,f[N];
struct data{int id,x;} dat[N],st[20000000];
struct edge{int u,v,c;} e[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

bool cmp_edge(edge a,edge b)
{
	return a.c<b.c;
}

bool cmp_data(data a,data b)
{
	return c[a.x]==c[b.x]?a.id<b.id:c[a.x]<c[b.x];
}

int getfa(int x)
{
	return x==f[x]?x:(st[++top]=(data){x,f[x]},f[x]=getfa(f[x]));
}

int main()
{
	n=getint(),m=getint();
	rep(i,1,m) u[i]=getint(),v[i]=getint(),c[i]=getint(),e[i]=(edge){u[i],v[i],c[i]};
	sort(e+1,e+1+m,cmp_edge);
	q=getint();
	rep(i,1,q)
	{
		k=getint();
		while(k--) dat[++tot]=(data){i,getint()};
	}
	sort(dat+1,dat+1+tot,cmp_data);
	rep(i,1,n) f[i]=i;
	for(int i=1,j=1,l,r; i<=tot; i=j+1,j=i)
	{
		while(j+1<=tot && c[dat[j+1].x]==c[dat[i].x]) ++j;
		while(p+1<=m && e[p+1].c<c[dat[i].x])
		{
			++p,x=getfa(e[p].u),y=getfa(e[p].v);
			if(x!=y) f[x]=y;
		}
		for(int l=i,r=i; l<=j; l=r+1,r=l)
		{
			for(top=0;	r+1<=j && dat[r+1].id==dat[l].id; ++r);
			if(ans[dat[l].id]) continue;
			rep(k,l,r)
			{
				x=getfa(u[dat[k].x]),y=getfa(v[dat[k].x]);
				if(x==y) {ans[dat[k].id]=1; break;}
				else st[++top]=(data){x,f[x]},f[x]=y;
			}
			repd(k,top,1) f[st[k].id]=st[k].x;
		}
	}
	rep(i,1,q) ans[i]?puts("NO"):puts("YES");
	return 0;
}