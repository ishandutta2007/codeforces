#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first 
#define S second 
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
struct segtree
{
    int mini[4*MAXN],lazy[4*MAXN];
    void pushup(int k)
    {
        mini[k]=min(mini[k*2],mini[k*2+1]);
    }
    void add(int k,int v)
    {
        mini[k]+=v;
        lazy[k]+=v;
    }
    void build(int k,int l,int r)
    {
        mini[k]=lazy[k]=0;
        if(l==r) return;
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
    }
    void pushdown(int k)
    {
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++) add(i,lazy[k]);
        lazy[k]=0;
    }
    void update(int k,int l,int r,int x,int y,int v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y) {add(k,v); return;}
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
}seg;
vector<pair<int,P> > v; 
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        int l,r,w;
        scanf("%d%d%d",&l,&r,&w);
        v.push_back(make_pair(w,P(l,r-1)));
    }
    sort(v.begin(),v.end());
    seg.build(1,1,m-1);
    int l=0,r=-1,ans=INF;
    while(l<(int)v.size())
    {
        while(r+1<(int)v.size()&&seg.mini[1]==0) 
        {
            seg.update(1,1,m-1,v[r+1].S.F,v[r+1].S.S,1);
            r++;
        }
        if(seg.mini[1]==0) break;
        ans=min(ans,v[r].F-v[l].F);
        seg.update(1,1,m-1,v[l].S.F,v[l].S.S,-1);
        l++;
    }
    printf("%d\n",ans);
    return 0;
}