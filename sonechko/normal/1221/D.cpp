#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long

const int N = 3e5 + 11;

int a[N];
ll b[N];
ll dp[N][3];

void up()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i]>>b[i];
    dp[1][0]=0;
    dp[1][1]=b[1];
    dp[1][2]=b[1]*2;
    for (int i=2; i<=n; i++)
    for (int d=0; d<=2; d++)
    {
        dp[i][d]=2e18;
        for (int t=0; t<=2; t++)
            if (a[i]+d!=a[i-1]+t) dp[i][d]=min(dp[i][d],dp[i-1][t]+b[i]*1ll*d);
    }
    cout<<min(dp[n][0],min(dp[n][1],dp[n][2]))<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    for (int i=1; i<=q; i++)
        up();
}
/**
B.B.B.......
..WBW.......
BW.WB.......
.B.B........
B.B.........
............
............
............
............
............
............
............



**/