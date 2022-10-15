#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,m,q,a[MAXN],l[MAXN],r[MAXN],d[MAXN],query[MAXN];
struct node
{
	ll l,r,sum,lazy;
}seg[4*MAXN];
void Lazy(ll k)
{
	ll num=seg[k].lazy;seg[k].lazy=0;
	if(seg[k].l==seg[k].r) return;
	seg[k*2].lazy+=num;seg[k*2].sum+=(seg[k*2].r-seg[k*2].l+1)*num;
	seg[k*2+1].lazy+=num;seg[k*2+1].sum+=(seg[k*2+1].r-seg[k*2+1].l+1)*num;
	return;
}
void build(ll k,ll l,ll r)
{
	seg[k].l=l;seg[k].r=r;seg[k].lazy=0;
	if(l==r) {seg[k].sum=a[l]; return;}
	ll mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	seg[k].sum=seg[k*2].sum+seg[k*2+1].sum;
}
void update(ll k,ll l,ll r,ll x)
{
	if(l>seg[k].r||r<seg[k].l) return;
	if(seg[k].l>=l&&seg[k].r<=r) 
	{
		seg[k].sum+=x;
		seg[k].lazy+=x;
		return;
	}
	if(seg[k].lazy) Lazy(k);
	update(k*2,l,r,x);
	update(k*2+1,l,r,x);
	seg[k].sum=seg[k*2].sum+seg[k*2+1].sum;
}
ll _query(ll k,ll l,ll r)
{
	if(l>seg[k].r||r<seg[k].l) return 0;
	if(seg[k].l>=l&&seg[k].r<=r) return seg[k].sum;
	if(seg[k].lazy) Lazy(k);
	return _query(k*2,l,r)+_query(k*2+1,l,r);
}
int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&q);
	for(ll i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	memset(query,0,sizeof(query));
	for(ll i=1;i<=m;i++)
		scanf("%I64d%I64d%I64d",&l[i],&r[i],&d[i]);
	for(ll i=1;i<=q;i++)
	{
		ll x,y;
		scanf("%I64d%I64d",&x,&y);
		query[x]++;
		query[y+1]--;
	}
	for(ll i=1;i<=m;i++)
		query[i]+=query[i-1];
	build(1,1,n);
	for(ll i=1;i<=m;i++)
		if(query[i]) update(1,l[i],r[i],d[i]*query[i]);
	for(ll i=1;i<=n;i++)
		printf("%I64d ",_query(1,i,i));
	return 0;
}