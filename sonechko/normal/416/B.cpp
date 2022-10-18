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


const int  N = 1e5 + 11;
int t[N][10],dp[N][10];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    cin>>t[i][j];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            dp[i][j]=max(dp[i][j-1],dp[i-1][j])+t[i][j];
        }
    for (int i=1; i<=n; i++)
        cout<<dp[i][m]<<" ";
    cout<<endl;
}