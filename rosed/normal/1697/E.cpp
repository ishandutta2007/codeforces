#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=110,mod=998244353,inf=2e9;
    int n;
    struct node
    {
        int x,y;
    }a[N];
    int dis[N][N],dp[N][N];
    bool vis[N];
    vector<int> g[N],ans;
    int col[N],tot;
    set<int> pts;
    inline void dfs1(int now)
    {
        if(pts.find(now)!=pts.end()) return;
        pts.insert(now);
        for(int t:g[now]) dfs1(t);
    }
    inline void dfs2(int now,int c)
    {
        if(col[now]==c) return;
        col[now]=c;
        for(int t:g[now]) dfs2(t,c);
    }
    inline int A(int n,int m)
    {
        int ans=1;
        for(int i=n;i>n-m;--i) ans=ans*i%mod;
       //     cout<<n<<' '<<m<<' '<<ans<<"!!"<<endl;
        return ans;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int skx=1;
        while(skx--)
        {
            cin>>n;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i].x>>a[i].y;
            }
            memset(dis,0x3f,sizeof(dis));
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=n;++j)
                {
                    if(i!=j)  dis[i][j]=abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y);
                }
            }
            for(int i=1;i<=n;++i)
            {
                int d=*min_element(dis[i]+1,dis[i]+n+1);
                for(int j=1;j<=n;++j)
                {
                    if(dis[i][j]==d) g[i].emplace_back(j);
                }
            }
            for(int i=1;i<=n;++i)
            {
                if(col[i]!=0) continue;
                ++tot;
                pts.clear();
                dfs1(i);
                int d=*min_element(dis[i]+1,dis[i]+n+1);
                set<int> pts2=pts;
                bool flag=0;
                for(int x:pts)
                {
                    for(int y:pts2)
                    {
                        if(x!=y&&dis[x][y]!=d) flag=1;
                    }
                }
                if(flag)
                {
                    col[i]=++tot;
                    ans.emplace_back(1);
                }
                else
                {
                    dfs2(i,tot);
                    ans.emplace_back(pts.size());
                }
            }
            dp[0][0]=1;
            int m=ans.size();
            for(int i=0;i<m;++i)
            {
                for(int j=0;j<n;++j)
                {
                    if(dp[i][j]==0) continue;
                    dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j])%mod;
                    if(ans[i]!=1) dp[i+1][j+ans[i]]=(dp[i+1][j+ans[i]]+dp[i][j])%mod;
                }
            }
            int ret=0;
            for(int i=1;i<=n;++i)
            {
                //cout<<dp[m][i]<<"!!!!!!!!!!"<<endl;
                ret=(ret+dp[m][i]*A(n,i))%mod;
            }
            cout<<ret<<'\n';
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