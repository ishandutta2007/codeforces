#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
map<int,int> mp;
struct segtree
{
    int sum[4*MAXN],occ[4*MAXN];
    void pushup(int k)
    {
        occ[k]=occ[k*2]+occ[k*2+1];
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    void build(int k,int l,int r)
    {
        sum[k]=occ[k]=0;
        if(l==r) return;
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
    }
    void update(int k,int l,int r,int pos,int v)
    {
        if(l==r) {occ[k]+=v; sum[k]+=v*l; return;}
        int mid=(l+r)/2;
        if(pos<=mid) update(k*2,l,mid,pos,v); else update(k*2+1,mid+1,r,pos,v);
        pushup(k);
    }
    int query(int k,int l,int r,int num)
    {
        if(l==r) return max(0,occ[k]-num/l);
        int mid=(l+r)/2;
        if(sum[k*2]>=num) return query(k*2,l,mid,num)+occ[k*2+1]; else return query(k*2+1,mid+1,r,num-sum[k*2]);
    }
}seg;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        mp.clear();
        seg.build(1,1,n);
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);
            mp[a[i]]++;
        }
        for(auto p:mp) seg.update(1,1,n,p.S,1);
        int ans=seg.query(1,1,n,k),need=0;
        for(int i=0;i<=n-1;i++)
        {
            if(!mp[i]) need++; else seg.update(1,1,n,mp[i],-1);
            if(need>k) break;
            ans=min(ans,seg.query(1,1,n,k));
        }
        printf("%d\n",ans);
    }
    return 0;
}