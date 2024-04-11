#include<iostream>

using namespace std;

string s[2];
int dp[101][5];
bool b[101][5];

int solve(int pos,int pr)
{
    if(pos==s[0].size())
        return 0;

    if(b[pos][pr])
        return dp[pos][pr];

    b[pos][pr]=1;

    int x=0;

    if(s[0][pos]=='X')
        x+=2;
    if(s[1][pos]=='X')
        x++;

    dp[pos][pr]=0;

    if(pr==3)
    {
        dp[pos][pr]=solve(pos+1,x);
        return dp[pos][pr];
    }
    if(pr==2)
    {
        if(x==0)
            dp[pos][pr]=solve(pos+1,3)+1;
        dp[pos][pr]=max(dp[pos][pr],solve(pos+1,x));

        return dp[pos][pr];
    }
    if(pr==1)
    {
        if(x==0)
            dp[pos][pr]=solve(pos+1,3)+1;
        dp[pos][pr]=max(dp[pos][pr],solve(pos+1,x));

        return dp[pos][pr];
    }

    if(x==0)
        dp[pos][pr]=max(solve(pos+1,2),solve(pos+1,1))+1;
    if(x==1)
        dp[pos][pr]=solve(pos+1,3)+1;
    if(x==2)
        dp[pos][pr]=solve(pos+1,3)+1;

    dp[pos][pr]=max(dp[pos][pr],solve(pos+1,x));

    return dp[pos][pr];
}

int main ()
{
    ios::sync_with_stdio(false);

    cin>>s[0]>>s[1];

    cout<<solve(0,3)<<"\n";

    return 0;
}