#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 300005
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
int t,n,a[MAXN],b[MAXN];
int cnt[MAXN];
vector<int> pos[MAXN];
int ps[MAXN];
struct segtree
{
    int mini[4*MAXN];
    void pushup(int k)
    {
        mini[k]=min(mini[k*2],mini[k*2+1]);
    }
    void build(int k,int l,int r)
    {
        if(l==r)
        {
            mini[k]=a[l];
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void modify(int k,int l,int r,int p,int v)
    {
        if(l==r)
        {
            mini[k]=v;
            return;
        }
        int mid=(l+r)/2;
        if(p<=mid) modify(k*2,l,mid,p,v); else modify(k*2+1,mid+1,r,p,v);
        pushup(k);
    }
    int query(int k,int l,int r,int x,int y)
    {
        if(x>r||l>y) return INF;
        if(l>=x&&r<=y) return mini[k];
        int mid=(l+r)/2;
        return min(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        bool f=true;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        for(int i=1;i<=n;i++) pos[i].clear();
        for(int i=1;i<=n;i++) cnt[i]=0;
        for(int i=1;i<=n;i++) pos[a[i]].push_back(i);
        for(int i=1;i<=n;i++)
        {
            cnt[b[i]]++;
            if((int)pos[b[i]].size()<cnt[b[i]])
            {
                f=false;
                break;
            }
            ps[i]=pos[b[i]][cnt[b[i]]-1];
        }
        if(!f) {puts("NO"); continue;}
        seg.build(1,1,n);
        for(int i=1;i<=n;i++)
        {
            int mini=seg.query(1,1,n,1,ps[i]);
            if(mini<b[i])
            {
                f=false;
                break;
            }
            seg.modify(1,1,n,ps[i],INF);
        }
        if(f)puts("YES"); else puts("NO");
    } 
    return 0;
}