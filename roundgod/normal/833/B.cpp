#include<bits/stdc++.h>
#define MAXN 35005
#define MAXK 55
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
struct node
{
	int l,r,res,lazy;
}seg[4*MAXN];
void Lazy(int k)
{
	if(seg[k].l==seg[k].r) return;
	int num=seg[k].lazy;
	seg[k].lazy=0;
	seg[k*2].lazy+=num;
	seg[k*2].res+=num;
	seg[k*2+1].lazy+=num;
	seg[k*2+1].res+=num;
	return;
}
void build(int k,int l,int r)
{
	seg[k].l=l;seg[k].r=r;seg[k].res=seg[k].lazy=0;
	if(l==r) return;
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
}
void update(int k,int l,int r,int x)
{
	if(seg[k].l>r||seg[k].r<l) return;
	if(seg[k].l>=l&&seg[k].r<=r) 
	{
		seg[k].res+=x;
		seg[k].lazy+=x;
		return;
	}
	if(seg[k].lazy) Lazy(k);
	update(k*2,l,r,x);
	update(k*2+1,l,r,x);
	seg[k].res=max(seg[k*2].res,seg[k*2+1].res);
}
int query(int k,int l,int r)
{
	if(seg[k].l>r||seg[k].r<l) return -INF;
	if(seg[k].l>=l&&seg[k].r<=r) return seg[k].res;
	if(seg[k].lazy) Lazy(k);
	return max(query(k*2,l,r),query(k*2+1,l,r));
}
int last[MAXK],chuochuo[MAXN],dp[MAXK][MAXN];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(last,0,sizeof(last));
	for(int i=1;i<=n;i++)
	{
		chuochuo[i]=last[a[i]];
		last[a[i]]=i;
	}
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=k;i++)
	{
		build(1,1,n);
		for(int j=1;j<=n;j++)
		{
			update(1,chuochuo[j]+1,j,1);
			dp[i][j]=query(1,1,j);
			update(1,j+1,j+1,dp[i-1][j]);
		}
	}
	printf("%d\n",dp[k][n]);
	return 0;
}