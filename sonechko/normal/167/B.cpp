#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mod %MOD

const int N = 200 + 11;
const int MOD = 1e9 + 7;

ld dp[N][N][N*2],p[N];
int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,l,k;
    cin>>n>>l>>k;
    for (int i=1; i<=n; i++)
    {
        cin>>p[i];
        p[i]/=100;
    }
    for (int j=1; j<=n; j++)
        cin>>a[j];
    dp[0][0][k+200]=1;
    cout.precision(10);
    cout<<fixed;
    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<i; j++)
        for (int kol=-200; kol<=200; kol++)
        {
            dp[i][j+1][min(200,kol+a[i])+200]+=dp[i-1][j][kol+200]*p[i];
            dp[i][j][kol+200]+=dp[i-1][j][kol+200]*(1-p[i]);
        }
    }
    ld ans=0;
    for (int j=l; j<=n; j++)
    for (int kol=0; kol<=200; kol++)
    ans+=dp[n][j][kol+200];
    cout<<ans<<endl;
}