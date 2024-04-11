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
    const int N=4e5+10,mod=998244353,inf=2e9;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            int n,a,b;cin>>n>>a>>b;
            int x=(a-1)/(b+1)+1;
            while(a>b&&a>0)
            {
                int y=min(x,a);
                while(y>0&&a>(b-1))
                {
                    --y;--a;
                    cout<<'R';
                }
                if(y==0&&b>0)
                {
                    cout<<'B';
                    --b;
                }
            }
            while(b--)
            {
                cout<<"B";
                if(a)
                {
                    cout<<"R";
                    --a;
                }
            }
            cout<<'\n';
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