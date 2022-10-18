#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e6 + 11;

int dp[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    s="."+s;
    int n=s.size()-1;
    dp[0]=0;
    for (int i=1; i<=n; i++)
    {
        int mask=0,kk=0;
        for (int j=i; j<=n; j++)
        {
            int l=s[j]-'a';
            if (mask&(1<<l)) break;
            mask^=(1<<l);
            kk++;
            dp[mask]=kk;
            ///cout<<mask<<" - "<<kk<<endl;
        }
    }
    int ans=0;
    for (int p=0; p<20; p++)
    for (int mask=0; mask<(1<<20); mask++)
    if ((mask&(1<<p))==0) dp[(mask^(1<<p))]=max(dp[(mask^(1<<p))],dp[mask]);
    ///for (int i=0; i<(1<<3); i++)
    ///    cout<<i<<" - "<<dp[i]<<endl;
    for (int mask=0; mask<(1<<20); mask++)
        ans=max(ans,dp[mask]+dp[(1<<20)-1-mask]);
    cout<<ans;
}