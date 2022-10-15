#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,a[MAXN];
ll sum[MAXN];
vector<int> v[MAXN];
struct segtree
{
    int lazy[4*MAXN],mini[4*MAXN];
    void add(int k,int v)
    {
        lazy[k]+=v; mini[k]+=v;
    }
    void pushup(int k)
    {
        mini[k]=min(mini[k*2],mini[k*2+1]);
    }
    void pushdown(int k)
    {
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++) add(i,lazy[k]);
        lazy[k]=0;
    }
    void build(int k,int l,int r)
    {
        lazy[k]=0;
        if(l==r)
        {
            mini[k]=l;
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
            add(k,v);
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
}seg;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        a[n+1]=INF;
        for(int i=1;i<=m;i++) v[i].clear();
        seg.build(1,0,n);
        for(int i=1;i<=m;i++)
        {
            int k,x; scanf("%d",&k);
            sum[i]=0;
            for(int j=0;j<k;j++)
            {
                scanf("%d",&x);
                v[i].push_back(x);
                sum[i]+=x;
            }
            int id=lower_bound(a+1,a+n+2,(sum[i]+k-1)/k)-a-1;
            //printf("dec %d %d\n",n-id,n);
            seg.update(1,0,n,n-id,n,-1);
        }
        for(int i=1;i<=m;i++)
        {
            int k=(int)v[i].size();
            int id=lower_bound(a+1,a+n+2,(sum[i]+k-1)/k)-a-1;
            seg.update(1,0,n,n-id,n,1);
            for(auto x:v[i])
            {
                int nid=lower_bound(a+1,a+n+2,(sum[i]-x+k-2)/(k-1))-a-1;
                seg.update(1,0,n,n-nid,n,-1);
                //printf("add %d %d\n",n-nid,n);
                if(seg.mini[1]>=0) printf("1"); else printf("0");
                seg.update(1,0,n,n-nid,n,1);
            }
            seg.update(1,0,n,n-id,n,-1);
        }
        printf("\n");
    }
    return 0;
}