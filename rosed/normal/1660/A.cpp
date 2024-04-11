#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=2e5+10,mod=998244353,inf=2e9;
    int n;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            int a,b;
            cin>>a>>b;
            if(a==0)
            {
                cout<<1<<'\n';
            }
            else
            {
                cout<<2*b+a+1<<'\n';
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