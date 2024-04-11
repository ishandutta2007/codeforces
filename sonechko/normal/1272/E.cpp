#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 2e5 + 11;

int a[N],dp[N],ans[N];
vector<int> v[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        if (i-a[i]>=1) v[i-a[i]].pb(i);
        if (i+a[i]<=n) v[i+a[i]].pb(i);
    }
    vector<int> vv;

    vv.clear();
    for (int i=1; i<=n; i++)
        if (a[i]%2==0) {dp[i]=0; vv.pb(i);} else dp[i]=-1;
    for (int j=0; j<vv.size(); j++)
    {
        int l=vv[j];
        for (int j=0; j<v[l].size(); j++)
            if (dp[v[l][j]]==-1)
        {
            dp[v[l][j]]=dp[l]+1;
            vv.pb(v[l][j]);
        }
    }
    for (int i=1; i<=n; i++)
        if (a[i]%2==1) ans[i]=dp[i];

    vv.clear();
    for (int i=1; i<=n; i++)
        if (a[i]%2==1) {dp[i]=0; vv.pb(i);} else dp[i]=-1;
    for (int j=0; j<vv.size(); j++)
    {
        int l=vv[j];
        for (int j=0; j<v[l].size(); j++)
            if (dp[v[l][j]]==-1)
        {
            dp[v[l][j]]=dp[l]+1;
            vv.pb(v[l][j]);
        }
    }
    for (int i=1; i<=n; i++)
        if (a[i]%2==0) ans[i]=dp[i];
    for (int i=1; i<=n; i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
}