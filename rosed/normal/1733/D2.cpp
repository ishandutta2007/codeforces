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
        int n,x,y;
        cin>>n>>x>>y;
        string s,t;
        cin>>s>>t;
        int sum=0;
        for(int i=0;i<n;++i) sum+=(s[i]-'0');
        for(int i=0;i<n;++i) sum-=(t[i]-'0');
        if(sum&1)
        {
            cout<<"-1\n";return;
        }
        vector<int> pos;
        for(int i=0;i<n;++i)
        {
            if(s[i]!=t[i]) pos.emplace_back(i);
        }
        if(x>=y)
        {
            if(pos.size()==2&&pos[0]+1==pos[1])
            {
                cout<<min(x,2*y)<<'\n';
            }
            else cout<<y*(pos.size()/2)<<'\n';
            return;
        }
        else
        {
            int t=y/x;
            int cnt=pos.size();
            pos.insert(pos.begin(),0);
            vector dp(n+1,vector<int>(n+1,inf));
            dp[0][0]=0;
            for(int i=1;i<=cnt;++i)
            {
                for(int j=0;j<=cnt;++j)
                {
                    if(j>0) dp[i][j]=min(dp[i][j],dp[i-1][j-1]+y);
                    if(j<cnt) dp[i][j]=min(dp[i][j],dp[i-1][j+1]);
                    if(i>=2) dp[i][j]=min(dp[i][j],dp[i-2][j]+(pos[i]-pos[i-1])*x);
                }
            }
            cout<<dp[cnt][0]<<'\n';
        }
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


*/