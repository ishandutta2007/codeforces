#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=5e5+10,mod=998244353,inf=2e9;
    int n;
    int a[N],p[N],c[N];
    bool vis[N];
    int ans;
    int st[N],top;
    inline void dfs(int now)
    {
        if(vis[now]) return;
        st[++top]=now;
        vis[now]=1;
        dfs(p[now]);
    }
    bool g[N];
    inline bool check(int x)
    {
        for(int i=1;i<=x;++i)
        {
            bool flag=1;
            for(int j=i;j<=top;j+=x)
            {
                flag&=(c[st[i]]==c[st[j]]);
            }
            if(flag) return 1;
        }
        return 0;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;ans=n;
            for(int i=1;i<=n;++i)
            {
                cin>>p[i];  
                vis[i]=0;
            }
            for(int i=1;i<=n;++i) cin>>c[i];
            for(int i=1;i<=n;++i)if(!vis[i])
            {
                top=0;
                dfs(i);
                int flag=n;
                for(int x=1;x*x<=top;++x)
                {
                    if(top%x==0)
                    {
                        if(check(x)) flag=min(flag,x);
                        if(check(top/x)) flag=min(flag,top/x);
                    }
                }
                ans=min(ans,flag);
            }
            cout<<ans<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
1
6
001010100100
001100001011
000010010000


*/