#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back

using namespace std;
const int N=300005;
int n,q,a[N],t[N],siz[N],A[N],tot,l[N],r[N],f[N];
int root,ans[N],id,k,mn,p[N];
struct data{int id,x;} ;
vector <data> vt[N];
int T[N];

void pushup(int x)
{
	t[x]=min(min(t[l[x]],t[r[x]]),a[x]);
	siz[x]=siz[l[x]]+siz[r[x]]+1;
}

void rotate(int x)
{
	int y=f[x],z=f[y];
	if(l[z]==y) l[z]=x;
	if(r[z]==y) r[z]=x;
	f[x]=z,f[y]=x;
	if(l[y]==x) f[l[y]=r[x]]=y,r[x]=y;
	else f[r[y]=l[x]]=y,l[x]=y;
	pushup(y),pushup(x);
}

void splay(int x)
{
	root=x;
	for(; f[x]; rotate(x))
	{
		int y=f[x],z=f[y];
		if(f[y]) rotate((l[z]==y)^(l[y]==x)?x:y);
	}
}

void ins(int &x,int fa)
{
	if(!x) {x=++tot,f[x]=fa,t[x]=a[x]=id,splay(x); return;}
	if(siz[l[x]]<k)
	{
		k-=siz[l[x]]+1;
		mn=min(min(t[l[x]],a[x]),mn);
		ins(r[x],x);
	}
	else ins(l[x],x);
}

void init()
{
	t[0]=n+1;
	rep(i,1,n)
	{
		mn=n+1;
		if(A[i]<=i)
		{
			k=i-A[i],id=i;
			if(tot>=k) ins(root,0),p[i]=mn;
		}
	}
}

void add(int x)
{
	for(int i=x; i; i-=i&-i) ++T[i];
}

int query(int x)
{
	int rt=0;
	for(int i=x; i<=n+1; i+=i&-i) rt+=T[i];
	return rt;
}

void solve()
{
	rep(i,1,q)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		++x,y=n-y;
		vt[x-1].pb((data){-i,x});
		vt[y].pb((data){i,x});
	}
	rep(i,1,n)
	{
		add(p[i]);
		int sz=vt[i].size();
		rep(j,0,sz-1)
		{
			if(vt[i][j].id<0) ans[-vt[i][j].id]-=query(vt[i][j].x);
			else ans[vt[i][j].id]+=query(vt[i][j].x);
		}
	}
	rep(i,1,q) printf("%d\n",ans[i]);
}

int main()
{
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	scanf("%d%d",&n,&q);
	rep(i,1,n) scanf("%d",&A[i]);
	init();
	solve();
	return 0;
}