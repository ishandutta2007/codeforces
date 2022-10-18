#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;
const int MOD = 1e9 + 7;
const int MX = 2e18;

#define mod %MOD

int kol[N],kk[N],a[N];
int dp[501][5001];


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=1; i<=n*k; i++)
    {
        int l;
        cin>>l;
        kol[l]++;
    }
    for (int i=1; i<=n; i++)
    {
        int p;
        cin>>p;
        kk[p]++;
    }
    for (int i=1; i<=k; i++)
        cin>>a[i];
    for (int i=1; i<=500; i++)
    for (int j=1; j<=5000; j++)
    for (int d=0; d<=min(k,j); d++)
    dp[i][j]=max(dp[i][j],dp[i-1][j-d]+a[d]);
    int ans=0;
    for (int i=1; i<=100000; i++)
        if (kk[i]>0) ans+=dp[kk[i]][kol[i]];
    cout<<ans<<endl;
}