#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define ld long double

const int N = 1500 + 11;
const ll MOD = 1e18;
#define mod %MOD

int dp[27][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    s='.'+s;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=26; j++)
    {
        int kol=0;
        for (int k=i; k<=n; k++)
        {
            int p=s[k]-'a'+1;
            if (p!=j) kol++;
            dp[j][kol]=max(dp[j][kol],k-i+1);
        }
    }
    int m;
    cin>>m;
    for (int i=1; i<=26; i++)
    for (int j=1; j<=n; j++)
    dp[i][j]=max(dp[i][j],dp[i][j-1]);
    for (int i=1; i<=m; i++)
    {
        int p;
        char h;
        cin>>p>>h;
        int d=h-'a'+1;
        cout<<dp[d][p]<<"\n";
    }
}