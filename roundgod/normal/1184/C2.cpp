#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 300005
#define MAXM 4000005
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
int n,R;
const int shift=2000000;
struct segtree
{
    int maxi[4*MAXM],lazy[4*MAXM];
    void pushup(int k)
    {
        maxi[k]=max(maxi[k*2],maxi[k*2+1]);
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
    void update(int k,int l,int r,int x,int y,int v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y)
        {
            lazy[k]+=v;
            maxi[k]+=v;
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    int query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return maxi[k];
        pushdown(k);
        int mid=(l+r)/2;
        return max(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg;
vector<P> v;
int main()
{
    scanf("%d%d",&n,&R);
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v.push_back(P(x-y,x+y));
    }
    sort(v.begin(),v.end());
    int l=0,r=0,ans=0;
    while(r<n)
    {
        int x=v[r].F,y=v[r].S;
        seg.update(1,1,4000001,y+shift,min(4000001,y+shift+2*R),1);
        while(v[l].F+2*R<v[r].F)
        {
            seg.update(1,1,4000001,v[l].S+shift,min(4000001,v[l].S+shift+2*R),-1);
            l++;
        }
        r++;
        ans=max(ans,seg.query(1,1,4000001,1,4000001));
    }
    printf("%d\n",ans);
    return 0;
}