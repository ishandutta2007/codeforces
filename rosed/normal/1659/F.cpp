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
    const int N=4e5+10,mod=998244353,inf=2e9;
    int n,pos,rt,s;
    vector<int> eg[N];
    int p[N];
    bool vis[N];
    int dep[N],maxn;
    inline void dfs(int now,int fa)
    {
        dep[now]=dep[fa]+1;
        if(dep[now]>dep[rt]) rt=now;
        for(int t:eg[now])
        {
            if(t==fa) continue;
            dfs(t,now);
        }
    }
    inline bool check(int x){return p[x]!=x;}
    int tt;
    inline void work()
    {
        s=0;
        for(int i=1;i<=n;++i) vis[i]=0;
        for(int i=1;i<=n;++i)
        {
            if(vis[i]) continue;
            vis[i]=1;
            int now=p[i];
            while(!vis[now])
            {
                tt=now;
                vis[now]=1;
                now=p[now];
                ++s;
            }
        }
    }
    inline void work1()
    {
        cout<<"Bob\n";
    }
    inline void work2()
    {
        if(s&1) cout<<"Alice\n";
        else cout<<"Bob\n";
    }
    inline void work3()
    {
        //cout<<"!!"<<endl;
        if(s&1) cout<<"Bob\n";
        else cout<<"Alice\n";
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n>>pos;
            for(int i=1;i<=n;++i)
            {
                eg[i].clear();
            }
            for(int i=1;i<n;++i)
            {
                int x,y;cin>>x>>y;
                eg[x].emplace_back(y);
                eg[y].emplace_back(x);
            }
            for(int i=1;i<=n;++i)
            {
                int x;cin>>x;
                p[x]=i;
            }
            work();
            if(!s)
            {
                cout<<"Alice\n";
                continue;
            }
            if(s==1&&pos!=tt&&pos!=p[tt])
            {
                cout<<"Alice\n";
                continue;
            }
            rt=0;
            dfs(1,0);
            dfs(rt,0);
            if(dep[rt]>3)
            {
                cout<<"Alice"<<'\n';
            }
            else
            {
                for(int i=1;i<=n;++i)
                {
                    if(eg[i].size()>eg[rt].size()) rt=i;
                }
                if(rt==pos&&check(rt)) work1();
                else if(rt==pos&&!check(rt)) work2();
                else if(rt!=pos&&check(pos)&&check(rt))
                {
                    if(p[pos]==rt) work1();
                    else work3();
                }
                else if(rt!=pos&&check(pos)&&!check(rt))
                {
                    work3();
                }
                else if(rt!=pos&&!check(pos)&&check(rt))
                {

                    if(s==1) cout<<"Alice\n";
                    else work3();
                }
                else if(rt!=pos&&!check(pos)&&!check(rt))
                {
                    if(s==1) cout<<"Alice\n";
                    else work3();
                }
            }
        }
    }
}
signed main()
{
    // freopen("data.in","r",stdin);
    // freopen("red.out","w",stdout);
    red::main();
    return 0;   
}
/*
1
11 8
7 1
7 2
7 3
7 4
7 5
7 6
7 8
7 9
7 10
7 11
11 5 8 2 9 6 4 7 1 10 3 

*/