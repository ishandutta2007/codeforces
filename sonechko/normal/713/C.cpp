#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int N = 3000 + 11;

ll dp[N*N],mn[N*N],dpp[N*N];
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<int> vv;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        a[i]-=i;
        vv.pb(a[i]);
    }
    sort(vv.begin(),vv.end());
    vector<int> pp;
    pp.pb(vv[0]);
    for (int j=1; j<vv.size(); j++)
        if (vv[j]!=pp.back()) pp.pb(vv[j]);
    ll ans=2e18;
    int t=pp.size()-1;
    for (int i=0; i<=t; i++)
    {
        dp[i]=mn[i]=abs(a[1]-pp[i]);
        dpp[i]=2e18;
        if (i>0) mn[i]=min(mn[i],mn[i-1]);
    }
    for (int i=2; i<=n; i++)
    {
        for (int j=0; j<=t; j++)
            dpp[j]=min(dpp[j],mn[j]+abs(a[i]-pp[j]));
        for (int j=0; j<=t; j++)
        {
            dp[j]=mn[j]=dpp[j];
            if (j>0) mn[j]=min(mn[j],mn[j-1]);
            dpp[j]=2e18;
        }
    }
    for (int j=0; j<=t; j++)
        ans=min(ans,dp[j]);
    cout<<ans<<endl;
}