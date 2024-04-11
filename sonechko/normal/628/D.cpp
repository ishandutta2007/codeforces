#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2000 + 11;
const int MOD = 1e9 + 7;

int dp[N][2][2][N];
int m,d;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>m>>d;
    string s1,s2;
    cin>>s1>>s2;
    s1="."+s1;
    s2="."+s2;
    dp[0][0][0][0]=1;
    int n=s1.size()-1;
    for (int i=1; i<=n; i++)
    for (int d1=0; d1<=1; d1++)
    for (int d2=0; d2<=1; d2++)
    for (int mm=0; mm<m; mm++)
    {
        for (int x=0; x<=9; x++)
        {
            if (d1==0&&x<s1[i]-'0') continue;
            if (d2==0&&x>s2[i]-'0') continue;
            if (i%2==1&&x==d) continue;
            if (i%2==0&&x!=d) continue;
            int dd1=d1,dd2=d2,mmm=(mm*10+x)%m;
            if (x>s1[i]-'0') dd1=1;
            if (x<s2[i]-'0') dd2=1;
            dp[i][dd1][dd2][mmm]=(dp[i][dd1][dd2][mmm]+dp[i-1][d1][d2][mm])%MOD;
        }
    }
    int ans=0;
    for (int d1=0; d1<=1; d1++)
    for (int d2=0; d2<=1; d2++)
        ans=(ans+dp[n][d1][d2][0])%MOD;
    cout<<ans;
}