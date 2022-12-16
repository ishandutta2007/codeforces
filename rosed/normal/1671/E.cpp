#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-15)
    const int N=1e6+10,mod=998244353,inf=2e9;
    int n,m;
    char s[N];
    string str[N];
    int dp[N];
    inline void dfs(int now)
    {
        if(now*2>=(1<<n))
        {
            dp[now]=1;
            str[now]=s[now];
            //cout<<now<<' '<<s[now]<<' '<<dp[now]<<"!!"<<endl;
            return;
        }
        dfs(now<<1);
        dfs(now<<1|1);
        string t1=str[now<<1],t2=str[now<<1|1];
        int f1=dp[now<<1],f2=dp[now<<1|1];
        if(t1==t2) dp[now]=f1*f2%mod;
        else dp[now]=f1*f2%mod*2%mod;
        if(t1<t2) str[now]=t1+s[now]+t2;
        else str[now]=t2+s[now]+t1;
        //cout<<now<<' '<<str[now]<<' '<<dp[now]<<"!!"<<endl;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);          
        cin>>n;
        cin>>(s+1);
        dfs(1);
        cout<<dp[1]<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
1
1 2 3 4

*/