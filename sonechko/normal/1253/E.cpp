#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long

const int N = 2e5 + 11;

vector<pair<int,int> > v[N];
int dp[N];
vector<pair<int,int> > dpp;

void add(int x, int l)
{
    while (dpp.size()>0&&dpp.back().ff>=x)
        dpp.pop_back();
    dpp.pb(mp(x,l));
}

int get(int pos)
{
    int l=0,r=dpp.size()-1;
    while (r-l>1)
    {
        int mid=(l+r)/2;
        if (dpp[mid].ss<pos) l=mid; else r=mid;
    }
    if (dpp[l].ss>=pos) return dpp[l].ff;
    return dpp[r].ff;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie();
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        int x,s;
        cin>>x>>s;
        for (int rr=0; x+rr<=m*2; rr++)
        {
            int l=x-rr,r=x+rr;
            int c=0;
            if (rr>s) c=rr-s;
            v[r].pb(mp(l,c));
        }
    }
    dp[0]=0;
    add(0,0);
    int ans=2e9;
    for (int i=1; i<=m*2; i++)
    {
        dp[i]=2e9;
        for (int j=0; j<v[i].size(); j++)
        {
            int l=v[i][j].ff;
            int cc=v[i][j].ss;
            dp[i]=min(dp[i],get(l-1)+cc);
        }
        add(dp[i],i);
        ///cout<<i<<" - "<<dp[i]<<endl;
        if (i>=m) ans=min(ans,dp[i]);
    }
    cout<<ans;
}

/**
4
**/