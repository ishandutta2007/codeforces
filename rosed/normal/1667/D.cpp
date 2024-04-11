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
    const int N=3e5+10,mod=998244353,inf=2e9;
    int n,m;
    int b[N];
    vector<int> eg[N];
    bool flag;
    inline void dfs(int now,int fa)
    {
        int cnt[2]={0,0};
        for(int t:eg[now])
        {
            if(t==fa) continue;
            dfs(t,now);
            ++cnt[b[t]];
        }
        if(now!=1)
        {
            b[now]=(cnt[0]>=cnt[1]);
            ++cnt[b[now]];
        }
        if(cnt[1]-cnt[0]<0||cnt[1]-cnt[0]>1) flag=1;
        //cout<<now<<' '<<b[now]<<' '<<cnt[0]<<' '<<cnt[1]<<"------------"<<endl;
    }
    inline void solve(int now,int fa)
    {
        vector<int> p[2];
        for(int t:eg[now])
        {
            if(t==fa) p[b[now]].emplace_back(now);
            else p[b[t]].emplace_back(t);
        }
        int s=eg[now].size(),opt=s%2;
        for(int i=0;i<s;++i)
        {
            int t=p[opt].back();
            if(t==now) cout<<now<<' '<<fa<<'\n';
            else solve(t,now);
            p[opt].pop_back();
            opt^=1;
        }
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;flag=0;
            for(int i=1;i<=n;++i)
            {
                eg[i].clear();
                b[i]=0;
            }
            for(int i=1;i<n;++i)
            {
                int x,y;cin>>x>>y;
                eg[x].emplace_back(y);
                eg[y].emplace_back(x);
            }
            dfs(1,0);
            if(flag)
            {
                cout<<"NO\n";
                continue;
            }
            cout<<"YES\n";
            solve(1,0);
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
5
1 2
2 3
3 4
3 5

*/