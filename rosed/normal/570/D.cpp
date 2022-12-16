#include<bits/stdc++.h>
using namespace std;
namespace red{
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-15)
    const int N=1e6+10,mod=1e9+7,inf=2e9;
    int n,m;
    char s[N];
    vector<int> eg[N];
    typedef pair<int,int> pr;
    vector<pr> q[N];
    int str[N],dep[N],maxlen[N],son[N];
    int ans[N];
    int dp[N][26],pos[N],cur=0;
    inline void dfs1(int now,int fa)
    {
        str[now]=maxlen[now]=1;
        dep[now]=dep[fa]+1;
        for(int t:eg[now])
        {
            if(t==fa) continue;
            dfs1(t,now);
            maxlen[now]=max(maxlen[now],maxlen[t]+1);
            str[now]+=str[t];
            if(maxlen[t]>maxlen[son[now]]) son[now]=t;
        }
    }
    inline void dfs2(int now,int fa)
    {
        if(son[fa]!=now) pos[now]=cur,cur+=maxlen[now];
        dp[pos[now]][s[now]-'a']^=1;
        if(son[now])
        {
            pos[son[now]]=pos[now]+1;
            dfs2(son[now],now);
        }
        // cout<<now<<'\n';
        // for(int i=0;i<=maxlen[now];++i) cout<<dp[pos[now]+i]<<" \n"[i==maxlen[now]];
        for(int t:eg[now])
        {
            if(t==fa||t==son[now]) continue;
            dfs2(t,now);
            int sum=0;
            for(int i=1;i<=maxlen[t];++i)
            {
                for(int c=0;c<26;++c)
                {
                    dp[pos[now]+i][c]^=dp[pos[t]+(i-1)][c];
                }
                //cout<<now<<' '<<dp[pos[t]+(i-1)]<<"!!!!"<<endl;
            }
        }
        // cout<<now<<'\n';
        // for(int i=0;i<=maxlen[now];++i) cout<<dp[pos[now]+i]<<" \n"[i==maxlen[now]];
        for(pr tmp:q[now])
        {
            int t=tmp.first,id=tmp.second,sum=0;
            t-=dep[now];
            if(t>=maxlen[now]||t<0) continue;
            //cout<<now<<' '<<t<<"!!!!!!"<<endl;
            for(int c=0;c<26;++c)
            {
                sum+=dp[pos[now]+t][c];
            }
            if(sum>1) ans[id]=1;
        }
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n>>m;
        for(int i=2;i<=n;++i)
        {
            int x=i,y;
            cin>>y;
            eg[x].emplace_back(y);
            eg[y].emplace_back(x);
        }
        cin>>(s+1);
        dfs1(1,0);
        for(int i=1;i<=m;++i)
        {
            int x,y;
            cin>>x>>y;
            q[x].emplace_back(pr(y,i));
        }
        dfs2(1,0);
        for(int i=1;i<=m;++i)
        {
            if(ans[i]==0) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
}
signed main()
{
    //freopen("data.in","r",stdin);
    //freopen("red.out","w",stdout);
    red::main();
    return 0;
}
/*

*/