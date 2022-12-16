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
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e18;
    void __init(int n=2000) {}
    inline void main()
    {
        int n;cin>>n;
        auto check=[&](int x) -> bool
        {
            int sum=0;
            for(int d=1;d<=2;++d)
            {
                int gc=2*d;
                int st=(d+1)*(d+1)-1-gc;
                if(gc>x-st) break;
                sum+=(x-st)/gc;
                if(sum>=n) return 1;
                //st+k*gc<=x;
                //k*gc<=x-st
            }
            return sum>=n;
        };
        int l=1,r=inf;
        while(l<=r)
        {
            if(check(mid)) r=mid-1;
            else l=mid+1;
        }
        cout<<r+1<<'\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::__init();
    int qwq=1; //cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*
2 1 3
3 1 8
3 2 5
4 1 15
4 2 12
4 3 7
5 1 24
5 2 21
5 3 16
5 4 9
6 1 35
6 2 32
6 3 27
6 4 20
6 5 11
7 1 48
7 2 45
7 3 40
7 4 33
7 5 24
7 6 13

*/