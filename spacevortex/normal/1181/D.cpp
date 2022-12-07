#include<bits/stdc++.h>
#define ls (rt<<1)
#define rs ((rt<<1)|1)
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
const ll N=2e6+50;
ll n,m,Q,top,pos,val;
ll P[N],pl[N],qans[N],S[N];
struct Query
{
	ll id,tim;
}q[N];
bool cmp(const ll &a,const ll &b)
{
	return P[a]<P[b];
}
bool cmp2(const Query &a,const Query &b)
{
	return a.tim<b.tim;
}
struct Stree
{
	ll siz[N];
	void mup(ll rt)
	{
		siz[rt]=siz[ls]+siz[rs];
	}
	void add(ll rt,ll l,ll r,ll x)
	{
		if(l==r) 
		{
			siz[rt]++;return ;
		}
		ll mid=(l+r)>>1;
		if(mid>=x) add(ls,l,mid,x);
		else add(rs,mid+1,r,x);
		mup(rt);
	}
	ll query(ll rt,ll l,ll r,ll K)
	{
		if(l==r) return l;
		ll mid=(l+r)>>1;
		if(siz[ls]>=K) return query(ls,l,mid,K);
		else return query(rs,mid+1,r,K-siz[ls]);
	}
}s;
void update(ll t)
{
	ll cs;
	
	if(t<=top-pos)
	{
		pos+=t;
		if(pos==top&&t>0) val++;
		return ;
	}
	if(pos!=top) val++;
	t-=top-pos;
	ll zcs=0;
	
	while(top<n&&(P[pl[top+1]]-val)*top<t) 
	{
		
		//printf("upd%d %d\n",t,val);
		t-=(P[pl[top+1]]-val)*top;
		val=P[pl[top+1]];
		while(top<n&&P[pl[top+1]]==val)
		{
		
			top++;s.add(1,1,n,pl[top]);
		}
		
	}
	cs=t/top;
	val+=cs;
	pos=(t-1)%top+1;
}
int main()
{
	//freopen("t.in","r",stdin);
	//freopen("t.out","w",stdout);
	ll i,j,x,las;
	m=rd();n=rd();Q=rd();
	for(i=1;i<=m;i++) S[i]=rd(),P[S[i]]++;
	for(i=1;i<=n;i++) pl[i]=i;
	sort(pl+1,pl+n+1,cmp);
	top=1;val=P[pl[1]];
	while(top<n&&P[pl[top+1]]==P[pl[top]]) top++;
	pos=top;
	for(i=1;i<=top;i++) s.add(1,1,n,pl[i]);
	for(i=1;i<=Q;i++) q[i].id=i,q[i].tim=rd();
	sort(q+1,q+Q+1,cmp2);
	las=m;
	for(i=1;i<=Q;i++)
	{
		if(q[i].tim<=m)
		{
			qans[q[i].id]=S[q[i].tim];
			continue;
		}
		update(q[i].tim-las);
		qans[q[i].id]=s.query(1,1,n,pos);
		las=q[i].tim;
		
	}
	for(i=1;i<=Q;i++) printf("%I64d\n",qans[i]);
	return 0;
}