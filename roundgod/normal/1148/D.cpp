#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 600005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,k,a[MAXN];
int dp1[MAXN],last1[MAXN],dp2[MAXN],last2[MAXN],save[MAXN];
struct node
{
    int x,y;
    int id;
};
vector<node> v1,v2;
bool cmp1(node p,node q)
{
    return p.x<q.x;
}
bool cmp2(node p,node q)
{
    return p.x>q.x;
}
int bit[MAXN+1];
struct segtree
{
    P maxi[4*MAXN];
    void pushup(int k)
    {
        maxi[k]=max(maxi[k*2],maxi[k*2+1]);
    }
    void build(int k,int l,int r)
    {
        maxi[k]=P(0,l);
        if(l==r) return;
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
    }
    void update(int k,int l,int r,int p,int v)
    {
        if(l==r) {maxi[k]=P(v,l); return;}
        int mid=(l+r)/2;
        if(p<=mid) update(k*2,l,mid,p,v); else update(k*2+1,mid+1,r,p,v);
        pushup(k);
    }
    P query(int k,int l,int r,int x,int y)
    {
        if(x>r||l>y) return P(-INF,0);
        if(l>=x&&r<=y) return maxi[k];
        int mid=(l+r)/2;
        return max(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        node nn=(node){x,y,i};
        if(x<y) v1.push_back(nn); else v2.push_back(nn); 
    }
    sort(v1.begin(),v1.end(),cmp2);
    sort(v2.begin(),v2.end(),cmp1);
    int ans=0,mark=-1,pp=-1;
    seg.build(1,1,2*n);
    memset(save,-1,sizeof(save));
    for(int i=0;i<(int)v1.size();i++)
    {
        P p=seg.query(1,1,2*n,v1[i].x+1,2*n);
        dp1[i]=1+p.F;
        last1[i]=save[p.S];
        seg.update(1,1,2*n,v1[i].y,dp1[i]);
        save[v1[i].y]=i;
        if(dp1[i]>ans)
        {
            mark=1;
            pp=i;
            ans=dp1[i];
        }
    }
    seg.build(1,1,2*n);
    for(int i=0;i<(int)v2.size();i++)
    {
        P p=seg.query(1,1,2*n,1,v2[i].x-1);
        dp2[i]=1+p.F;
        last2[i]=save[p.S];
        seg.update(1,1,2*n,v2[i].y,dp2[i]);
        save[v2[i].y]=i;
        if(dp2[i]>ans)
        {
            mark=2;
            pp=i;
            ans=dp2[i];
        }
    }
    printf("%d\n",ans);
    if(mark==1)
    {
         vector<int> ppos;
         while(pp!=-1)
         {
             ppos.push_back(v1[pp].id);
             pp=last1[pp];
         }
         reverse(ppos.begin(),ppos.end());
         for(auto x:ppos) printf("%d ",x+1);
    }
    else
    {
         vector<int> ppos;
         while(pp!=-1)
         {
             ppos.push_back(v2[pp].id);
             pp=last2[pp];
         }
         reverse(ppos.begin(),ppos.end());
         for(auto x:ppos) printf("%d ",x+1);
    }
    return 0;
}