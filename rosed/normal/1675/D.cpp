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
    const int N=5e5+10,mod=1e9+7,inf=2e9;
    int n,rt;
    vector<int> eg[N];
    vector<int> ans[N];
    int top;
    int str[N],son[N];
    inline void init()
    {
        rt=1;
        for(int i=1;i<=n;++i)
        {
            eg[i].clear();
            str[i]=son[i]=0;
        }
        for(int i=1;i<=top;++i) ans[i].clear();
        top=0;
    }
    inline void dfs(int now,int fa)
    {
        str[now]=1;
        for(int t:eg[now])
        {
            if(t==fa) continue;
            dfs(t,now);
            str[now]+=str[t];
            if(str[t]>str[son[now]]) son[now]=t;
        }
    }
    inline void dfs2(int now,int fa,int topf)
    {
        if(now==topf) ++top;
        ans[top].emplace_back(now);
        if(son[now]) dfs2(son[now],now,topf);
        for(int t:eg[now])
        {
            if(t==son[now]||t==fa) continue;
            dfs2(t,now,t);
        }
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;
            init();
            for(int i=1;i<=n;++i)
            {
                int x;cin>>x;
                if(i==x) rt=i;
                else
                {
                    eg[x].emplace_back(i);
                    eg[i].emplace_back(x);
                }
            }
            dfs(rt,0);
            dfs2(rt,0,rt);
            //cout<<"----------\n";
            cout<<top<<'\n';
            for(int i=1;i<=top;++i)
            {
                cout<<ans[i].size()<<'\n';
                for(int t:ans[i]) cout<<t<<' ';
                cout<<'\n';
            }
            cout<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*


*/