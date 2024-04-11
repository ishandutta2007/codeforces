#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2000 + 11;
const int MOD = 1e9 + 7;

int dp[N][N][2][2];
int ans;

void up(string s, int n, int c)
{
    ///cout<<s<<" "<<n<<" "<<c<<endl;
    for (int i=0; i<=n+1; i++)
    for (int j=0; j<=n+1; j++)
    for (int p=0; p<=1; p++)
    for (int d=0; d<=1; d++)
        dp[i][j][p][d]=0;
    dp[n+1][0][0][1]=1;
    for (int i=n; i>=1; i--)
    for (int j=0; j<=n; j++)
    for (int p=0; p<=1; p++)
    for (int d=0; d<=1; d++)
    {
        for (int x=0; x<=9; x++)
        {
            int dd=d;
            if (x<s[i]-'0') dd=1;
            if (x>s[i]-'0') dd=0;
            if (x<c||(x==c&&p==1)) dp[i][j][p][dd]=(dp[i][j][p][dd]+dp[i+1][j][p][d])%MOD;
            if (x>c) dp[i][j+1][p][dd]=(dp[i][j+1][p][dd]+dp[i+1][j][p][d])%MOD;
            if (x==c&&p==0)
            {
                dp[i][j][1][dd]=(dp[i][j][1][dd]+dp[i+1][j][p][d])%MOD;
                dp[i][j+1][0][dd]=(dp[i][j+1][0][dd]+dp[i+1][j][p][d])%MOD;
            }
        }
    }
    ll st=1;
    for (int j=0; j<n; j++)
    {
        ///cout<<dp[1][j][1][1]<<endl;
        ans=(ans*1ll+dp[1][j][1][1]*1ll*c*1ll*st)%MOD;
        st=(st*10ll)%MOD;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    s="."+s;
    int n=s.size()-1;
    for (int c=1; c<=9; c++)
        up(s,n,c);
    cout<<ans;
}