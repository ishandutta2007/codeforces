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
    int n;
    int a[N];
    bool vis[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        vis[1]=0;
        for(int i=2;i<=50;++i)
        {
            for(int j=1;j<i;++j)
            {
                if(vis[j]==vis[i-j])
                {
                    vis[i]=1;break;
                }
            }
        }
        while(T--)
        {
            cin>>n;
            int sum=0;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
                sum+=vis[a[i]];
            }
            if(sum&1) cout<<"errorgorn\n";
            else cout<<"maomao90\n";
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