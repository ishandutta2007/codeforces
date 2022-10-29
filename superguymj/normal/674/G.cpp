#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)
#define pb push_back

using namespace std;
const int N=150005;
int n,m,P,ql,qr,x,cur[N<<2];

struct data {int id,cnt;} ;

struct seg
{
	vector <data> s;
} t[N<<2],ans;

void add(seg &x,int p,int c)
{
	int sz=x.s.size();
	rep(i,0,sz-1) if(x.s[i].id==p)
	{
		x.s[i].cnt+=c;
		return;
	}
	if(sz<P) {x.s.pb((data){p,c}); return;}
	int mn=c;
	rep(i,0,sz-1) mn=min(mn,x.s[i].cnt);
	c-=mn;
	rep(i,0,sz-1) x.s[i].cnt-=mn;
	if(!c) return;
	rep(i,0,sz-1) if(!x.s[i].cnt)
	{
		x.s[i]=(data){p,c};
		break;
	}
}

seg operator + (seg x,seg y)
{
	int sz=y.s.size();
	rep(i,0,sz-1)
	{
		int p=y.s[i].id,c=y.s[i].cnt;
		add(x,p,c);
	}
	return x;
}

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void build(int l,int r,int rt)
{
	if(l==r)
	{
		t[rt].s.pb((data){getint(),1});
		return;
	}
	build(l,mid,lch),build(mid+1,r,rch);
	t[rt]=t[lch]+t[rch];
}

void turn(int l,int r,int rt,int x)
{
	cur[rt]=x,t[rt].s.clear();
	t[rt].s.pb((data){x,r-l+1});
}

void pushdown(int l,int r,int rt)
{
	if(cur[rt])
	{
		turn(l,mid,lch,cur[rt]);
		turn(mid+1,r,rch,cur[rt]);
		cur[rt]=0;
	}
}

void modify(int l,int r,int rt)
{
	if(ql<=l && r<=qr)
	{
		turn(l,r,rt,x);
		return;
	}
	pushdown(l,r,rt);
	if(ql<=mid) modify(l,mid,lch);
	if(mid<qr) modify(mid+1,r,rch);
	t[rt]=t[lch]+t[rch];
}

void query(int l,int r,int rt)
{
	if(ql<=l && r<=qr)
	{
		ans=ans+t[rt];
		return;
	}
	pushdown(l,r,rt);
	if(ql<=mid) query(l,mid,lch);
	if(mid<qr) query(mid+1,r,rch);
}	

int main()
{
	n=getint(),m=getint(),P=100/getint();
	build(1,n,1);
	rep(i,1,m)
		if(getint()==1)
		{
			ql=getint(),qr=getint(),x=getint();
			modify(1,n,1);
		}
		else
		{
			ql=getint(),qr=getint();
			ans.s.clear();
			query(1,n,1);
			int sz=ans.s.size();
			printf("%d",sz);
			rep(j,0,sz-1) printf(" %d",ans.s[j].id);
			puts("");
		}
	return 0;
}