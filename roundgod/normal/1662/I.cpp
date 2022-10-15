#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 200005
#define INF 2000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,m;
int p[MAXN],x[MAXN];
int pos[MAXN];
int l[MAXN],r[MAXN];
vector<int> dis;
struct segtree
{
    ll maxi[8*MAXN],lazy[8*MAXN];
    void pushup(int k)
    {
        maxi[k]=max(maxi[k*2],maxi[k*2+1]);
    }
    void add(int k,ll v)
    {
        maxi[k]+=v; lazy[k]+=v;
    }
    void pushdown(int k)
    {
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++)
        {
            add(i,lazy[k]);
        }
        lazy[k]=0;
    }
    void update(int k,int l,int r,int x,int y,ll v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y) {add(k,v); return;}
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    ll query()
    {
        return maxi[1];
    }
}seg;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n;i++) pos[i]=pos[i-1]+100;
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    for(int i=1;i<=m;i++) scanf("%d",&x[i]);
    sort(x+1,x+m+1);
    for(int i=1;i<=n;i++)
    {
        int dist=0;
        if(x[m]<=pos[i]) dist=pos[i]-x[m];
        else 
        {
            int id=lower_bound(x+1,x+m+1,pos[i])-x;
            dist=x[id]-pos[i];
            if(id>1) dist=min(dist,pos[i]-x[id-1]);
        }
        l[i]=2*pos[i]-2*dist+1; r[i]=2*pos[i]+2*dist-1;
        //printf("%d %d\n",l[i],r[i]);
        dis.push_back(l[i]); dis.push_back(r[i]);
    }
    sort(dis.begin(),dis.end());
    dis.erase(unique(dis.begin(),dis.end()),dis.end());
    int sz=(int)dis.size();
    for(int i=1;i<=n;i++)
    {
        l[i]=lower_bound(dis.begin(),dis.end(),l[i])-dis.begin()+1;
        r[i]=lower_bound(dis.begin(),dis.end(),r[i])-dis.begin()+1;
        seg.update(1,1,sz,l[i],r[i],p[i]);
    }
    printf("%lld\n",seg.query());
    return 0;
}