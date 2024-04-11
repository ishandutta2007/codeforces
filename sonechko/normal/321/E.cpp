#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define y1 skfn

const int N = 4000 + 11;
const int MOD = 1e9 + 7;
#define mod %MOD

int a[N][N],s[N][N],d[N][N];
int dp[801][N];

void up(int l, int r, int ol, int orr, int k)
{
    int mid=(l+r)/2;
    int pos=ol;
    for (int i=ol; i<=min(orr,mid-1); i++)
    if (dp[k-1][i]+d[i+1][mid]<dp[k][mid])
    {
        dp[k][mid]=dp[k-1][i]+d[i+1][mid];
        pos=i;
    }
    //cout<<k<<" "<<mid<<" - "<<dp[k][mid]<<endl;
    if (l<=mid-1) up(l,mid-1,ol,pos,k);
    if (mid+1<=r) up(mid+1,r,pos,orr,k);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    {
        char ch;
        cin>>ch;
        a[i][j]=ch-'0';
        s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
    }
    for (int i=1; i<=n; i++)
    for (int j=1; j<=k; j++)
        dp[j][i]=1e9;
    for (int l=1; l<=n; l++)
    for (int r=l; r<=n; r++)
        d[l][r]=s[r][r]-s[l-1][r]-s[r][l-1]+s[l-1][l-1];
    for (int i=1; i<=n; i++)
    {
        dp[1][i]=d[1][i];
    }
    for (int p=2; p<=k; p++)
        up(1,n,1,n,p);
    cout<<dp[k][n]/2<<endl;
}