#include<bits/stdc++.h>
using namespace std;
namespace red{
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-15)
    const int N=3e5+10,mod=1e9+7,inv2=5e8+4,inf=2e15;
    void __init(int n=2000) {}
    int son[N*31][2];
    int f[N*31][2];
    inline void main()
    {
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> dp(n);
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        int ans=0;
        // vector son(n*31,vector<int>(2,0));
        // vector f(n*31,vector<int>(2,0));
        int tot=0;
        auto insert=[&](int x,int i,int val) -> void
        {
            int now=0;
            for(int k=29;k>=0;--k)
            {
                int b=(x>>k)&1;
                if(!son[now][b]) son[now][b]=++tot;
                now=son[now][b];
                int &ret=f[now][i>>k&1];
                ret=max(ret,val);
            }
        };
        auto query=[&](int x,int i) -> int
        {
            int now=0,ret=0;
            for(int k=29;k>=0;--k)
            {
                int b=(x>>k)&1;
                ret=max(ret,f[son[now][!b]][!((x^i)>>k&1)]);
                now=son[now][b];
                if(!now) return ret;
            }
            return ret;
        };
        for(int i=0;i<n;++i)
        {
            dp[i]=query(a[i]^i,i)+1;
            ans=max(ans,dp[i]);
            insert(a[i]^i,i,dp[i]); 
            //cout<<dp[i]<<'\n';
        }
        cout<<ans<<'\n';
        for(int i=0;i<=tot;++i) son[i][0]=son[i][1]=f[i][0]=f[i][1]=0;
        //cout<<"----------\n";
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