#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define L (x<<1)
#define R (L+1)
#define mid (l+r)/2
int a[1000000];
pair<int,int> b[2000000];
pair<int,int> mn[2000000];
void build(int x,int l,int r)
{
    if (l==r)mn[x]={a[l],l};
    else {
        build(L,l,mid),build(R,mid+1,r);
        mn[x]=min(mn[L],mn[R]);
    }
}
pair<int,int> query(int x,int l,int r,int s,int e,int v)
{
    if (mn[x].first*2>=v)return {-1,-1};
    if (l>e || r<s)return {-1,-1};
    if (l==r)return mn[x];
    auto p = query(L,l,mid,s,e,v);
    if (p.first!=-1)return p;
    auto q = query(R,mid+1,r,s,e,v);
    return q;
}
int n;
int tree[2000000];
int dp[2000000];
void build2(int x,int l,int r)
{
    if (l==r){
        tree[x]=1e7;
    } else {
        build2(L,l,mid);
        build2(R,mid+1,r);
        tree[x]=1e7;
    }
}
int query2(int x,int l,int r,int s,int e)
{
    if (l>e || r<s)return 1e7;
    if (l>=s && r<=e)return tree[x];
    return min(query2(L,l,mid,s,e),query2(R,mid+1,r,s,e));
}
void upd(int x,int l,int r,int v){
    if (v>r || v<l)return;
    if (l==r)tree[x]=dp[v];
    else{
        if (v<=mid)upd(L,l,mid,v);
        else upd(R,mid+1,r,v);
        tree[x]=min(tree[L],tree[R]);
    }
}
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        cin>>a[i];
        b[i]={a[i],i};
        a[i+n]=a[i];
        a[i+2*n]=a[i];
    }
    a[n*3]=0;
    sort(b,b+n);
    reverse(b,b+n);
    build(1,0,3*n);
    build2(1,0,3*n);
    for (int i=0;i<n;i++){
        int id = b[i].second;
        int v = b[i].first;
        auto p = query(1,0,3*n,id,3*n,v);
        dp[id] = min(p.second,query2(1,0,3*n,id,p.second));
        dp[id+n]=n+dp[id];
        upd(1,0,3*n,id);
        upd(1,0,3*n,id+n);
    }

    for (int i=0;i<n;i++){
        dp[i]=dp[i]-i;
        if (dp[i]>2*n)dp[i]=-1;
    }
    for (int i=0;i<n;i++)printf("%d ",dp[i]);
}