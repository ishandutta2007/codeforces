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
    const int N=1e6+10,mod=1e9+7,inv2=5e8+4,inf=2e9;
    const double pi=acos(-1.0);
    int n,h,m;
    int hh[N],mm[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int qwq;cin>>qwq;
        while(qwq--)
        {
            cin>>n>>h>>m;
            int tim=h*60+m;
            int pos=inf;
            for(int i=1;i<=n;++i)
            {
                cin>>hh[i]>>mm[i];
                hh[i]=hh[i]*60+mm[i];
                if(hh[i]>=tim) pos=min(pos,hh[i]-tim);
            }
            if(pos==inf)
            {
                tim-=24*60;
                for(int i=1;i<=n;++i)
                {
                    if(hh[i]>=tim) pos=min(pos,hh[i]-tim);
                }
            }
            cout<<pos/60<<' '<<pos%60<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
7 2 4 12
7 -5 2 8
7 -5 8 2
*/