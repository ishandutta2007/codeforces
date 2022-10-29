#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)

using namespace std;
const int N=100005;
int n,m,mx,ans,tot,u,v,w,ql,qr,t[N*20],ls[N*20],rs[N*20],root[N];

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

void insert(int l,int r,int &rt,int x,int y)
{
	if(!rt) rt=++tot;
	if(l==r)
	{
		t[rt]=max(t[rt],y);
		return;
	}
	if(x<=mid) insert(l,mid,ls[rt],x,y);
	else insert(mid+1,r,rs[rt],x,y);
	t[rt]=max(t[ls[rt]],t[rs[rt]]);
}

int query(int l,int r,int rt)
{
	if(ql>qr) return 0;
	if(!rt) return 0;
	if(ql<=l && r<=qr) return t[rt];
	if(qr<=mid) return query(l,mid,ls[rt]);
	if(mid<ql) return query(mid+1,r,rs[rt]);
	return max(query(l,mid,ls[rt]),query(mid+1,r,rs[rt]));
}

int main()
{
	n=getint(),m=getint();
	rep(i,1,m)
	{
		u=getint(),v=getint(),w=getint();
		ql=0,qr=w-1,mx=query(0,100000,root[u])+1;
		insert(0,100000,root[v],w,mx),ans=max(ans,mx);
	}
	printf("%d\n",ans);
	return 0;
}