#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define ld long double
#define mp make_pair
#define pb push_back

const int N = 200 + 11;
const int MOD = 998244353;

int dp[201][201][7][7];
vector<pair<int,int> > v[201][201][7][7];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    dp[0][0][0][0]=1;
    for (int sum=0; sum<=4; sum++)
    for (int l=0; l<=sum; l++)
    for (int i=0; i<=200; i++)
    for (int j=0; j<=200; j++)
    {
        int r=sum-l;
        if (dp[i][j][l][r]==0) continue;
        if (max(l,r)>=3) continue;

        int t=25;
        if (sum==4) t=15;

        for (int x=t; x<=200; x++)
        {
            if (i+x<=200&&j+x-2<=200&&dp[i+x][j+x-2][l+1][r]==0)
            {
                dp[i+x][j+x-2][l+1][r]=1;
                v[i+x][j+x-2][l+1][r]=v[i][j][l][r];
                v[i+x][j+x-2][l+1][r].pb(mp(x,x-2));
            }
            if (i+x-2<=200&&j+x<=200&&dp[i+x-2][j+x][l][r+1]==0)
            {
                dp[i+x-2][j+x][l][r+1]=1;
                v[i+x-2][j+x][l][r+1]=v[i][j][l][r];
                v[i+x-2][j+x][l][r+1].pb(mp(x-2,x));
            }
        }

        for (int y=0; y<=t-2; y++)
        {
            if (i+t<=200&&j+y<=200&&dp[i+t][j+y][l+1][r]==0)
            {
                dp[i+t][j+y][l+1][r]=1;
                v[i+t][j+y][l+1][r]=v[i][j][l][r];
                v[i+t][j+y][l+1][r].pb(mp(t,y));
            }
            if (i+y<=200&&j+t<=200&&dp[i+y][j+t][l][r+1]==0)
            {
                dp[i+y][j+t][l][r+1]=1;
                v[i+y][j+t][l][r+1]=v[i][j][l][r];
                v[i+y][j+t][l][r+1].pb(mp(y,t));
            }
        }
    }

    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int l,r;
        cin>>l>>r;
        int l1=-1,r1=-1;
        if (dp[l][r][3][0]==1) {l1=3; r1=0;} else
        if (dp[l][r][3][1]==1) {l1=3; r1=1;} else
        if (dp[l][r][3][2]==1) {l1=3; r1=2;} else
        if (dp[l][r][2][3]==1) {l1=2; r1=3;} else
        if (dp[l][r][1][3]==1) {l1=1; r1=3;} else
        if (dp[l][r][0][3]==1) {l1=0; r1=3;}
        if (l1==-1) {cout<<"Impossible"<<"\n";} else
        {
            cout<<l1<<":"<<r1<<"\n";
            for (int j=0; j<v[l][r][l1][r1].size(); j++)
                cout<<v[l][r][l1][r1][j].ff<<":"<<v[l][r][l1][r1][j].ss<<" ";
            cout<<"\n";
        }
    }
}