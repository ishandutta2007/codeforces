#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back

using namespace std;
const int N=100005,M=4000005,D=30;
int n,q,ql,qr,a[N],root[N],tot,l[M],r[M],x,ans;
struct seg{int siz,x;} t[M];
vector <int> tmp;

void build(int &rt,int lst,int d)
{
	if(!rt) rt=++tot,l[rt]=r[rt]=0;
	if(d==-1)
	{
		t[rt]=(seg){1+t[lst].siz,x};
		return;
	}
	if(x&(1<<d)) build(r[rt],r[lst],d-1),l[rt]=l[lst];
	else build(l[rt],l[lst],d-1),r[rt]=r[lst];
	t[rt].siz=t[l[rt]].siz+t[r[rt]].siz;
	t[rt].x=x;
}

void query(int rt,int lst,int d)
{
	if(d==-1) return;
	int sz=tmp.size(),x=t[l[rt]].siz-t[l[lst]].siz;
	rep(i,0,sz-1) if(!(tmp[i]&(1<<d))) ++x;
	if(x>1)
	{
		vector <int> a;
		rep(i,0,sz-1) if(!(tmp[i]&(1<<d))) a.pb(tmp[i]);
		tmp=a;
		query(l[rt],l[lst],d-1);
	}
	else
	{
		if(t[l[rt]].siz-t[l[lst]].siz) tmp.pb(t[l[rt]].x);
		ans|=1<<d,query(r[rt],r[lst],d-1);
	}
}

void solve()
{
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	tot=0;
	rep(i,1,n) root[i]=0,x=a[i],build(root[i],root[i-1],D);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&ql,&qr),ans=0;
		tmp.clear();
		query(root[qr],root[ql-1],D);
		printf("%d\n",ans);
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}