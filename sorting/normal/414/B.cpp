#include<iostream>
#define endl "\n"
#define M 1000000007

using namespace std;

int n;
long long dp[2001][2001];
bool b[2001][2001];

long long solve(long long pr,long left)
{
    if(left==0)return 1;
    if(b[pr][left]==1)return dp[pr][left];
    int i;

    b[pr][left]=1;

    for(i=pr;i<=n;i+=pr)
    {
        dp[pr][left]+=solve(i,left-1);
        if(dp[pr][left]>=M)dp[pr][left]-=M;
    }

    return dp[pr][left];
}

int main ()
{
    int k;

    ios::sync_with_stdio(false);

    cin>>n>>k;

    cout<<solve(1,k)<<endl;

    return 0;
}