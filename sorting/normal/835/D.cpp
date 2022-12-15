#include<iostream>

using namespace std;

string s;
int dp[5001][5001],n;
bool b[5001][5001];
int res[5001];

int solve(int l,int r)
{
    if(b[l][r]==1)return dp[l][r];
    b[l][r]=1;

    if(s[l]!=s[r])return dp[l][r]=0;
    if(solve(l+1,r-1)==0)return dp[l][r]=0;

    dp[l][r]=solve(l,(l+r)/2-(1-(l+r)%2))+1;

    return dp[l][r];
}

int main ()
{
    int i,j;

    ios::sync_with_stdio(false);

    cin>>s;

    n=s.size();

    for(i=0;i<n;i++)
    {
        b[i][i]=1;
        dp[i][i]=1;
        res[1]++;
    }

    for(i=0;i<n-1;i++)
    {
        if(s[i]==s[i+1])
        {
            b[i][i+1]=1;
            dp[i][i+1]=2;
            res[2]++;
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=i+2;j<n;j++)
        {
            //cout<<solve(i,j)<<endl;
            res[solve(i,j)]++;
        }
    }
    for(i=n-1;i>=1;i--)res[i]+=res[i+1];
    for(i=1;i<n;i++)cout<<res[i]<<" ";
    cout<<res[n]<<endl;

    return 0;
}