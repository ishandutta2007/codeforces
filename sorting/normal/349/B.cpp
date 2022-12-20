#include<iostream>
#define mini -1000000

using namespace std;

int a[10];
int dp[1000001],dig[1000001];
bool b[1000001];

int solve(int v)
{
    if(v<0)return mini;
    if(b[v])return dp[v];

    int i,p;

    b[v]=1;

    dp[v]=mini;

    for(i=9;i>=1;i--)
    {
        p=solve(v-a[i]);
        if(p>dp[v])
        {
            dig[v]=i;
            dp[v]=solve(v-a[i]);
        }
    }

    dp[v]++;

    return dp[v];
}

int main ()
{
    int v,i;
    bool x=false;

    cin>>v;

    for(i=1;i<=9;i++)cin>>a[i];

    solve(v);

    while(dig[v]>0)
    {
        if(x==true)
        {
            cout<<dig[v];
        }
        else
        {
            x=true;
            cout<<dig[v];
        }
        v-=a[dig[v]];
    }

    if(x==true)cout<<endl;
    else cout<<"-1"<<endl;

    return 0;
}