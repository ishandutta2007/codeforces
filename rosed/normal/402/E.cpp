#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=1e5+10,inf=2e9;
    int n;
    int a[2010][2010];
    vector<int> eg[N];
    int dfn[N],low[N],idx,sum;
    int st[N],top;
    bool vis[N];
    inline void tarjan(int now)
    {
        dfn[now]=low[now]=++idx;
        st[++top]=now;
        for(int t:eg[now])
        {
            if(!dfn[t])
            {
                tarjan(t);
                low[now]=min(low[now],low[t]);
            }
            else if(!vis[t])
            {
                low[now]=min(low[now],dfn[t]);
            }
        }
        if(dfn[now]==low[now])
        {
            ++sum;
            while(st[top]!=now) vis[st[top--]]=1;
            vis[st[top--]]=1;
        }
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                cin>>a[i][j];
                if(a[i][j]>0&&i!=j) eg[i].push_back(j);
            }
        }
        for(int i=1;i<=n;++i)
        {
            if(!dfn[i]) tarjan(i);
        }
        if(sum==1) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
signed main()
{
    red::main();
    return 0;   
}
/*
1 0 1
1 1 0
1 1 1

*/