#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-15)
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e18;
    void __init(int n=2000) {}
    inline void main()
    {
        string s;cin>>s;
        int n=s.length();
        vector dp(n+1,vector<int>(n+1));
        for(int i=0;i<n-1;++i)
        {
            if(s[i]!=s[i+1]) dp[i+1][i+2]=1;
        }
        for(int len=4;len<=n;len+=2)
        {
            for(int l=1,r=len;r<=n;++l,++r)
            {
                //
                bool f1=(dp[l+2][r]==1||(dp[l+2][r]==0&&s[l-1]<s[l+1-1]));
                bool f2=(dp[l+1][r-1]==1||(dp[l+1][r-1]==0&&s[l-1]<s[r-1]));
                if(f1&&f2) dp[l][r]=1;
                //
                f1=(dp[l][r-2]==1||(dp[l][r-2]==0&&s[r-1]<s[r-1-1]));
                f2=(dp[l+1][r-1]==1||(dp[l+1][r-1]==0&&s[r-1]<s[l-1]));
                if(f1&&f2) dp[l][r]=1;
            }
        }
        if(dp[1][n]==1) cout<<"Alice\n";
        else cout<<"Draw\n";
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::__init();
    int qwq=1; cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*
abbaab

*/