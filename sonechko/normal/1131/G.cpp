#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

const int N = 3e5 + 11;
const int M = 1e7 + 11;
const int MOD = 1e9 + 7;

vector<int> v1[N],v2[N];
int a[M];
ll b[M];
int l1[M],r1[M];
ll dp[M];
ll dpp[M];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        int k;
        cin>>k;
        for (int j=1; j<=k; j++)
        {
            int p;
            cin>>p;
            v1[i].pb(p);
        }
        for (int j=1; j<=k; j++)
        {
            int p;
            cin>>p;
            v2[i].pb(p);
        }
    }
    int q;
    cin>>q;
    m=0;
    for (int j=1; j<=q; j++)
    {
        int id,mult;
        cin>>id>>mult;
        for (int j=0; j<v1[id].size(); j++)
        {
            m++;
            a[m]=v1[id][j];
            b[m]=v2[id][j]*1ll*mult;
        }
    }
    vector<pair<int,int> > vv;

    vv.clear();
    for (int i=m; i>=1; i--)
    {
        r1[i]=i;
        while (vv.size()>0)
        {
            int l=vv.back().ff,r=vv.back().ss;
            if (l-i<a[i]) {r1[i]=r; vv.pop_back();} else break;
        }
        vv.pb(mp(i,r1[i]));
    }
    vv.clear();
    for (int i=1; i<=m; i++)
        dp[i]=2e18;
    for (int i=1; i<=m; i++)
    {
        l1[i]=i;
        dpp[i]=2e18;
        while (vv.size()>0)
        {
            int l=vv.back().ff,r=vv.back().ss;
            if (i-l<a[i]) {l1[i]=r; vv.pop_back(); dpp[i]=min(dpp[i],dpp[l]);} else break;
        }
        dp[i]=min(dp[i],min(dpp[i],dp[l1[i]-1])+b[i]);
        vv.pb(mp(i,l1[i]));
        dp[r1[i]]=min(dp[r1[i]],dp[i-1]+b[i]);
        dpp[i]=min(dpp[i],dp[i]);
    }
    cout<<dp[m];
}