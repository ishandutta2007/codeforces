#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair

const int N = 20000 + 11;

vector<int> v[N*4];
vector<pair<int,int> > vv[N];
int ans[N],c[N],h[N];
int dp[20][N];

void update(int i, int l, int r, int tl, int tr, int x)
{
    if (tl<=l&&r<=tr) {v[i].pb(x); return;}
    if (l>tr||tl>r) return;
    int mid=(l+r)/2;
    update(i+i,l,mid,tl,tr,x);
    update(i+i+1,mid+1,r,tl,tr,x);
}

void dfs(int p, int i, int l, int r)
{
    for (int d=0; d<=4000; d++)
        dp[p][d]=dp[p-1][d];
    for (int j=0; j<v[i].size(); j++)
    {
        int l=v[i][j];
        for (int d=4000; d>=c[l]; d--)
            dp[p][d]=max(dp[p][d-c[l]]+h[l],dp[p][d]);
    }
    if (l==r)
    {
        for (int j=0; j<vv[l].size(); j++)
            ans[vv[l][j].ss]=dp[p][vv[l][j].ff];
        return;
    }
    int mid=(l+r)/2;
    dfs(p+1,i+i,l,mid);
    dfs(p+1,i+i+1,mid+1,r);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,p;
    cin>>n>>p;
    for (int i=1; i<=n; i++)
    {
        int t;
        cin>>c[i]>>h[i]>>t;
        update(1,1,20000,t,t+p-1,i);
        ///cout<<t<<".."<<t+p-1<<" "<<i<<endl;
    }
    int q;
    cin>>q;
    for (int j=1; j<=q; j++)
    {
        int l,r;
        cin>>l>>r;
        vv[l].pb(mp(r,j));
    }
    dfs(1,1,1,20000);
    for (int j=1; j<=q; j++)
        cout<<ans[j]<<"\n";
}