#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define x1 dskaodo
#define y1 dsakod
#define x2 daskodsa
#define y2 daokdsaoa
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,sa[MAXN],ea[MAXN],sb[MAXN],eb[MAXN];
struct node
{
    int x1,y1,x2,y2;
    int id;
};
vector<int> v;
vector<P> s1[MAXN],t1[MAXN],s2[MAXN],t2[MAXN];
struct segtree
{
    int len[4*MAXN];
    ll sum[4*MAXN];
    ll lazy[4*MAXN];
    void pushup(int k)
    {
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    void add(int k,int v)
    {
        lazy[k]+=v;
        sum[k]+=1LL*len[k]*v;
    }
    void pushdown(int k)
    {
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++) 
        {
            sum[i]+=1LL*len[i]*lazy[k];
            lazy[i]+=lazy[k];
        }
        lazy[k]=0;
    }
    void build(int k,int l,int r)
    {
        len[k]=r-l+1;
        lazy[k]=sum[k]=0;
        if(l==r) return;
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
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
    ll query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return sum[k];
        pushdown(k);
        int mid=(l+r)/2;
        return query(k*2,l,mid,x,y)+query(k*2+1,mid+1,r,x,y);
    }
}seg;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d%d%d%d",&sa[i],&ea[i],&sb[i],&eb[i]);
        v.push_back(sa[i]); v.push_back(ea[i]);
        v.push_back(sb[i]); v.push_back(eb[i]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=1;i<=n;i++)
    {
        sa[i]=lower_bound(v.begin(),v.end(),sa[i])-v.begin()+1;
        ea[i]=lower_bound(v.begin(),v.end(),ea[i])-v.begin()+1;
        sb[i]=lower_bound(v.begin(),v.end(),sb[i])-v.begin()+1;
        eb[i]=lower_bound(v.begin(),v.end(),eb[i])-v.begin()+1;
        s1[ea[i]+1].push_back((P){sb[i],eb[i]});
        s2[sa[i]].push_back((P){sb[i],eb[i]});
        t1[eb[i]+1].push_back((P){sa[i],ea[i]});
        t2[sb[i]].push_back((P){sa[i],ea[i]});
    }
    bool f=true;
    int sz=(int)v.size();
    seg.build(1,1,sz);
    for(int i=1;i<=sz;i++)
    {
        for(auto x:s1[i]) 
        {
            seg.update(1,1,sz,x.F,x.S,1);
        }
        for(auto x:s2[i])
        {
            if(seg.query(1,1,sz,x.F,x.S)) f=false;
        } 
    }
    seg.build(1,1,sz);
    for(int i=1;i<=sz;i++)
    {
        for(auto x:t1[i]) 
        {
            seg.update(1,1,sz,x.F,x.S,1);
        }
        for(auto x:t2[i])
        {
            if(seg.query(1,1,sz,x.F,x.S)) f=false;
        } 
    }
    if(f) puts("YES"); else puts("NO");
    return 0;
}