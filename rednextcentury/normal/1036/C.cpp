#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
long long dp[20][4][2];
int n;
int a[1000];
long long solve(int i,int j,int eq)
{
    if (j>3)return 0;
    if (i==n)
        return 1;
    if (dp[i][j][eq]!=-1)
        return dp[i][j][eq];
    long long &ret=dp[i][j][eq];
    ret=0;
    if (eq)
    {
        ret=solve(i+1,j+(a[i]!=0),eq);
        for (int x=0;x<a[i];x++)
        {
            //if (x==0 && i==0)continue;
            ret+=solve(i+1,j+(x!=0),0);
        }
    }
    else
    {
        for (int x=0;x<10;x++)
        {
            //if (x==0 && i==0)continue;
            ret+=solve(i+1,j+(x!=0),0);
        }
    }
    return ret;
}
long long get(long long x)
{
    if (x==0)return 1;
    n=0;
    while(x)
    {
        a[n++]=x%10;
        x/=10;
    }
    reverse(a,a+n);
    memset(dp,-1,sizeof(dp));
    return solve(0,0,1);
}
int main ()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long l,r;
        cin>>l>>r;
        long long ret = get(r)-get(l-1);
        cout<<ret<<endl;
    }
}