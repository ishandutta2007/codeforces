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
    const int N=5e5+10,inf=1e15,mod=998244353;
    int n;
    struct edge
    {
        int nxt,to,val;
        int x,y;
    }a[N<<1];
    int head[N],cnt;
    int tot=1;
    int dp[N],f[N];
    int c[N];
    map<int,int> cx;
    int prime[N],tmp[N],num;
    bool vis[N];
    inline int fast(int x,int k)
    {
        int ret=1;
        while(k)
        {
            if(k&1) ret=ret*x%mod;
            x=x*x%mod;
            k>>=1;
        }
        return ret;
    }
    inline void link(int x,int y,int z,int k1,int k2)
    {
        a[++cnt].nxt=head[x];
        a[cnt].to=y;
        a[cnt].val=z;
        a[cnt].x=k1;
        a[cnt].y=k2;
        head[x]=cnt;
    }
    inline void oula(int n)
    {
        for(int i=2;i<=n;++i)
        {
            if(!vis[i]) prime[++num]=i,tmp[i]=i;
            for(int j=1;j<=num&&i*prime[j]<=n;++j)
            {
                vis[i*prime[j]]=1;
                tmp[i*prime[j]]=prime[j];
                if(i%prime[j]==0) break;
            }
        }
    }
    inline void check(int x,int k)
    {
        while(x>1)
        {
            f[tmp[x]]+=k;
            c[tmp[x]]=max(c[tmp[x]],f[tmp[x]]);
            cx[tmp[x]]=1;
            x/=tmp[x];
        }
    }
    inline void dfs(int now,int fa)
    {
        for(int i=head[now];i;i=a[i].nxt)
        {
            int t=a[i].to;
            if(t==fa) continue;
            dp[t]=dp[now]*a[i].val%mod;
            check(a[i].y,1);
            check(a[i].x,-1);
            //cout<<now<<' '<<t<<' '<<a[i].x<<' '<<a[i].y<<' '<<f[t]<<endl;
            dfs(t,now);
            check(a[i].y,-1);
            check(a[i].x,1);
        }
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        oula(2e5);
        while(T--)
        {
            cin>>n;
            for(int i=1;i<=n;++i) head[i]=dp[i]=f[i]=0;
                cx.clear();
                cnt=0;tot=1;
            for(int k=1;k<n;++k)
            {
                int i,j,x,y;cin>>i>>j>>x>>y;
                int g=__gcd(x,y);
                x/=g,y/=g;
                link(j,i,x*fast(y,mod-2)%mod,x,y);
                link(i,j,y*fast(x,mod-2)%mod,y,x);
            }
            dp[1]=1;
            dfs(1,0);
            int ans=0;
            for(auto t:cx)
            {
                int u=t.first;
                //cout<<u<<' '<<c[u]<<"!!"<<endl;
                tot=tot*fast(u,c[u])%mod;
                c[u]=0;
            }
            for(int i=1;i<=n;++i)
            {
                ans=(ans+dp[i]*tot%mod)%mod;
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
8
5 4 2 3
6 4 5 4
1 3 5 2
6 8 2 1
3 5 3 4
3 2 2 5
6 7 4 3


6
4
3 2 3 4
1 2 4 3
1 4 2 4
8
5 4 2 3
6 4 5 4
1 3 5 2
6 8 2 1
3 5 3 4
3 2 2 5
6 7 4 3
17
8 7 4 16
9 17 4 5
5 14 13 12
11 1 17 14
6 13 8 9
2 11 3 11
4 17 7 2
17 16 8 6
15 5 1 14
16 7 1 10
12 17 13 10
11 16 7 2
10 11 6 4
13 17 14 6
3 11 15 8
15 6 12 8
4
3 2 3 4
1 2 4 3
1 4 2 4
8
5 4 2 3
6 4 5 4
1 3 5 2
6 8 2 1
3 5 3 4
3 2 2 5
6 7 4 3
17
8 7 4 16
9 17 4 5
5 14 13 12
11 1 17 14
6 13 8 9
2 11 3 11
4 17 7 2
17 16 8 6
15 5 1 14
16 7 1 10
12 17 13 10
11 16 7 2
10 11 6 4
13 17 14 6
3 11 15 8
15 6 12 8

*/