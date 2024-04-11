#include<bits/stdc++.h>
#define cle(a) memset(a,0,sizeof(a))
#define ls son[rt][0]
#define rs son[rt][1]
using namespace std;
typedef long long ll;
ll rd()
{
	ll rx=0,fx=1;char c=getchar();
	while(c<48||c>57)
	{
		if(c=='-') fx=-1;
		c=getchar();
	}
	while(c>=48&&c<=57)
	{
		rx=rx*10+c-48;
		c=getchar();
	}
	return rx*fx;
}
const ll N=2e5+50,V=2e7+50,W=1e9+1;
ll n,ort;
struct Data{ll al,ar,bl,br;}h[N],p[N];
struct Segment_tree
{
	ll tot;
	ll tag[V],val[V],son[V][2];
	void add(ll &rt,ll l,ll r,ll x,ll y)
	{
		if(!rt) rt=++tot;
		if(l>=x&&r<=y)
		{
			tag[rt]=val[rt]=1;return ;
		}
		ll mid=(l+r)>>1;
		if(mid>=x) add(ls,l,mid,x,y);
		if(mid<y) add(rs,mid+1,r,x,y);
		val[rt]=val[ls]|val[rs];
	}
	ll qry(ll rt,ll l,ll r,ll x,ll y)
	{
		if(l>=x&&r<=y) return val[rt];
		ll mid=(l+r)>>1,ret=0;
		if(mid>=x) ret|=qry(ls,l,mid,x,y);
		if(mid<y) ret|=qry(rs,mid+1,r,x,y);
		ret|=tag[rt];
		return ret;
	}
}sgt;
bool cmp(const Data &a,const Data &b){return a.al<b.al;}
bool cmp2(const Data &a,const Data &b){return a.ar<b.ar;}
bool Solve()
{
	ll i,top=0;
	sgt.tot=0;ort=0;
	cle(sgt.tag);cle(sgt.val);cle(sgt.son);
	for(i=1;i<=n;i++) p[i]=h[i];
	sort(h+1,h+n+1,cmp);
	sort(p+1,p+n+1,cmp2);
	for(i=1;i<=n;i++)
	{
		while(top<n&&p[top+1].ar<h[i].al)
		{
			top++;sgt.add(ort,1,W,p[top].bl,p[top].br);
		}
		if(sgt.qry(ort,1,W,h[i].bl,h[i].br)) 
		{
			//printf("!!!%lld\n",sgt.qry(ort,1,W,h[i].al,h[i].ar));
			return 0;
		}
	}
	return 1;
}
int main()
{
	ll i;
	n=rd();
	for(i=1;i<=n;i++) 
	{
		h[i].al=rd();h[i].ar=rd();h[i].bl=rd();h[i].br=rd();
	}
	if(Solve()==0) {puts("NO");return 0;}
	for(i=1;i<=n;i++) swap(h[i].al,h[i].bl),swap(h[i].ar,h[i].br);
	if(Solve()==0) {puts("NO");return 0;}
	puts("YES");return 0;
}