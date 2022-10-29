#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)

using namespace std;
const int hx[]={0,0,1,-1};
const int hy[]={1,-1,0,0};
const int N=200005,M=1005;
int n,m,p,tot,mp[M][M];
typedef long long LL;
LL ans;
struct data{int x,y;} dat[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

struct lint_cut_tree
{
	bool cur[N];
	int l[N],r[N],f[N];

	bool isroot(int x){return l[f[x]]!=x && r[f[x]]!=x;}

	int pushdown(int x)
	{
		if(cur[x]) swap(l[x],r[x]),cur[l[x]]^=1,cur[r[x]]^=1,cur[x]=0;
	}

	void dfs(int x)
	{
		if(!isroot(x)) dfs(f[x]);
		pushdown(x);
	}

	void rotate(int x)
	{
		int y=f[x],z=f[y];
		if(l[z]==y) l[z]=x;
		if(r[z]==y) r[z]=x;
		f[x]=z,f[y]=x;
		if(l[y]==x) f[l[y]=r[x]]=y,r[x]=y;
		else f[r[y]=l[x]]=y,l[x]=y;
	}

	void splay(int x)
	{
		for(dfs(x); !isroot(x); rotate(x))
		{
			int y=f[x],z=f[y];
			if(!isroot(y)) rotate((l[y]==x)^(l[z]==y)?x:y);
		}
	}

	void access(int x)
	{
		for(int t=0; x; t=x,x=f[x])
			splay(x),r[x]=t;
	}

	int rever(int x)
	{
		access(x),splay(x),cur[x]^=1;
	}

	int find(int x)
	{
		if(pushdown(x),!l[x]) return x;
		return find(l[x]);
	}

	void link(int x,int y)
	{
		rever(x),rever(y),f[y]=x;
	}

	void cut(int x,int y)
	{
		rever(x),access(y),splay(y),l[y]=f[x]=0;
	}

	bool check(int x,int y)
	{
		return rever(x),access(y),splay(y),find(y)==x;
	}
} t1;

bool link(int x,int p)
{
	int i=dat[x].x,j=dat[x].y;
	rep(k,0,3)
	{
		int _i=i+hx[k];
		int _j=j+hy[k];
		int y=mp[_i][_j];
		if(_i && _j && _i<=n && _j<=m && y>=p && y<=x)
		{
			if(t1.check(y,x))
			{
				rep(l,0,k-1)
				{
					_i=i+hx[l];
					_j=j+hy[l];
					y=mp[_i][_j];
					if(_i && _j && _i<=n && _j<=m && y>=p && y<=x) t1.cut(y,x);
				}
				return 0;
			}
			else t1.link(y,x);
		}
	}
	return 1;
}

void cut(int x,int p)
{
	int i=dat[x].x,j=dat[x].y;
	rep(k,0,3)
	{
		int _i=i+hx[k];
		int _j=j+hy[k];
		int y=mp[_i][_j];
		if(_i && _j && _i<=n && _j<=m && y>=x && y<=p) t1.cut(y,x);
	}
}

struct seg{int mn,x;} ;

seg operator + (seg x,seg y)
{
	seg rt=(seg){min(x.mn,y.mn),0};
	if(x.mn==rt.mn) rt.x+=x.x;
	if(y.mn==rt.mn) rt.x+=y.x;
	return rt;
}	

struct segment_tree
{
	seg t[N<<2];
	int cur[N<<2],x,y,ql,qr;
	
	void build(int l,int r,int rt)
	{
		t[rt]=(seg){0,r-l+1};
		if(l==r) return;
		build(l,mid,lch),build(mid+1,r,rch);
	}

	int query(int _ql,int _qr)
	{
		return ql=_ql,qr=_qr,query(1,tot,1).x;
	}

	seg query(int l,int r,int rt)
	{
		if(ql<=l && r<=qr) return t[rt];
		pushdown(rt);
		if(qr<=mid) return query(l,mid,lch);
		if(mid<ql) return query(mid+1,r,rch);
		return query(l,mid,lch)+query(mid+1,r,rch);
	}

	void ins(int _x,int _y)
	{
		x=_x,y=_y,ins(1,tot,1);
	}

	void pushdown(int rt)
	{
		if(cur[rt]) turn(lch,cur[rt]),turn(rch,cur[rt]),cur[rt]=0;
	}

	void turn(int rt,int x)
	{
		cur[rt]+=x,t[rt].mn+=x;
	}
	
	void ins(int l,int r,int rt)
	{
		if(r<=x) {turn(rt,y); return;}
		pushdown(rt);
		ins(l,mid,lch);
		if(mid<x) ins(mid+1,r,rch);
		t[rt]=t[lch]+t[rch];
	}
} t2;

void ins(int x)
{
	int i=dat[x].x,j=dat[x].y;
	rep(k,0,3)
	{
		int _i=i+hx[k];
		int _j=j+hy[k];
		if(_i && _j && _i<=n && _j<=m && mp[_i][_j]<=x)  t2.ins(mp[_i][_j],-1);
	}
}

int main()
{
	n=getint(),m=getint(),tot=n*m;
	rep(i,1,n) rep(j,1,m) dat[mp[i][j]=getint()]=(data){i,j};
	t2.build(1,tot,1),p=1;
	rep(i,1,n*m)
	{
		for(t2.ins(i,1),ins(i); !link(i,p); cut(p++,i-1));
		ans+=t2.query(p,i);
	}
	printf("%lld\n",ans);
	return 0;
}