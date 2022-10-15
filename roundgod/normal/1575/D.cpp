#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,dp[10][25][11][2];
string str;
int solve(int now,int mod,int x,int zero)
{
    if(now==n) return (mod==0?1:0);
    if(dp[now][mod][x][zero]!=-1) return dp[now][mod][x][zero];
    int res=0;
    if(str[now]>='0'&&str[now]<='9') 
    {
        if(zero&&str[now]=='0') return 0;
        res=solve(now+1,(mod*10+str[now]-'0')%25,x,0);
    }
    else if(str[now]=='_')
    {
        for(int i=0;i<=9;i++)
        {
            if(zero&&i==0) continue;
            res+=solve(now+1,(mod*10+i)%25,x,0);
        }
    }
    else
    {
        if(x!=10) res=solve(now+1,(mod*10+x)%25,x,0);
        else
        {
            for(int i=0;i<=9;i++)
            {
                if(zero&&i==0) continue;
                res+=solve(now+1,(mod*10+i)%25,i,0);
            }
        }
    }
    return dp[now][mod][x][zero]=res;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>str;
    n=(int)str.size();
    if(n==1)
    {
        if(str=="0"||str=="_"||str=="X") puts("1"); else puts("0");
        return 0;
    }
    printf("%d\n",solve(0,0,10,1));
}