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
    int n,m,tmp;
    int a[N];
    int p[33];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n>>m;tmp=0;
            for(int i=0;i<=30;++i) p[i]=0;
            for(int i=1;i<=n;++i)
            {
                int x;cin>>x;
                for(int k=0;k<=30;++k) if((x>>k)&1)
                {
                    ++p[k];
                }
            }
            for(int k=30;k>=0;--k)
            {
                int sum=n-p[k];
                if(m>=sum) m-=sum,tmp|=(1<<k);
            }
            cout<<tmp<<'\n';
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