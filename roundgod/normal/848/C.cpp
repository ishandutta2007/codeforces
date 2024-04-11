#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
set<int> s[MAXN];
struct qr
{
    int type,l,r,x,y;
};
vector<qr> query;
void ins(int i,int v)
{
    auto it=s[a[i]].find(i);
    int pre=0,suf=n+1;
    if(it!=s[a[i]].begin()) {it--; pre=*it; it++;}
    it++;
    if(it!=s[a[i]].end()) suf=*it;
    it--;
    if(pre!=0) query.push_back((qr){1,i,pre,*it-pre,v});
    if(suf!=n+1) query.push_back((qr){1,suf,*it,suf-*it,v});
    if(pre!=0&&suf!=n+1) query.push_back((qr){1,suf,pre,suf-pre,-v});
}
struct segtree
{
    vector<int> dis[4*MAXN];
    vector<ll> bit[4*MAXN];
    void ins(int k,int l,int r,int p,int v)
    {
        dis[k].push_back(v);
        if(l==r) return; 
        int mid=(l+r)/2;
        if(p<=mid) ins(k*2,l,mid,p,v); else ins(k*2+1,mid+1,r,p,v);
    }
    void insq(int k,int l,int r,int x,int y,int v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y) 
        {
            dis[k].push_back(v);
            return;
        }
        int mid=(l+r)/2;
        insq(k*2,l,mid,x,y,v); insq(k*2+1,mid+1,r,x,y,v);
    }
    void discretize(int k,int l,int r)
    {
        sort(dis[k].begin(),dis[k].end());
        dis[k].erase(unique(dis[k].begin(),dis[k].end()),dis[k].end());
        bit[k].resize((int)dis[k].size()+1);
        if(l==r) return;
        int mid=(l+r)/2;
        discretize(k*2,l,mid); discretize(k*2+1,mid+1,r);
    }
    void update(int k,int l,int r,int pos,int x,int v)
    {
        int p=lower_bound(dis[k].begin(),dis[k].end(),x)-dis[k].begin()+1;
        p=(int)bit[k].size()-p;
        while(p<(int)bit[k].size())
        {
            bit[k][p]+=v;
            p+=p&-p;
        }
        if(l==r) return;
        int mid=(l+r)/2;
        if(pos<=mid) update(k*2,l,mid,pos,x,v); else update(k*2+1,mid+1,r,pos,x,v);
    }
    ll query(int k,int l,int r,int x,int y,int v)
    {
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y)
        {
            int p=lower_bound(dis[k].begin(),dis[k].end(),v)-dis[k].begin()+1;
            ll s=0;
            p=(int)bit[k].size()-p;
            while(p>0)
            {
                s+=bit[k][p];
                p-=p&-p;
            }
            return s;
        }
        int mid=(l+r)/2;
        return query(k*2,l,mid,x,y,v)+query(k*2+1,mid+1,r,x,y,v);
    }
}seg;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) 
    {
        s[a[i]].insert(i);
        ins(i,1);
    }
    for(int i=0;i<m;i++)
    {
        int t,l,r;
        scanf("%d%d%d",&t,&l,&r);
        if(t==2) query.push_back((qr){t,l,r,0,0});
        else
        {
            ins(l,-1); 
            s[a[l]].erase(l);
            a[l]=r;
            s[a[l]].insert(l);
            ins(l,1);
        }
    }
    for(auto p:query)
    {
        if(p.type==1) seg.ins(1,1,n,p.l,p.r);
        else seg.insq(1,1,n,p.l,p.r,p.l);
    }
    seg.discretize(1,1,n);
    for(auto p:query)
    {
        if(p.type==1) seg.update(1,1,n,p.l,p.r,p.x*p.y);
        else printf("%lld\n",seg.query(1,1,n,p.l,p.r,p.l));
    }
    return 0;
}