#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,inf=1e15,mod=1e9+7;
    int n,sum;
    int a[N],b[N];
    map<int,int> cnt;
    int tot;
    map<int,bool> vis;
    inline bool dfs(int x)
    {
        if(!x) return 1;
        if(cnt[x])
        {
            --cnt[x];
            ++tot;
            return 0;
        }
        if(vis[x]) return 1;
        bool flag=0;
        flag|=dfs(x/2);
        if(flag)
        {
            vis[x]=1;
            return 1;
        }
        flag|=dfs((x+1)/2);
        if(flag) vis[x]=1;
        return vis[x];
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;
            sum=0;
            cnt.clear();tot=0;
            vis.clear();
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
                sum+=a[i];
                ++cnt[a[i]];
            }
            dfs(sum);
            if(tot==n) cout<<"YES\n";
            else cout<<"NO\n";
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
8
2 16 1 8 64 1 4 32

*/