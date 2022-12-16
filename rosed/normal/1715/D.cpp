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
    const int N=1e6+10,mod=1e9+7,inv2=5e8+4,inf=2e15;
    void __init(int n=2000) {}
    
    inline void main()
    {
        int n,m;
        cin>>n>>m;
        vector<int> b(n+1);
        vector vis(n+1,vector<int>(31));
        typedef pair<int,int> pr;
        vector<vector<pr> > eg(n+1);
        for(int i=1;i<=m;++i)
        {
            int x,y,z;cin>>x>>y>>z;
            if(x>y) swap(x,y);
            eg[x].emplace_back(pr(y,z));
            for(int k=29;k>=0;--k)
            {
                if(((z>>k)&1)==0)
                {
                    vis[x][k]=vis[y][k]=1;
                }
            }
        }

        for(int i=1;i<=n;++i)
        {
            for(auto [t,v]:eg[i])
            {
                for(int k=29;k>=0;--k) if((v>>k)&1)
                {
                    if(((b[i]>>k)&1)||((b[t]>>k)&1)) continue;
                    if(vis[t][k]) b[i]|=(1<<k);
                    if(i==t) b[i]|=(1<<k);
                    //else b[t]|=(1<<k);
                }
            }
            for(auto [t,v]:eg[i])
            {
                for(int k=29;k>=0;--k) if((v>>k)&1)
                {
                    if(((b[i]>>k)&1)||((b[t]>>k)&1)) continue;
                    b[t]|=(1<<k);
                }
            }
            cout<<b[i]<<" \n"[i==n];
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::__init();
    int qwq=1; //cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*

*/