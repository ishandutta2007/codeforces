#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;

int a[N],dp[N][6][6];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        a[l]++;
    }
    //for (int i=1; i<=m; i++)
    //    cout<<a[i]<<" ";
    //cout<<endl;
    for (int i=1; i<=m+2; i++)
    for (int p=0; p<=5; p++)
    for (int d=0; d<=5; d++)
    dp[i][p][d]=-2e9;
    dp[m+1][0][0]=0;
    int ans=0;
    for (int i=m; i>=1; i--)
    for (int t1=0; t1<=5; t1++)
    for (int t2=0; t2<=5; t2++)
    for (int kk=0; kk<=min(a[i],5); kk++)
    for (int tt=0; tt<=min(a[i]-kk,5); tt++)
    {
        int c=min(t1,min(t2,kk));
        int cc=(a[i]-c-tt)/3,dd=tt;
        dp[i][dd][t1-c]=max(dp[i][dd][t1-c],cc+c+dp[i+1][t1][t2]);
        //cout<<i<<" "<<dd<<" "<<t1-c<<" - "<<dp[i][dd][t1-c]<<endl;
        ans=max(ans,dp[i][dd][t1-c]);
    }
    cout<<ans<<endl;
}