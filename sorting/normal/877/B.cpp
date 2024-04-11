#include<iostream>

using namespace std;

string s;
int l;

int dp[5001][4];
bool b[5001][4];

int solve(int pos,int st)
{
    if(pos==l)return 0;
    if(b[pos][st]==1)return dp[pos][st];
    b[pos][st]=1;

    if(st==0)
    {
        if(s[pos]=='a')dp[pos][st]=1+solve(pos+1,st);
        else
        {
            dp[pos][st]=max(1+solve(pos+1,st+1),solve(pos+1,st));
        }
    }
    else
    {
        if(st==1)
        {
            if(s[pos]=='a')dp[pos][st]=max(1+solve(pos+1,st+1),solve(pos+1,st));
            else
            {
                dp[pos][st]=1+solve(pos+1,st);
            }
        }
        else
        {
            if(s[pos]=='a')dp[pos][st]=1+solve(pos+1,st);
            else dp[pos][st]=solve(pos+1,st);
        }
    }
    return dp[pos][st];
}

int main ()
{
    cin>>s;

    l=s.size();

    cout<<solve(0,0)<<endl;

    return 0;
}