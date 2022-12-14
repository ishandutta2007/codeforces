#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mid (l+r)/2
#define L (x<<1)
#define R (L+1)
int has[1000000];
int num[1000000];
int tree[5000000];
void build(int x,int l,int r){
    if (l==r)tree[x]=num[l];
    else {
        build(L,l,mid);
        build(R,mid+1,r);
        tree[x]=tree[L]+tree[R];
    }
}
void upd(int x,int l,int r,int v){
    if (l==r)tree[x]=num[v];
    else {
        if (v<=mid)upd(L,l,mid,v);
        else upd(R,mid+1,r,v);
        tree[x]=tree[x*2]+tree[x*2+1];
    }
}
int query(int x,int l,int r,int s,int e){
    if (s>r || l>e)return 0;
    if (l>=s && r<=e)return tree[x];
    return query(L,l,mid,s,e)+query(R,mid+1,r,s,e);
}
vector<int> adj[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,p;
    cin>>n>>p;
    num[0]=n;
    for (int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        num[has[x]]--;
        has[x]++;
        num[has[x]]++;
        num[has[y]]--;
        has[y]++;
        num[has[y]]++;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    build(1,0,n);
    ll ret=0;
    for (int i=1;i<=n;i++){
        num[has[i]]--;
        upd(1,0,n,has[i]);
        for (auto x:adj[i]){
            num[has[x]]--;
            has[x]--;
            num[has[x]]++;
            upd(1,0,n,has[x]+1);
            upd(1,0,n,has[x]);
        }
if (has[i]>=p)ret+=n-1;
        else ret+=query(1,0,n,p-has[i],n);
        for (auto x:adj[i]){
            num[has[x]]--;
            has[x]++;
            num[has[x]]++;
            upd(1,0,n,has[x]-1);
            upd(1,0,n,has[x]);
        }
        
        num[has[i]]++;
        upd(1,0,n,has[i]);
    }
    cout<<ret/2<<endl;
}