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

    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n>>m;
            if(n>m) swap(n,m);
            if(n==1&&m>2)
            {
                cout<<"-1\n";
                continue;
            }
            int t1=n-1,t2=m-1;
            if(abs(t1-t2)<=1) cout<<t1+t2<<'\n';
            else
            {
                cout<<t1+t2+(t2-t1)/2*2<<'\n';
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
1 2 3 4

*/