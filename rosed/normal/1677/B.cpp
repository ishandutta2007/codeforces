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
    const int N=2e6+10,mod=1e9+7,inf=2e9;
    int n,m,len;
    int a[N];
    char s[N];
    bool vis[N];
    int t[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n>>m;
            cin>>(s);
            len=strlen(s);
            int r=0,c=0;
            for(int i=0;i<=m;++i) vis[i]=0;
            for(int i=0;i<=len;++i) t[i]=0;
            int pre=-inf,ss=0;
            for(int i=0;i<len;++i)
            {
                ss+=t[i%m];
                if(s[i]=='1')
                {
                    if(!vis[i%m]) ++r,vis[i%m]=1;
                    if(i-pre>=m) ++c;
                    else
                    {
                        ++t[(i+m-(i-pre))%m],--t[i%m];
                    }
                    pre=i;
                }
                cout<<r+c+ss<<' ';
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
6
2 2
1100
4 2
11001101
2 4
11001101
2 2
1100
4 2
11001101
2 4
11001101

*/