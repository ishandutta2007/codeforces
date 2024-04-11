#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define L (x<<1)
#define R (L+1)
#define mid (l+r)/2
ll tree[1000000];
void build(int x,int l,int r) {
    if (l==r)tree[x]=1e17;
    else {
        build(L,l,mid);
        build(R,mid+1,r);
        tree[x]=min(tree[L],tree[R]);
    }
}
void upd(int x,int l,int r,int id,ll val) {
    if (l==r)tree[x]=val;
    else {
        if (id<=mid)upd(L,l,mid,id,val);
        else upd(R,mid+1,r,id,val);
        tree[x]=min(tree[x*2],tree[x*2+1]);
    }
}
ll query(int x,int l,int r,int s,int e) {
    if (l>e || r<s)return 1e18;
    if (l>=s && r<=e)return tree[x];
    return min(query(L,l,mid,s,e),query(R,mid+1,r,s,e));
}
ll dp[10000000];
vector<pair<int,int> > routers[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    s="."+s; // make it 1-indexed
    for (int i=1;i<=n;i++) {
        if (s[i]=='1') {
            int st = max(1,i-k);
            int en = min(n,i+k);
            int cost = i;
            routers[en].push_back({st,cost});
        }
    }
    build(1,0,n);
    dp[0]=0;
    upd(1,0,n,0,0); // put base case in segment tree, dp[0]=0
    for (int i=1;i<=n;i++) {
        dp[i]=dp[i-1]+i; // direct connection
        for (auto router:routers[i]) // Try all routers that end in ith position
            dp[i]=min(dp[i],query(1,0,n,router.first-1,i-1)+router.second);
        upd(1,0,n,i,dp[i]); // Store dp[i] in segment tree
    }
    cout<<dp[n]<<endl;
}