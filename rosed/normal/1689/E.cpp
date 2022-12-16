#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,mod=998244353,inf=2e9;
    int n;
    int a[N];
    vector<int> eg[N];
    bool vis[N];
    inline void dfs(int now)
    {
        vis[now]=1;
        for(int t:eg[now])
        {
            if(vis[t]) continue;
            dfs(t);
        }
    }
    inline bool check()
    {
        int m=0;
        for(int i=1;i<=n;++i) m|=a[i];
        for(int i=0;i<30;++i) eg[i].clear(),vis[i]=0;
        for(int i=1;i<=n;++i)
        {
            int x=a[i],pre=-1;
            for(int k=0;k<30;++k) if((x>>k)&1)
            {
                if(~pre) eg[pre].emplace_back(k),eg[k].emplace_back(pre);
                pre=k;
            }
        }
        for(int i=0;i<30;++i) if((m>>i)&1)
        {
            dfs(i);break;
        }
        for(int i=0;i<30;++i) if((m>>i)&1)
        {
            if(!vis[i]) return 0;
        }
        return 1;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int skx;
        cin>>skx;
        while(skx--)
        {
            cin>>n;
            int ans=0;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
                if(!a[i]) a[i]=1,++ans;
            }
            if(check())
            {
                cout<<ans<<'\n';
                for(int i=1;i<=n;++i) cout<<a[i]<<" \n"[i==n];
                continue;
            }
            bool flag=0;
            for(int i=1;i<=n;++i)
            {
                --a[i];
                ++ans;
                if(a[i]>0&&check())
                {
                    cout<<ans<<'\n';
                    for(int i=1;i<=n;++i) cout<<a[i]<<" \n"[i==n];
                    flag=1;
                    break;
                }
                ++a[i];
                ++a[i];
                if(check())
                {
                    cout<<ans<<'\n';
                    for(int i=1;i<=n;++i) cout<<a[i]<<" \n"[i==n];
                    flag=1;
                    break;
                }
                --ans;
                --a[i];
            }
            if(flag) continue;
            int maxn=0,pos=0;
            for(int i=1;i<=n;++i)
            {
                if(lowbit(a[i])>maxn) maxn=lowbit(a[i]),pos=i;
            }
            --a[pos];
            maxn=0,pos=0;
            for(int i=1;i<=n;++i)
            {
                if(lowbit(a[i])>maxn) maxn=lowbit(a[i]),pos=i;
            }
            ++a[pos];
            cout<<ans+2<<'\n';
            for(int i=1;i<=n;++i) cout<<a[i]<<" \n"[i==n];
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
4
1 2 2 2


1
2
3 12


*/