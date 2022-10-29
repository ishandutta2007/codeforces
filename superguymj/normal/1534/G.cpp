#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=800005;
int n,l[N<<1],r[N<<1],siz[N<<1];
int root,cur[N<<1],key[N<<1],tot,k;
typedef long long LL;
LL ans,seed;
struct data{int x,y;} dat[N];
struct seg{int siz,val;} t[N<<1],y;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

bool cmp(data a,data b)
{
	return a.x+a.y<b.x+b.y;
}

int ran()
{
	return seed=(seed^998244353)*1000000007ll%1000000009;
}

void pushup(int x)
{
	siz[x]=siz[l[x]]+siz[r[x]]+t[x].siz;
}

void rotate(int &x,int tp)
{
	int y=tp?r[x]:l[x];
	if(tp) r[x]=l[y],l[y]=x;
	else l[x]=r[y],r[y]=x;
	pushup(x),pushup(y),x=y;
}

void turn(int x,int y)
{
	if(x) cur[x]+=y,t[x].val+=y;
}

void pushdown(int x)
{
	if(cur[x])
	{
		turn(l[x],cur[x]);
		turn(r[x],cur[x]);
		cur[x]=0;
	}
}

void ins(int &x)
{
	if(!x)
	{
		x=++tot,t[x]=y;
		key[x]=ran(),siz[x]=t[x].siz;
		return;
	}
	pushdown(x);
	if(t[x].val==y.val)
	{
		t[x].siz+=y.siz,pushup(x);
		return;
	}
	if(t[x].val>y.val)
	{
		ins(l[x]);
		if(key[l[x]]>key[x]) rotate(x,0);
		else pushup(x);
	}
	else
	{
		ins(r[x]);
		if(key[r[x]]>key[x]) rotate(x,1);
		else pushup(x);
	}
}

void add(int &x)
{
	if(!x) return;
	pushdown(x);
	if(siz[l[x]]>=k)
	{
		++t[x].val,turn(r[x],1);
		add(l[x]);
		if(key[l[x]]>key[x]) rotate(x,0);
		else pushup(x);
	}
	else if(siz[l[x]]+t[x].siz>=k)
	{
		turn(l[x],-1),turn(r[x],1),--t[x].val,k=t[x].siz-(k-siz[l[x]]);
		if(k) t[x].siz-=k,y=(seg){k,t[x].val+2},ins(x);
		if(key[l[x]]>key[x]) rotate(x,0);
		else pushup(x);
	}
	else
	{
		--t[x].val,turn(l[x],-1);
		k-=siz[l[x]]+t[x].siz,add(r[x]);
		if(key[r[x]]>key[x]) rotate(x,1);
		else pushup(x);
	}
}

void calc(int x)
{
	if(!x) return;
	pushdown(x);
	if(t[x].val<0) ans+=(LL)t[x].siz*t[x].val;
	calc(l[x]),calc(r[x]);
}

int main()
{
	n=getint();
	rep(i,1,n) dat[i].x=getint(),dat[i].y=getint();
	sort(dat+1,dat+1+n,cmp);
	rep(i,1,n)
	{
		if(y.siz=dat[i].x+dat[i].y-dat[i-1].x-dat[i-1].y) y.val=0,ins(root);
		if(root) ans+=dat[i].x,k=dat[i].x,add(root);
	}
	calc(root);
	printf("%lld\n",ans);
	return 0;
}