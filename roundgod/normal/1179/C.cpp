#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 300005
#define MAXM 1000005
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
int n,m,q,a[MAXN],b[MAXN];
int cnta[MAXM],cntb[MAXM];
struct segtree
{
    int maxi[4*MAXM],pos[4*MAXM];
    int lazy[4*MAXM];
    void pushup(int k)
    {
        if(maxi[k*2+1]>=maxi[k*2])
        {
            pos[k]=pos[k*2+1];
            maxi[k]=maxi[k*2+1];
        }
        else
        {
            pos[k]=pos[k*2];
            maxi[k]=maxi[k*2];
        }
    }
    void pushdown(int k)
    {
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++) 
        {
            lazy[i]+=lazy[k];
            maxi[i]+=lazy[k];
        }
        lazy[k]=0;
    }
    void build(int k,int l,int r)
    {
        lazy[k]=0;
        if(l==r)
        {
            pos[k]=l;
            maxi[k]=cnta[l]-cntb[l];
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int x,int y,int v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y)
        {
            maxi[k]+=v;
            lazy[k]+=v;
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    P query(int k,int l,int r)
    {
        if(l==r) return make_pair(maxi[k],l);
        pushdown(k);
        int mid=(l+r)/2;
        if(maxi[k*2+1]>0) return query(k*2+1,mid+1,r); else return query(k*2,l,mid);
    }
}seg;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        cnta[a[i]]++;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&b[i]);
        cntb[b[i]]++;
    }
    for(int i=1000000;i>=1;i--)
    {
        cnta[i]+=cnta[i+1];
        cntb[i]+=cntb[i+1];
    }
    seg.build(1,1,1000000);
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int type,x,y;
        scanf("%d%d%d",&type,&x,&y);
        if(type==1)
        {
            if(a[x]<=y) seg.update(1,1,1000000,a[x]+1,y,1);
            else seg.update(1,1,1000000,y+1,a[x],-1);
            a[x]=y;
        }
        else
        {
            if(b[x]<=y) seg.update(1,1,1000000,b[x]+1,y,-1);
            else seg.update(1,1,1000000,y+1,b[x],1);
            b[x]=y;
        }
        P p=seg.query(1,1,1000000);
        if(p.F<=0) puts("-1"); else printf("%d\n",p.S);
    }
    return 0;
}