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
    const int N=1e6+10,mod=1e9+7,inf=2e15;
    void __init(int n=2000) {}
    inline void main()
    {
        int l,r;
        cin>>l>>r;
        vector<int> d,u;
        vector dp(100,vector(2,vector(2,vector(2,vector<int>(2,-1)))));
        function<int(int,int,int,int,int)> dfs=[&](int pos,int x1,int x2,int y1,int y2) -> int 
        {
            if(pos<0) return 1;
            if(~dp[pos][x1][x2][y1][y2]) return dp[pos][x1][x2][y1][y2];
            int &ret=dp[pos][x1][x2][y1][y2];ret=0;
            int t1=x1?d[pos]:0,t2=x2?u[pos]:1;
            int t3=y1?d[pos]:0,t4=y2?u[pos]:1;
            for(int x=t1;x<=t2;++x)
                for(int y=t3;y<=t4;++y)
                {
                    if(x&y) continue;
                    ret=(ret+dfs(pos-1,x1&(x==t1),x2&(x==t2),y1&(y==t3),y2&(y==t4)));
                }
            return ret;
        };
        auto solve=[&](int l,int r) -> int
        {
            while(l) d.emplace_back(l&1),l>>=1;
            while(r) u.emplace_back(r&1),r>>=1;
            int len=u.size();
            d.resize(len,0);
            return dfs(len-1,1,1,1,1);
        };
        cout<<solve(l,r)<<'\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::__init();
    int qwq=1; cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*
1 7 5 6 8 2 6 5

0 8 5 6 8 0 8 5
3
5 6 5
3 8 5
2
3
8
*/