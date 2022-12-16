#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,inf=2e9,mod=1e9+7;
    int n,m;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            int l,r,a;
            cin>>l>>r>>a;
            int k=r%a;
            if(k==a-1) cout<<(r/a+r%a)<<'\n';
            else
            {
                int tmp=r-(k+1);
                if(tmp>=l) cout<<(tmp/a+tmp%a)<<'\n';
                else cout<<(r/a+r%a)<<'\n';

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
5 5
5 1 2
6 2 3
4 3 5
6 2 4
5 1 3

*/