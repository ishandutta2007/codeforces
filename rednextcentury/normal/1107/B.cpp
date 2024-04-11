#include <bits/stdc++.h>
using namespace std;
long long dp[101][101*9][10];
int val[10001];
long long Get(int i,int j,int x)
{
    if (i==18)
        return val[j]==x;
    if (dp[i][j][x]!=-1)return dp[i][j][x];
    long long &ret = dp[i][j][x];
    ret=0;
    for (int k=0;k<10;k++)
        ret+=Get(i+1,(j+k),x);
    return ret;
}
long long K;
long long ret=0;
void getPath(int i,int j,int x)
{
    if (i==18)return;
    for (int k=0;k<10;k++)
    {
        if (Get(i+1,j+k,x)>=K){
            ret=ret*10+k,getPath(i+1,j+k,x);
            return;
        }
        else
            K-=Get(i+1,j+k,x);
    }
}
int sum(int v)
{
    int r=0;
    while(v)
    {
        r+=v%10;
        v/=10;
    }
    return r;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    memset(dp,-1,sizeof(dp));
    for (int i=1;i<=10000;i++)
    {
        int v = i;
        while(v>=10)v=sum(v);
        val[i]=v;
    }
    while(t--)
    {
        int x;
        cin>>K>>x;
        ret=0;
        getPath(0,0,x);
        cout<<ret<<endl;
    }
}