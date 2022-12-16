#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=300,mod=998244353,inf=2e9;
    int n,m;
    char s[N][N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int skx;
        cin>>skx;
        while(skx--)
        {
            for(int i=1;i<=8;++i)
            {
                cin>>(s[i]+1);
            }
            for(int i=2;i<=7;++i)
            {
                for(int j=2;j<=7;++j)
                {
                    if(s[i][j]=='#'&&s[i-1][j-1]=='#'&&s[i-1][j+1]=='#'&&s[i+1][j-1]=='#'&&s[i+1][j+1]=='#')
                    {
                        cout<<i<<' '<<j<<'\n';
                    }
                }
            }
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
1 2 3
a
aa

*/