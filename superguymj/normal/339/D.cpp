#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)

using namespace std;
const int N=140000;
int n,m,x,y,t[N<<2];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void build(int l,int r,int rt,int dep)
{
	if(l==r)
	{
		t[rt]=getint();
		return;
	}
	build(l,mid,lch,dep-1);
	build(mid+1,r,rch,dep-1);
	t[rt]=dep&1?(t[lch]|t[rch]):(t[lch]^t[rch]);
}

void modify(int l,int r,int rt,int dep)
{
	if(l==r)
	{
		t[rt]=y;
		return;
	}
	if(x<=mid) modify(l,mid,lch,dep-1);
	else modify(mid+1,r,rch,dep-1);
	t[rt]=dep&1?(t[lch]|t[rch]):(t[lch]^t[rch]);
}

int main()
{
	n=getint(),m=getint();
	build(1,1<<n,1,n);
	while(m--)
	{
		x=getint(),y=getint();
		modify(1,1<<n,1,n),printf("%d\n",t[1]);
	}
	return 0;
}