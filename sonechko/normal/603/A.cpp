#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define ld long double

const int N = 2e5 + 11;
const int MOD = 1e6 + 3;
int dp[N][2];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    string s;
    cin>>n;
    cin>>s;
    s='.'+s;
    for (int i=n; i>=1; i--)
    {
        if (s[i]=='0')
        {
            dp[i][0]=dp[i+1][1]+1;
            dp[i][1]=dp[i+1][1];
        } else
        {
            dp[i][0]=dp[i+1][0];
            dp[i][1]=dp[i+1][0]+1;
        }
    }
    int ans=1,p=0;
    for (int i=2; i<=n; i++)
        if (s[i]!=s[i-1]) ans++; else
        {
            p=i;
            break;
        }
    int d=0,dd=0;
    if (p==0) {cout<<ans<<endl; return 0;}
    int k=0;
    if (s[p-1]=='1') k=1;
    for (int j=p; j<=n; j++)
    {
        if (s[j]=='1'&&k==1)
        {
            k=0;
            d++;
        }
        if (s[j]=='0'&&k==0)
        {
            k=1;
            d++;
        }
        if (k==0) dd=max(dd,dp[j+1][1]+d);
        else dd=max(dd,dp[j+1][0]+d);
    }
    cout<<ans+dd<<endl;
}