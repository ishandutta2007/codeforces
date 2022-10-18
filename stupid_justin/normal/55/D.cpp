#include <bits/stdc++.h>
using namespace std;
int digit[20],h[2521],cnt;
long long dp[20][2521][50];

int gcd(int a,int b)
{
    if (a%b==0) return b;
    return gcd(b,a%b);
}
int lcm(int a,int b)
{
    if (a==0) return b;
    else return (a*b)/gcd(a,b);
}
long long dfs(int len,int pre,int mod,int limit)
{
    if(len==0) return pre%mod==0;
    if(limit==0 && dp[len][pre][h[mod]]!=-1) return dp[len][pre][h[mod]];
    long long ret=0;
    int ends=9;
    if (limit) ends=digit[len];
    for(int i=0;i<=ends;i++)
    {
        if(i==ends && limit) ret+=dfs(len-1,(pre*10+i)%2520,lcm(i,mod),1);
        else ret+=dfs(len-1,(pre*10+i)%2520,lcm(i,mod),0);
    }
    if(!limit) dp[len][pre][h[mod]]=ret;
    return ret;
}

long long solve(long long n)
{
    int len=0;
    while(n)
    {
        digit[++len]=n%10;
        n/=10;
    }
    return dfs(len,0,1,1);
}

signed main()
{
	memset(dp,-1,sizeof(dp));
    for(int i=1;i<=2520;i++) if(2520%i==0) h[i]=++cnt;
    int T;
    cin>>T;
    while(T--)
    {
        long long l,r;
        cin>>l>>r;
        cout<<solve(r)-solve(l-1)<<endl;
    }
}