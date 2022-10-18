#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

ll dp[N][2],a[N],b[N],n,c;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>c;
    for (int i=2; i<=n; i++)
        cin>>a[i];
    for (int i=2; i<=n; i++)
        cin>>b[i];
    dp[1][0]=0;
    dp[1][1]=2e9;
    for (int i=2; i<=n; i++)
    {
        dp[i][0]=min(dp[i-1][0]+a[i],dp[i-1][1]+a[i]);
        dp[i][1]=min(dp[i-1][1]+b[i],dp[i-1][0]+b[i]+c);
    }
    for (int i=1; i<=n; i++)
        cout<<min(dp[i][0],dp[i][1])<<" ";
    cout<<endl;
}