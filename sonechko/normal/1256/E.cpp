#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

ll dp[N],dd[N],pr[N],pp[N],ans[N];
pair<ll,int> a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i].ff;
        a[i].ss=i;
    }
    sort(a+1,a+n+1);
    dp[0]=0;
    dd[0]=0;
    for (int i=1; i<=n; i++)
    {
        if (i<3) {dp[i]=2e18; pr[i]=-1;} else
        {
            dp[i]=a[i].ff+dd[i-2];
            pr[i]=pp[i-2];
        }
        dd[i]=dd[i-1];
        pp[i]=pp[i-1];
        if (dp[i-1]-a[i].ff<dd[i])
        {
            dd[i]=dp[i-1]-a[i].ff;
            pp[i]=i;
        }
    }
    int t=n;
    int d=0;
    while (t>=1)
    {
        int c=pr[t];
        d++;
        for (int j=c; j<=t; j++)
            ans[a[j].ss]=d;
        t=c-1;
    }
    cout<<dp[n]<<" "<<d<<endl;
    for (int i=1; i<=n; i++)
        cout<<ans[i]<<" ";
}
/**
dp[i]

dp[i]=j -> min(dp[j-1]+a[i]-a[j]);
**/