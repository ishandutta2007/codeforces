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
    const int N=1e6+10,mod=1e9+7,inv2=5e8+4,inf=2e9;
    const double pi=acos(-1.0);
    int n,m;
    int a[N],s[N];
    bool vis[10];
    inline bool dfs(int now,int sum,int lim)
    {
        if(now>lim)
        {
            if(sum==0)
            {
                for(int i=1;i<=lim;++i) cout<<a[i];
                cout<<'\n';
                return 1;
            }
            return 0;
        }
        for(int x=1;x<=9&&x<=sum;++x)
        {
            if(!vis[x])
            {
                vis[x]=1;
                a[now]=x;
                if(dfs(now+1,sum-x,lim)) return 1;
                vis[x]=0;
            }
        }
        return 0;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int qwq;cin>>qwq;
        while(qwq--)
        {
            cin>>m;
            for(int i=1;i<=9;++i) vis[i]=0;
            for(int i=1;i<=9;++i)
            {
                if(dfs(1,m,i)) break;
            }
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
7 2 4 12
7 -5 2 8
7 -5 8 2
*/