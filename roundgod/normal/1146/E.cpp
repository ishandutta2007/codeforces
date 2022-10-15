#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
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
int n,q;
int a[MAXN],ans[MAXN],isflip[MAXN];
struct segtree
{
    int sum[4*MAXN],lazy[4*MAXN],flp[4*MAXN];
    void pushup(int k)
    {
        ;
    }
    void pushdown(int k)
    {
        if(lazy[k])
        {
            for(int i=k*2;i<=k*2+1;i++) 
            {
                sum[i]=lazy[i]=lazy[k];
            }
            lazy[k]=0; flp[k]=0;
        }
        else if(flp[k])
        {
            for(int i=k*2;i<=k*2+1;i++) 
            {
                sum[i]=-sum[i];
                if(lazy[i]) lazy[i]=-lazy[i]; else flp[i]^=1;
            }
            flp[k]=0;
        }
    }
    void update(int k,int l,int r,int x,int y,int v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y) 
        {
            lazy[k]=v; 
            sum[k]=v;
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    void flip(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y) 
        {
            sum[k]=-sum[k];
            if(lazy[k]) lazy[k]=-lazy[k]; else flp[k]^=1;
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        flip(k*2,l,mid,x,y); flip(k*2+1,mid+1,r,x,y);
        pushup(k);
    }
    int query(int k,int l,int r,int p)
    {
        if(l==r) return sum[k];
        pushdown(k);
        int mid=(l+r)/2;
        if(p<=mid) return query(k*2,l,mid,p); else return query(k*2+1,mid+1,r,p);
    }
}seg1,seg2;
char str[4];
int x;
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    seg2.update(1,1,100000,1,100000,-1);
    for(int i=0;i<q;i++)
    {
        scanf("%s",str);
        scanf("%d",&x);
        if(str[0]=='>')
        {
            if(x>=0) {seg1.update(1,1,100000,x+1,100000,-1);}
            else 
            {
                seg1.update(1,1,100000,-x,100000,-1); 
                seg1.flip(1,1,100000,1,-x-1); seg2.flip(1,1,100000,1,-x-1);
            }
        }
        else 
        {
            if(x<=0) {seg1.update(1,1,100000,-x+1,100000,1);}
            else
            {
                seg1.update(1,1,100000,x,100000,1); 
                seg1.flip(1,1,100000,1,x-1); seg2.flip(1,1,100000,1,x-1);
            }
        }
    }
    for(int i=1;i<=100000;i++) ans[i]=seg1.query(1,1,100000,i),isflip[i]=seg2.query(1,1,100000,i);
    for(int i=1;i<=n;i++) 
    {
        int x=abs(a[i]);
        if(x==0) printf("%d ",x);
        else if(ans[x]!=0) printf("%d ",x*ans[x]);
        else if(isflip[x]==1) printf("%d ",-a[i]); else printf("%d ",a[i]);
    }
    return 0;
}