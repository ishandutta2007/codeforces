# include <iostream>
using namespace std;
long long dp[2][4];
#define A 0
#define B 1
#define C 2
#define D 3
int main()
{
    int n;
    cin>>n;
    dp[0][D]=1;
    for (int i=0;i<n;i++)
    {
        dp[1][D]=(dp[0][C]+dp[0][B]+dp[0][A])%1000000007;
        dp[1][C]=(dp[0][D]+dp[0][B]+dp[0][A])%1000000007;
        dp[1][B]=(dp[0][C]+dp[0][D]+dp[0][A])%1000000007;
        dp[1][A]=(dp[0][C]+dp[0][B]+dp[0][D])%1000000007;
        dp[0][A]=dp[1][A];
        dp[0][B]=dp[1][B];
        dp[0][C]=dp[1][C];
        dp[0][D]=dp[1][D];
    }
    cout<<dp[0][D]<<endl;
}