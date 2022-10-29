#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)

using namespace std;
const int N=200005;
struct seg
{
	int l,r,ans;
	
	void set(int x)
	{
		l=r=x,ans=1;
	}
} t[N*20];
int n,m,tot,x,y,root[N],ls[N*20],rs[N*20],ans;

seg operator + (seg x,seg y)
{
	seg rt;
	rt.l=x.l,rt.r=y.r;
	rt.ans=x.ans+y.ans;
	if(x.r+1==y.l) --rt.ans;
	return rt;
}

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;	
	return x;
}

void pushup(int rt)
{
	if(!ls[rt]) t[rt]=t[rs[rt]];
	if(!rs[rt]) t[rt]=t[ls[rt]];
	t[rt]=t[ls[rt]]+t[rs[rt]];
}

void insert(int l,int r,int &rt)
{
	if(!rt) rt=++tot;
	if(l==r) {t[rt].set(x); return;}
	if(x<=mid) insert(l,mid,ls[rt]);
	else insert(mid+1,r,rs[rt]);
	pushup(rt);
}

void merge(int l,int r,int &x,int y)
{
	if(!y) return;
	if(!x) {x=y; return;}
	merge(l,mid,ls[x],ls[y]);
	merge(mid+1,r,rs[x],rs[y]);
	pushup(x);
}

int main()
{
	n=getint(),m=getint();
	rep(i,1,n) x=i,insert(1,n,root[getint()]);
	rep(i,1,m) ans+=t[root[i]].ans;
	printf("%d\n",ans-1);
	rep(i,1,m-1)
	{
		x=getint(),y=getint();
		ans-=t[root[x]].ans+t[root[y]].ans;
		merge(1,n,root[x],root[y]);
		ans+=t[root[x]].ans;
		printf("%d\n",ans-1);
	}
	return 0;
}