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
    const int N=1e6+10,mod=998244353,inv2=499122177,inf=2e18;
    void __init(int n=2000) {}
    
    inline void main()
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > eg(n+1);
        vector<int> sg(n+1,-1);
        for(int i=1;i<=m;++i)
        {
            int x,y;cin>>x>>y;
            eg[x].emplace_back(y);
        }
        auto fast=[&](int x,int k) -> int
        {
            int ret=1;
            while(k)
            {
                if(k&1) ret=ret*x%mod;
                x=x*x%mod;
                k>>=1;
            }
            return ret;
        };
        function<void(int)> dfs=[&](int now) -> void
        {
            if(~sg[now]) return;
            vector<bool> vis(520);
            for(int t:eg[now])
            {
                dfs(t);
                vis[sg[t]]=1;
            }
            for(int i=0;;++i)
            {
                if(!vis[i])
                {
                    sg[now]=i;break;
                }
            }
        };
        vector<int> a(512);
        for(int i=1;i<=n;++i)
        {
            dfs(i);
            ++a[sg[i]];
        }
        auto fwt=[&](auto &a,int inv) -> void
        {
            for(int k=1;2*k<=512;k<<=1)
            {
                for(int i=0;i<512;i+=2*k)
                {
                    for(int j=0;j<k;++j)
                    {
                        int x=a[i+j],y=a[i+j+k];
                        a[i+j]=inv*(x+y)%mod;
                        a[i+j+k]=inv*(x-y+mod)%mod;
                    }
                }
            }
        };
        fwt(a,1);
        vector<int> b(512);
        for(int i=0;i<512;++i)
        {
            b[i]=fast(n+1-a[i]+mod,mod-2);
        }
        fwt(b,inv2);
        cout<<(1-b[0]+mod)%mod<<'\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::__init();
    int qwq=1; //cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*

*/