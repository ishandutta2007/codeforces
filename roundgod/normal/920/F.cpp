#include<bits/stdc++.h>
#define MAXN 300005
#define MAXD 1000005
using namespace std;
typedef long long ll;
struct node
{
	ll l,r,maxx,sum;
}seg[4*MAXN];
ll n,m,a[MAXN],divi[MAXD];
void build(ll k,ll l,ll r)
{
	seg[k].l=l;seg[k].r=r;
	if(l==r)
	{
		seg[k].sum=a[l];
		seg[k].maxx=a[l];
		return;
	}
	ll mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	seg[k].sum=seg[k*2].sum+seg[k*2+1].sum;
	seg[k].maxx=max(seg[k*2].maxx,seg[k*2+1].maxx);
}
void change(ll k,ll l,ll r)
{
	if(seg[k].maxx<=2) return;
	if(seg[k].l>r||seg[k].r<l) return;
	if(seg[k].l==seg[k].r)
	{
		seg[k].sum=divi[seg[k].sum];
		seg[k].maxx=divi[seg[k].maxx];
		return;
	}
	change(k*2,l,r);
	change(k*2+1,l,r);
	seg[k].sum=seg[k*2].sum+seg[k*2+1].sum;
	seg[k].maxx=max(seg[k*2].maxx,seg[k*2+1].maxx);
}
ll query(ll k,ll l,ll r)
{
	if(seg[k].l>r||seg[k].r<l) return 0;
	if(seg[k].l>=l&&seg[k].r<=r) return seg[k].sum;
	return query(k*2,l,r)+query(k*2+1,l,r);
}
int main()
{
	memset(divi,0,sizeof(divi));
	for(ll i=1;i<MAXD;i++)
		for(ll j=i;j<MAXD;j+=i)
			divi[j]++;
	scanf("%I64d%I64d",&n,&m);
	for(ll i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	build(1,1,n);
	for(ll i=0;i<m;i++)
	{
		ll t,x,y;
		scanf("%I64d%I64d%I64d",&t,&x,&y);
		if(t==1) change(1,x,y);
		else printf("%I64d\n",query(1,x,y));
	}
	return 0;
}