#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ss second
#define ff first
#define ll long long
#define pb push_back
#define y1 dkne
const ll MOD = 1e9 + 7;
#define mod %MOD


const int  N = 1000 + 11;
int dp[N][5],a[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int sum=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    for (int i=n; i>=1; i--)
    for (int j=1; j<=2; j++)
    {
        int ks1=dp[i+1][j];
        if (j==2) ks1+=a[i];
        int ks2=dp[i+1][3-j];
        if (j==1) ks2+=a[i];
        if (j==1) dp[i][j]=max(ks1,ks2); else
            dp[i][j]=min(ks1,ks2);
    }
    cout<<sum-dp[1][1]<<" "<<dp[1][1]<<endl;
}