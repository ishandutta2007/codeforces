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
    char s[55][55];
    inline void down(int x,int y)
    {
        if(s[x+1][y]=='.')
        {
            swap(s[x+1][y],s[x][y]);
            down(x+1,y);
        }
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n>>m;
            for(int i=1;i<=n;++i)
            {
                cin>>(s[i]+1);
            }
            for(int i=1;i<=m;++i) s[n+1][i]='o';
            for(int i=n;i>=1;--i)
            {
                for(int j=1;j<=m;++j)
                {
                    if(s[i][j]=='*') down(i,j);
                }
            }
            for(int i=1;i<=n;++i)
            {
                cout<<(s[i]+1)<<'\n';
            }
            cout<<'\n';
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
1 2 3 4

*/