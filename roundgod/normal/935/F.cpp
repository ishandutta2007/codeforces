#include<bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define INF 1000000000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
struct node
{
	ll l,r,b,c,d,e,f;
}seg[4*MAXN];
struct res
{
	ll d,e,f;
};
ll n,sum,q,a[MAXN],id[MAXN];
void build(ll k,ll l,ll r)
{
	seg[k].l=l;seg[k].r=r;
	if(seg[k].l==seg[k].r)
	{
		id[l]=k;
		if(l==1||r==n)
		{
			seg[k].d=seg[k].e=seg[k].f=0;
			return;
		}
		seg[k].b=a[l]-a[l-1];
		seg[k].c=a[l]-a[l+1];
		ll b=seg[k].b,c=seg[k].c;
		ll cst=max(-b,b)+max(-c,c);
		seg[k].d=-b-c-cst;
		seg[k].e=max(b-c,c-b)-cst;
		seg[k].f=b+c-cst;
		return;
	}
	ll mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	seg[k].d=max(seg[k*2].d,seg[k*2+1].d);
	seg[k].e=max(seg[k*2].e,seg[k*2+1].e);
	seg[k].f=max(seg[k*2].f,seg[k*2+1].f);
}
res query(ll k,ll l,ll r,ll x)
{
	if(seg[k].r<l||seg[k].l>r)
	{
		return (res){-INF,-INF,-INF};
	}
	else if(seg[k].l>=l&&seg[k].r<=r)
	{
		return (res){-2*x+seg[k].d,seg[k].e,2*x+seg[k].f};
	}
	res lres=query(k*2,l,r,x);
	res rres=query(k*2+1,l,r,x);
	return (res){max(lres.d,rres.d),max(lres.e,rres.e),max(lres.f,rres.f)};
}
void modify(ll k,ll x,ll type)
{
	if(type==1) {sum-=max(seg[k].b,-seg[k].b); seg[k].b+=x; sum+=max(seg[k].b,-seg[k].b);}
	if(type==2) seg[k].b-=x; 
	if(type==3) {sum-=max(seg[k].c,-seg[k].c); seg[k].c+=x; sum+=max(seg[k].c,-seg[k].c);}
	if(type==4) seg[k].c-=x; 
	ll b=seg[k].b,c=seg[k].c;
	ll cst=max(-b,b)+max(-c,c);
	seg[k].d=-b-c-cst;
	seg[k].e=max(b-c,c-b)-cst;
	seg[k].f=b+c-cst;
	while(k>1)
	{
		k=k/2;
		seg[k].d=max(seg[k*2].d,seg[k*2+1].d);
		seg[k].e=max(seg[k*2].e,seg[k*2+1].e);
		seg[k].f=max(seg[k*2].f,seg[k*2+1].f);
	}
}
int main()
{
	scanf("%I64d",&n);
	sum=0;
	for(ll i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		if(i!=1) sum+=max(a[i]-a[i-1],a[i-1]-a[i]);
	}
	build(1,1,n);
	scanf("%I64d",&q);
	for(ll i=1;i<=q;i++)
	{
		ll type,l,r,x;
		scanf("%I64d%I64d%I64d%I64d",&type,&l,&r,&x);
		if(type==1)
		{
			res ans=query(1,l,r,x);
			printf("%I64d\n",sum+max(max(ans.d,ans.e),ans.f));
		}
		else
		{
			modify(id[l],x,1);
			modify(id[r+1],x,2);
			modify(id[r],x,3);
			modify(id[l-1],x,4);
			//printf("%I64d\n",sum);
		}
	}
	return 0;
}