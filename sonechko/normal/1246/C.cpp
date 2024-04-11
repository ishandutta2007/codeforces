#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long

const int N = 2000 + 11;
const int MOD = 1e9 + 7;

ll k1[N][N],k2[N][N],dp1[N][N],dp2[N][N],t1[N][N],t2[N][N];
char a[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie();
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    {
        cin>>a[i][j];
    }
    for (int i=n; i>=1; i--)
    for (int j=m; j>=1; j--)
    {
        k1[i][j]=k1[i+1][j]+(a[i][j]=='R');
        k2[i][j]=k2[i][j+1]+(a[i][j]=='R');
    }
    if (n==1&&m==1) {cout<<1; return 0;}
    dp1[1][1]=1;
    dp2[1][1]=1;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    {
        t1[i][j]=(t1[i][j-1]+t1[i][j])%MOD;
        t2[i][j]=(t2[i-1][j]+t2[i][j])%MOD;
        dp1[i][j]=(dp1[i][j]+t1[i][j]+MOD)%MOD;
        dp2[i][j]=(dp2[i][j]+t2[i][j]+MOD)%MOD;
        ///cout<<i<<" "<<j<<" = "<<dp1[i][j]<<":"<<dp2[i][j]<<endl;
        int t=k1[i+1][j];
        int l=n-t;
        t2[i+1][j]=(t2[i+1][j]+dp1[i][j]+MOD)%MOD;
        t2[l+1][j]=(t2[l+1][j]-dp1[i][j]+MOD)%MOD;
        t=k2[i][j+1];
        int r=m-t;
        t1[i][j+1]=(t1[i][j+1]+dp2[i][j]+MOD)%MOD;
        t1[i][r+1]=(t1[i][r+1]-dp2[i][j]+MOD)%MOD;
    }
    cout<<(dp1[n][m]+dp2[n][m])%MOD;
}