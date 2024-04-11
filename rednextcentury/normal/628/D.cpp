#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007LL
long long dp[2001][2001][2];
bool vis[2001][2001][2];
int m,d;
string s;
int n;
long long DP(int i,int rem,bool pre)
{
    if (i==n)
    {
        if (rem==0)
            return 1;
        return 0;
    }
    if (vis[i][rem][pre])
        return dp[i][rem][pre];
    vis[i][rem][pre]=1;
    long long ret=0;
    if (i%2==0)
    {
        for (int j=0; j<=9; j++)
        {
            if (pre && j>s[i]-'0')
                break;
            if (j==d)continue;
            if (j<s[i]-'0')
                ret+=DP(i+1,(rem*10+j)%m,0);
            else
                ret+=DP(i+1,(rem*10+j)%m,pre);
            ret%=MOD;
        }
    }
    else
    {
        if (pre && d>s[i]-'0')
            ;
        else
        {


            if (d<s[i]-'0')
                ret+=DP(i+1,(rem*10+d)%m,0);
            else
                ret+=DP(i+1,(rem*10+d)%m,pre);
            ret%=MOD;
        }
    }
    return dp[i][rem][pre]=ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>m>>d;
    string a,b;
    cin>>a>>b;
    s=b;
    n=s.length();
    long long ans=DP(0,0,1);
    memset(vis,0,sizeof(vis));
    if (a=="0")
    {
        cout<<ans<<endl;
    }
    else
    {
        s=a;
        int j=s.size()-1;
        while(s[j]=='0')
            j--;
        s[j]--;
        for (j=j+1; j<s.size(); j++)
            s[j]='9';
        n=s.length();
        ans=(ans-DP(0,0,1)+MOD)%MOD;
        cout<<ans<<endl;
    }
}