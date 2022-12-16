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
    const int N=1e6+10,mod=1e9+7,inf=2e9;
    int n;
    vector<int> eg[N];
    int buf[N],ans[N];
    int *dp[N],*cur=buf;
    int maxlen[N],son[N];
    inline void dfs1(int now,int fa)
    {
        maxlen[now]=1;
        for(int t:eg[now])
        {
            if(t==fa) continue;
            dfs1(t,now);
            maxlen[now]=max(maxlen[now],maxlen[t]+1);
            if(maxlen[t]>maxlen[son[now]]) son[now]=t;
        }
    }
    inline void dfs2(int now,int fa)
    {
        if(son[fa]!=now)
        {
            dp[now]=cur,cur+=maxlen[now];
        }
        dp[now][0]=1;
        
        if(son[now])
        {
            dp[son[now]]=dp[now]+1;
            dfs2(son[now],now);
            ans[now]=ans[son[now]]+1;
        }
        // cout<<now<<'\n';
        // for(int i=0;i<=maxlen[now];++i) cout<<dp[now][i]<<" \n"[i==maxlen[now]];
        for(int t:eg[now])
        {
            if(t==fa||t==son[now]) continue;
            dfs2(t,now);
            for(int i=1;i<=maxlen[t];++i)
            {
                dp[now][i]+=dp[t][i-1];
                //cout<<dp[now][i]<<"!!"<<endl;
                if(dp[now][i]>dp[now][ans[now]]||(dp[now][i]==dp[now][ans[now]]&&i<ans[now])) ans[now]=i;
            }
        }
        //for(int i=0;i<=maxlen[now];++i) cout<<dp[now][i]<<" \n"[i==maxlen[now]];
        if(dp[now][ans[now]]==1) ans[now]=0;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n;
        for(int i=1;i<n;++i)
        {
            int x,y;
            cin>>x>>y;
            eg[x].emplace_back(y);
            eg[y].emplace_back(x);
        }
        dfs1(1,0);
        dfs2(1,0);
        for(int i=1;i<=n;++i) cout<<ans[i]<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;
}
/*


*/