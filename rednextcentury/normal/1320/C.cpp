#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000005];
ll b[1000005];
vector<pair<int,ll> > add[1000007];
ll tree[5000000];
ll lazy[5000000];
#define L (x<<1)
#define R (L+1)
#define mid ((l+r)/2)
void build(int x,int l,int r){
    if (l==r) tree[x] = b[l];
    else {
        build(L,l,mid); build(R,mid+1,r);
        tree[x]=max(tree[L],tree[R]);
    }
}
void lzy(int x,int l,int r){
    tree[x]+=lazy[x];
    if (l!=r) lazy[L]+=lazy[x], lazy[R]+=lazy[x];
    lazy[x]=0;
}
void upd(int x,int l,int r,int s,int e,ll v){
    lzy(x,l,r);
    if (l>e || r<s)return;
    if (l>=s && r<=e){
        lazy[x]+=v;
        lzy(x,l,r);
        return;
    }
    upd(L,l,mid,s,e,v);
    upd(R,mid+1,r,s,e,v);
    tree[x]=max(tree[L],tree[R]);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    int mx = 1e6+1;
    for (int i=0;i<=mx;i++) a[i] = 1e16, b[i] = -1e16;
    for (int i=1;i<=n;i++){
        ll x,y;
        cin>>x>>y;
        a[x]=min(a[x],y);
    }
    for (int i=1;i<=m;i++){
        ll x,y;
        cin>>x>>y;
        b[x]=max(b[x],-y);
    }
    for (int i=1;i<=k;i++){
        int x,y,z;
        cin>>x>>y>>z;
        add[x].push_back({y,z});
    }
    for (int i=mx-1;i>=0;i--) a[i] = min(a[i], a[i+1]), b[i]=max(b[i],b[i+1]);
    ll ret=-1e18;
    build(1,0,mx);
    for (int i=1;i<=mx;i++){
        for (auto [v,val]:add[i-1]){
            upd(1,0,mx,v+1,mx,val);
        }
        lzy(1,0,mx);
        ll best = tree[1] - a[i];
        ret=max(ret, best);
    }
    cout<<ret<<endl;
}