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
    int n,m,sum;
    int a[N];
    char c1,c2;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            
            cin>>n;sum=0;
            for(int i=0;i<=10000;++i) a[i]=0;
            for(int i=1;i<=n;++i)
            {
                cin>>c1>>c2;
                int x=c1-'a'+1,y=c2-'a'+1;
                sum+=a[x*100];
                sum+=a[y];
                sum-=2*a[x*100+y];
                ++a[x*100],++a[y],++a[x*100+y];
            }
            cout<<sum<<'\n';
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