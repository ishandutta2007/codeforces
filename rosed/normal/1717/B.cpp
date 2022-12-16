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
    const int N=1e6+10,mod=998244353,inf=2e15;
    void __init(int n=2000) {}
    inline void main()
    {
        int n,k,x,y;
        cin>>n>>k>>x>>y;
        vector a(n+1,vector<int>(n+1));
        function<void(int,int)> dfs=[&](int x,int y) -> void
        {
            if(x<1||x>n||y<1||y>n) return;
            if(a[x][y]) return;
            a[x][y]=1;
            if(x>1&&y<n) dfs(x-1,y+1);
            if(x<n&&y>1) dfs(x+1,y-1);
            if(y+k<=n) dfs(x,y+k);
            else dfs(x+((y+k)-n),n);
            if(y-k>=1) dfs(x,y-k);
            else dfs(x-(1-(y-k)),1);
        };
        dfs(x,y);
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(a[i][j]) cout<<'X';
                else cout<<'.';
            }
            cout<<'\n';
        }
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