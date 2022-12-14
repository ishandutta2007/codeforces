#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mid ((l+r)/2)
#define L (x<<1)
#define R (L+1)
int tree[1000000];
int lazy[1000000];
void lzy(int x,int l,int r){
    if (!lazy[x])return;
    tree[x] = lazy[x];
    if (l!=r) lazy[L]=lazy[R]=lazy[x];
    lazy[x]=0;
}
void build(int x,int l,int r){
    if (l==r)tree[x]=1e9;
    else {
        build(L,l,mid); build(R,mid+1,r);
        tree[x]=min(tree[L],tree[R]);
    }
}
void upd(int x,int l,int r,int s,int e,int v){
    lzy(x,l,r);
    if (s>r||e<l)return;
    if (l>=s && r<=e) {
        lazy[x]=v;
        lzy(x,l,r);
        return;
    }
    upd(L,l,mid,s,e,v);
    upd(R,mid+1,r,s,e,v);
    tree[x] = min(tree[L],tree[R]);
}
int query(int x,int l,int r,int id){
    lzy(x,l,r);
    if (id>r || id<l)return 1e9;
    if (l==r)return tree[x];
    return min(query(L,l,mid,id),query(R,mid+1,r,id));
}
int a[1000000];
int b[1000000];
int x[1000000];
int y[1000000];
int k[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    build(1,1,n);
    for (int i=1;i<=n;i++)cin>>a[i];
    for (int i=1;i<=n;i++)cin>>b[i];
    for (int i=1;i<=q;i++){
        int t;
        cin>>t;
        if (t==1){
            cin>>x[i]>>y[i]>>k[i];
            upd(1,1,n,y[i],y[i]+k[i]-1,i);
        } else {
            int o;
            cin>>o;
            int id = query(1,1,n,o);
            if (id==1e9){
                cout<<b[o]<<endl;
                continue;
            }
            int dist = o - y[id];
            int ind = x[id]+dist;
            cout<<a[ind]<<endl;
        }
    }
}