#include <bits/stdc++.h>
using namespace std;
int dp[201][201][201];
bool can[1000];
int sol(int i,int j,int k)
{
    if (dp[i][j][k]!=-1)return dp[i][j][k];
    if (i+j+k==1)
    {
        if (i)can['R']=1;
        if (j)can['G']=1;
        if (k)can['B']=1;
        return dp[i][j][k]=1;
    }
    dp[i][j][k]=0;
    if (i && j)dp[i][j][k]|=sol(i-1,j-1,k+1);
    if (i && k)dp[i][j][k]|=sol(i-1,j+1,k-1);
    if (j && k)dp[i][j][k]|=sol(i+1,j-1,k-1);
    if (i>1)dp[i][j][k]|=sol(i-1,j,k);
    if (j>1)dp[i][j][k]|=sol(i,j-1,k);
    if (k>1)dp[i][j][k]|=sol(i,j,k-1);
    return dp[i][j][k];
}
int main()
{
    int n;
    string s;
    int R=0,G=0,B=0;
    cin>>n>>s;
    for (auto x:s)
    {
        if (x=='R')R++;
        if (x=='G')G++;
        if (x=='B')B++;
    }
    memset(dp,-1,sizeof(dp));
    sol(R,G,B);
    string ret="";
    if (can['B'])ret+="B";
    if (can['G'])ret+="G";
    if (can['R'])ret+="R";
    cout<<ret<<endl;

}