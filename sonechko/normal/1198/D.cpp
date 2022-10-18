#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 50 + 11;


int s[N][N];
int dp[N][N][N][N];

int sum(int l1, int r1, int l2, int r2)
{
    return (s[l2][r2]-s[l1-1][r2]-s[l2][r1-1]+s[l1-1][r1-1]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    {
        char c;
        cin>>c;
        s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        if (c=='#') s[i][j]++;
    }
    for (int l2=1; l2<=n; l2++)
    for (int r2=1; r2<=n; r2++)
    for (int l1=l2; l1>=1; l1--)
    for (int r1=r2; r1>=1; r1--)
        if (sum(l1,r1,l2,r2)==0)
            dp[l1][r1][l2][r2]=0; else
        {
            dp[l1][r1][l2][r2]=max(l2-l1+1,r2-r1+1);
            for (int p=l1; p<=l2; p++)
                if (sum(p,r1,p,r2)==0)
                    dp[l1][r1][l2][r2]=min(dp[l1][r1][l2][r2],
                                    dp[l1][r1][p-1][r2]+dp[p+1][r1][l2][r2]);
            for (int p=r1; p<=r2; p++)
                if (sum(l1,p,l2,p)==0)
                    dp[l1][r1][l2][r2]=min(dp[l1][r1][l2][r2],
                                    dp[l1][r1][l2][p-1]+dp[l1][p+1][l2][r2]);
            ///cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<"  "<<dp[l1][r1][l2][r2]<<endl;
        }
    cout<<dp[1][1][n][n]<<"\n";
}