#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ll long long

const int N = 2e5 + 11;

ll dp[N];

void up()
{
    int d,m;
    cin>>d>>m;
    int dd=d;
    string s="";
    while (d>0)
    {
        s+=(d%2+'0');
        d/=2;
    }
    reverse(s.begin(),s.end());
    s="."+s;
    int n=s.size()-1;
    dp[0]=1;
    int ans=0;
    for (int i=1; i<=n; i++)
    {
        dp[i]=0;
        ll kol=0;
        if (i<n) kol=(1<<(i-1)); else
        {
            kol=(dd-(1<<(i-1))+1);
        }
        for (int j=0; j<i; j++)
            dp[i]=(dp[i]+dp[j])%m;
        ///cout<<i<<": "<<dp[i]<<" * "<<kol<<endl;
        dp[i]=(dp[i]*1ll*kol)%m;
        ans=(ans+dp[i])%m;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
        up();
}