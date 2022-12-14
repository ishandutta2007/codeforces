#include <bits/stdc++.h>
using namespace std;
#define mid (l+r)/2
#define L (x<<1)
#define R (L+1)
pair<long long,int> tree[3000000];
long long lazy[3000000];
long long a[1000000];
void build(int x,int l,int r)
{
    if (l==r)tree[x]={a[l],-l};
    else
    {
        build(L,l,mid);
        build(R,mid+1,r);
        tree[x]=min(tree[x*2],tree[x*2+1]);
    }
}
void lzy(int x,int l,int r)
{
    tree[x].first+=lazy[x];
    if (l!=r)
        lazy[L]+=lazy[x],lazy[R]+=lazy[x];
    lazy[x]=0;
}
void upd(int x,int l,int r,int s,int e,long long v)
{
    lzy(x,l,r);
    if (l>e || r<s)return;
    if (l>=s && r<=e)
    {
        lazy[x]+=v;
        lzy(x,l,r);
        return;
    }
    upd(L,l,mid,s,e,v);
    upd(R,mid+1,r,s,e,v);
    tree[x]=min(tree[L],tree[R]);
}
pair<long long,int> query(int x,int l,int r,int s,int e)
{
    lzy(x,l,r);
    if (l>e || r<s)return {1e17,1};
    if (l>=s && r<=e)return tree[x];

    return min(query(L,l,mid,s,e),query(R,mid+1,r,s,e));
}
long long ret[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    build(1,1,n);
    for (int i=1;i<=n;i++)
    {
        pair<long long,int> v = query(1,1,n,1,n);
        v.second=-v.second;
        ret[v.second]=i;
        upd(1,1,n,v.second+1,n,-i);
        upd(1,1,n,v.second,v.second,1e15);
    }
    for (int i=1;i<=n;i++)
        cout<<ret[i]<<' ';
    cout<<endl;
}