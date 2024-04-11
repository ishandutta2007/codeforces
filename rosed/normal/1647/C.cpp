#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=1e6+10,mod=998244353,inf=2e9;
    int n,m;
    char s[210][210];
    struct node
    {
        int x,y,xx,yy;
    }st[N];
    int top=0;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n>>m;top=0;
            for(int i=1;i<=n;++i)
            {
                cin>>(s[i]+1);
            }
            if(s[1][1]=='1')
            {
                cout<<"-1\n";
                continue;
            }
            for(int i=n;i>1;--i)
            {
                for(int j=1;j<=m;++j)
                {
                    if(s[i][j]=='1') st[++top]=(node){i-1,j,i,j};
                }
            }
            for(int j=m;j>1;--j)
            {
                if(s[1][j]=='1') st[++top]=(node){1,j-1,1,j};
            }
            cout<<top<<'\n';
            for(int i=1;i<=top;++i)
            {
                cout<<st[i].x<<' '<<st[i].y<<' '<<st[i].xx<<' '<<st[i].yy<<'\n';
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
5 5 7 2
5 0 7 2

1 3 1 2 5
1 2 3 1 4

*/