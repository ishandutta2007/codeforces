#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct segtree
{
    //maintain sum a^2b-sum ab
    //update: seg+1 (a+v)^2b=a^2b+2avb+v^2b
    ll suma2b[4*MAXN],sumab[4*MAXN],sumb[4*MAXN];
    ll suma[4*MAXN];
    int lazy[4*MAXN];
    void build(int k,int l,int r)
    {
        lazy[k]=suma2b[k]=sumab[k]=sumb[k]=suma[k]=0;
        if(l==r) return;
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
    }
    void pushup(int k)
    {
        suma2b[k]=suma2b[k*2]+suma2b[k*2+1];
        sumab[k]=sumab[k*2]+sumab[k*2+1];
        sumb[k]=sumb[k*2]+sumb[k*2+1];
        suma[k]=max(suma[k*2],suma[k*2+1]);
    }
    void add(int k,int v)
    {
        suma2b[k]+=2LL*v*sumab[k]+1LL*v*v*sumb[k];
        sumab[k]+=1LL*v*sumb[k];
        suma[k]+=v;
        lazy[k]+=v;
    }
    void pushdown(int k)
    {
        if(lazy[k]==0) return;
        for(int i=k*2;i<=k*2+1;i++) add(i,lazy[k]);
        lazy[k]=0;
    }
    void update(int k,int l,int r,int pos,int v)//v=0: remove v=1:add
    {
        if(l==r)
        {
            ll x=suma[k];
            if(v==0)
            {
                sumb[k]=sumab[k]=suma2b[k]=0;
            }
            else
            {
                sumb[k]=1; sumab[k]=x; suma2b[k]=1LL*x*x;
            }
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        if(pos<=mid) update(k*2,l,mid,pos,v); else update(k*2+1,mid+1,r,pos,v);
        pushup(k);
    }
    void update2(int k,int l,int r,int x,int y,int v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y)
        {
            add(k,v);
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        update2(k*2,l,mid,x,y,v); update2(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    ll queryab(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y)
        {
            return sumab[k];
        }
        pushdown(k);
        int mid=(l+r)/2;
        return queryab(k*2,l,mid,x,y)+queryab(k*2+1,mid+1,r,x,y);
    }
    ll querya2b(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y)
        {
            return suma2b[k];
        }
        pushdown(k);
        int mid=(l+r)/2;
        return querya2b(k*2,l,mid,x,y)+querya2b(k*2+1,mid+1,r,x,y);
    }
}seg;
vector<int> dis;
int q,d,a[MAXN];
bool has[MAXN];
int main()
{
    scanf("%d%d",&q,&d);
    for(int i=1;i<=q;i++)
    {
        scanf("%d",&a[i]);
        dis.push_back(a[i]);
    }
    dis.push_back(-INF);
    sort(dis.begin(),dis.end());
    dis.erase(unique(dis.begin(),dis.end()),dis.end());
    int sz=(int)dis.size();
    seg.build(1,1,sz);
    for(int i=1;i<=q;i++)
    {
        int r=lower_bound(dis.begin(),dis.end(),a[i])-dis.begin();
        int l=lower_bound(dis.begin(),dis.end(),a[i]-d)-dis.begin()+1;
        if(has[r+1])
        {
            seg.update2(1,1,sz,l,r,-1);
            seg.update(1,1,sz,r+1,0);
            has[r+1]=false;
        }
        else
        {
            seg.update2(1,1,sz,l,r,1);
            seg.update(1,1,sz,r+1,1);
            has[r+1]=true;
        }
        ll ans=(seg.querya2b(1,1,sz,1,sz)-seg.queryab(1,1,sz,1,sz))/2;
        printf("%lld\n",ans);
    }
    return 0;
}