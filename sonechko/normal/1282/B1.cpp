#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int a[N];
int n,p,k;
int dp[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n>>p>>k;
        for (int i=1; i<=n; i++)
            cin>>a[i];
        sort(a+1,a+n+1);
        dp[0]=0;
        int ans=0;
        for (int i=1; i<=n; i++)
        {
            if (i<k) dp[i]=dp[i-1]+a[i]; else dp[i]=dp[i-k]+a[i];
            if (dp[i]<=p) ans=i;
            ///cout<<dp[i]<<" ";
        }
        cout<<ans<<"\n";
    }
}
/**
1 1 2 2 2

5
**/