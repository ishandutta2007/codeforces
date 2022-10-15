#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int cnt[MAXN];
vector<int> pos[MAXN];
int dp[MAXN];
int maxi[MAXN];
struct segtee
{
	int maxi[4*MAXN];
	void pushup(int k)
	{
		maxi[k]=max(maxi[k*2],maxi[k*2+1]);
	}
	void build(int k,int l,int r)
	{
		maxi[k]=-INF;
		if(l==r) return;
		int mid=(l+r)/2;
		build(k*2,l,mid); build(k*2+1,mid+1,r);
	}
	void update(int k,int l,int r,int pos,int v)
	{
		if(l==r) {maxi[k]=v; return;}
		int mid=(l+r)/2;
		if(pos<=mid) update(k*2,l,mid,pos,v); else update(k*2+1,mid+1,r,pos,v);
		pushup(k);
	}
	int query(int k,int l,int r,int x,int y)
	{
		if(l>y||x>r) return -INF;
		if(l>=x&&r<=y) return maxi[k];
		int mid=(l+r)/2;
		return max(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
	}
}seg;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		pos[a[i]].push_back(i);
	}
	seg.build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		if(i!=pos[a[i]][0]) dp[i]=max(dp[i],seg.query(1,1,n,pos[a[i]][0],i-1)+i-1);
		seg.update(1,1,n,i,dp[i]-i);
	}	
	printf("%d\n",dp[n]);
	return 0;
}