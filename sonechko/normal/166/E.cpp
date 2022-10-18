#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ss second
#define ff first
#define pb push_back
#define mp make_pair
#define y1 kdnfskefn
#define sqr(a) ((a)*(a))
const int N = 1e7 + 11;
///-----------------------------------------------------------
int dp[N];
///-----------------------------------------------------------
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    dp[1]=0;
    int n;
    cin>>n;
    for (int i=2; i<=n; i++)
    {
        dp[i]=(dp[i-1]+dp[i-1])%1000000007;
        dp[i]=(dp[i]+dp[i-1])%1000000007;
        if (i%2==0) dp[i]+=3; else dp[i]=dp[i]+1000000007-3;
        dp[i]%=1000000007;
    }
    cout<<dp[n]<<endl;
}