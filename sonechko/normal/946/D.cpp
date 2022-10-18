#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ss second
#define ff first
#define endl "\n"
#define ld long double
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;
const int N = 1000 + 11;

int dp[N][N],kol[N][N],c1[N],c2[N];
string s[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1; i<=n; i++)
    {
        cin>>s[i];
        s[i]="."+s[i];
        for (int c=0; c<=m; c++)
            kol[i][c]=m;
        for (int j=1; j<=m; j++)
        {
            c1[j]=c1[j-1];
            if (s[i][j]=='1') c1[j]++;
        }
        for (int j=1; j<=m; j++)
        for (int k=j; k<=m; k++)
        {
            int kk=c1[k]-c1[j-1];
            kol[i][c1[m]-kk]=min(kol[i][c1[m]-kk],k-j+1);
        }
        kol[i][c1[m]]=0;
    }
    for (int i=1; i<=n; i++)
    for (int j=0; j<=k; j++)
    dp[i][j]=n*m;
    dp[0][0]=0;
    for (int i=1; i<=n; i++)
    for (int j=0; j<=k; j++)
    for (int p=0; p<=m; p++)
    dp[i][j+p]=min(dp[i][j+p],dp[i-1][j]+kol[i][p]);
    int res=n*m;
    for (int j=0; j<=k; j++)
        res=min(res,dp[n][j]);
    cout<<res<<endl;
}