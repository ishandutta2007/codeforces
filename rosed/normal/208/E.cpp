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
    const int N=3e5+10,mod=1e9+7,inf=2e9;
    int n,m;
    vector<int> eg[N];
    typedef pair<int,int> pr;
    vector<pr> q[N];
    int buf[N],ans[N];
    int *dp[N],*cur=buf;
    int maxlen[N],son[N],dep[N];
    int f[N][18];
    inline void dfs1(int now,int fa)
    {
        //cout<<now<<' '<<fa<<"!!"<<endl;
        maxlen[now]=1;
        f[now][0]=fa;
        dep[now]=dep[fa]+1;
        for(int i=1;i<18;++i) f[now][i]=f[f[now][i-1]][i-1];
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
        if(son[fa]!=now) dp[now]=cur,cur+=maxlen[now];
        dp[now][0]=1;
        if(son[now])
        {
            dp[son[now]]=dp[now]+1;
            dfs2(son[now],now);
        }
        for(int t:eg[now])
        {
            if(t==fa||t==son[now]) continue;
            dfs2(t,now);
            for(int i=1;i<=maxlen[t];++i)
            {
                dp[now][i]+=dp[t][i-1];
            }
        }
        if(now<=n)
        {
            for(pr t:q[now])
            {
                int tmp=dp[now][t.first];
                int id=t.second;
                //cout<<now<<' '<<t.first<<' '<<tmp<<"!!!"<<endl;
                ans[id]=tmp-1;
            }
        }
        
        //cout<<now<<' '<<dp[2][0]<<"!!!!!!!"<<endl;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            int x=i,y;cin>>y;
            if(!y) y=n+1;
            eg[x].emplace_back(y),eg[y].emplace_back(x);
        }
        cin>>m;
        dfs1(n+1,0);
        for(int i=1;i<=m;++i)
        {
            int x,p;cin>>x>>p;
            int y=x,k=p;
            for(int i=17;~i;--i) if((p>>i)&1)
            {
                p-=(1<<i);
                y=f[y][i];
            }
            q[y].emplace_back(pr(k,i));
        }
        dfs2(n+1,0);
        for(int i=1;i<=m;++i) cout<<ans[i]<<" \n"[i==m];
    }
}
signed main()
{
    red::main();
    return 0;
}
/*


*/