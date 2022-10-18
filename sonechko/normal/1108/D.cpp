#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;

int dp[N][3];
int pr[N][3];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    s="."+s;
    for (int i=1; i<=n; i++)
    for (int t=0; t<3; t++)
    dp[i][t]=2e9;
    for (int i=1; i<=n; i++)
    for (int d=0; d<3; d++)
    for (int p=0; p<3; p++)
    if (d!=p)
    {
        int r=dp[i-1][d];
        if (s[i]=='R'&&p!=0) r++;
        if (s[i]=='G'&&p!=1) r++;
        if (s[i]=='B'&&p!=2) r++;
        if (r<dp[i][p])
        {
            dp[i][p]=r;
            pr[i][p]=d;
        }
    }
    int k=0;
    for (int i=0; i<3; i++)
        if (dp[n][i]<dp[n][k]) k=i;
    cout<<dp[n][k]<<endl;
    string ans="";
    for (int i=n; i>=1; i--)
    {
        if (k==0) ans+="R";
        if (k==1) ans+="G";
        if (k==2) ans+="B";
        k=pr[i][k];
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}