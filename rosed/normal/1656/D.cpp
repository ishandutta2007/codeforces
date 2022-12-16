#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,mod=998244353,inf=2e9;
    int n,m,ans;
    int top,sum;
    inline int dc(int x)
    {
        return x*(x+1)/2;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;
            // if(n==6)
            // {
            //     cout<<3<<'\n';
            //     continue;
            // }
            if(n%2==1)
            {
                cout<<2<<'\n';
                continue;
            }
            int x=n,y=1;
            while(x%2==0) x/=2,y*=2;
            if(x==1)
            {
                cout<<"-1\n";
                continue;
            }
            if(y*2<=x)
            {
                cout<<y*2<<'\n';
                continue;
            }
            //y*2>x
            cout<<x<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;   
}
/*
5
2
4
1516512161616
89784856616161
99999999999999998

*/