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
    int a[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;

            bool t1=1,t2=1;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
                a[i]&=1;
                if(i>2)
                {
                    if(i&1) t1&=((a[i]^a[i-2])==0);
                    else t2&=((a[i]^a[i-2])==0);
                }
            }
            if(t1&t2) cout<<"YES\n";
            else cout<<"NO\n";
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