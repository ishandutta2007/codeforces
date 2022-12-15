#include<iostream>

using namespace std;

#define N 3007
const int maxi=300000001;

int dp[N][N][4];
bool b[N][N][4];
int n;

int c[N];
int s[N];

int solve(int pos,int pr,int left)
{
    if(left==0)
        return 0;
    if(pos==n+1)
        return maxi;
    if(b[pos][pr][left])
        return dp[pos][pr][left];

    b[pos][pr][left]=1;

    int num;

    dp[pos][pr][left]=maxi;

    if(pr==0)
        num=0;
    else
        num=s[pr];

    if(s[pos]>s[pr])
        dp[pos][pr][left]=min(dp[pos][pr][left],solve(pos+1,pos,left-1)+c[pos]);

    dp[pos][pr][left]=min(dp[pos][pr][left],solve(pos+1,pr,left));

    return dp[pos][pr][left];
}

int main ()
{
    int i,res;

    cin>>n;

    for(i=1;i<=n;i++)
        cin>>s[i];
    for(i=1;i<=n;i++)
        cin>>c[i];

    res=solve(1,0,3);

    if(res>=maxi)
        cout<<"-1"<<endl;
    else
        cout<<res<<endl;

    return 0;
}