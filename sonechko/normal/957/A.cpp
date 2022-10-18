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

const int N = 100 + 11;

int dp[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    s="."+s;
    dp[0][0]=1;
    for (int i=1; i<=n; i++)
    {
        int l1=1,r1=3;
        if (s[i]=='C') {l1=1; r1=1;}
        if (s[i]=='Y') {l1=2; r1=2;}
        if (s[i]=='M') {l1=3; r1=3;}
        for (int c=l1; c<=r1; c++)
        for (int j=0; j<=3; j++)
            if (c!=j) dp[i][c]=min(5,dp[i][c]+dp[i-1][j]);
    }
    int p=dp[n][1]+dp[n][2]+dp[n][3];
    if (p>1) cout<<"Yes"<<endl; else cout<<"No"<<endl;
}