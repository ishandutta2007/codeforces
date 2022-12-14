#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define L (x<<1)
#define R (L+1)
#define mid (l+r)/2
pair<int,int> mxT[1000000];
pair<int,int> mnT[1000000];
void buildMn(int x,int l,int r) {
    if (l==r)mnT[x] = {l,l};
    else {
        buildMn(L,l,mid);
        buildMn(R,mid+1,r);
        mnT[x]=min(mnT[x*2],mnT[x*2+1]);
    }
}
int par[1000000];
void buildMx(int x,int l,int r) {
    if (l==r)mxT[x] = {l,l};
    else {
        buildMx(L,l,mid);
        buildMx(R,mid+1,r);
        mxT[x]=max(mxT[x*2],mxT[x*2+1]);
    }
}
void update(int x,int l,int r,int id,int val) {
    if (id>r || id<l)return;
    if (l==r)
        mnT[x]={val,l},mxT[x]={val,l};
    else {
        update(L,l,mid,id,val);
        update(R,mid+1,r,id,val);
        mnT[x] = min(mnT[L],mnT[R]);
        mxT[x] = max(mxT[L],mxT[R]);

    }
}
pair<int,int> mnQ(int x,int l,int r,int s,int e) {
    if (l>e || r<s)return {1e9,1e9};
    if (l>=s && r<=e)return mnT[x];
    return min(mnQ(L,l,mid,s,e),mnQ(R,mid+1,r,s,e));
}
pair<int,int> mxQ(int x,int l,int r,int s,int e) {
    if (l>e || r<s)return {-1e9,-1e9};
    if (l>=s && r<=e)return mxT[x];
    return max(mxQ(L,l,mid,s,e),mxQ(R,mid+1,r,s,e));
}
vector<int> C[1000000];
int n,m;
int sz[1000000];
int mn[1000000];
int mx[1000000];
set<int> invalid;
int getP(int v) {
    if (par[v]==v)return v;
    return par[v]=getP(par[v]);
}
void Merge(int u,int v) {
    u = getP(u);
    v = getP(v);
    if (u==v)return;
    if (sz[u]>sz[v]) {
        swap(u,v);
    }
    sz[v]+=sz[u];
    mx[v]=max(mx[v],mx[u]);
    mn[v]=min(mn[v],mn[u]);
    par[u]=v;
    if (mx[v]-mn[v]+1!=sz[v])invalid.insert(v);
    for (auto x:C[u]) {
        C[v].push_back(x);
        update(1,1,n,x,v);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        par[i]=i;
        sz[i]=1;
        mn[i]=i,mx[i]=i;
        C[i].push_back(i);
    }
    buildMn(1,1,n);
    buildMx(1,1,n);
    for (int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        Merge(u,v);
    }
    int ret=0;
    while(!invalid.empty()) {
        int v = *invalid.begin();
        invalid.erase(v);
        v = getP(v);
        pair<int,int> LL = mnQ(1,1,n,mn[v],mx[v]);
        pair<int,int> RR = mxQ(1,1,n,mn[v],mx[v]);
//        LL.first = getP(LL.first);
//        RR.first = getP(RR.first);
        if (LL.first!=v){
            Merge(v,LL.first);
            ret++;
            continue;
        }
        if (RR.first!=v){
            Merge(v,RR.first);
            ret++;
            continue;
        }
    }
    cout<<ret<<endl;
}