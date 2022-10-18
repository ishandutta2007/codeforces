#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 1e5 + 11;

map<pair<int,int>,bool> mt;
map<pair<int,int>,int> dp;
vector<pair<int,int> > v;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x0,y0,x1,y1;
    cin>>x0>>y0>>x1>>y1;
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int r,a,b;
        cin>>r>>a>>b;
        for (int j=a; j<=b; j++)
            mt[mp(r,j)]=1;
    }
    if (mt[mp(x0,y0)]==0) {cout<<-1<<endl; return 0;}
    v.pb(mp(x0,y0));
    dp[mp(x0,y0)]=1;
    for (int j=0; j<v.size(); j++)
    {
        int l=v[j].ff,r=v[j].ss;
        if (mt[mp(l-1,r)]==1&&dp[mp(l-1,r)]==0)
        {
            dp[mp(l-1,r)]=dp[mp(l,r)]+1;
            v.pb(mp(l-1,r));
        }
        if (mt[mp(l+1,r)]==1&&dp[mp(l+1,r)]==0)
        {
            dp[mp(l+1,r)]=dp[mp(l,r)]+1;
            v.pb(mp(l+1,r));
        }
        if (mt[mp(l,r-1)]==1&&dp[mp(l,r-1)]==0)
        {
            dp[mp(l,r-1)]=dp[mp(l,r)]+1;
            v.pb(mp(l,r-1));
        }
        if (mt[mp(l,r+1)]==1&&dp[mp(l,r+1)]==0)
        {
            dp[mp(l,r+1)]=dp[mp(l,r)]+1;
            v.pb(mp(l,r+1));
        }
        if (mt[mp(l-1,r-1)]==1&&dp[mp(l-1,r-1)]==0)
        {
            dp[mp(l-1,r-1)]=dp[mp(l,r)]+1;
            v.pb(mp(l-1,r-1));
        }
        if (mt[mp(l+1,r+1)]==1&&dp[mp(l+1,r+1)]==0)
        {
            dp[mp(l+1,r+1)]=dp[mp(l,r)]+1;
            v.pb(mp(l+1,r+1));
        }
        if (mt[mp(l+1,r-1)]==1&&dp[mp(l+1,r-1)]==0)
        {
            dp[mp(l+1,r-1)]=dp[mp(l,r)]+1;
            v.pb(mp(l+1,r-1));
        }
        if (mt[mp(l-1,r+1)]==1&&dp[mp(l-1,r+1)]==0)
        {
            dp[mp(l-1,r+1)]=dp[mp(l,r)]+1;
            v.pb(mp(l-1,r+1));
        }
    }
    cout<<dp[mp(x1,y1)]-1<<endl;
}