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
    const int N=1e6+10,mod=1e9+7,inf=2e15;
    void __init(int n=2000) {}
    inline void main()
    {
        int a,b,x;
        cin>>a>>b>>x;
        if(x>a&&x>b)
        {
            cout<<"NO\n";
            return;
        }
        //x==a
        if(x==a||x==b)
        {
            cout<<"YES\n";
            return;
        }
        if(a>b) swap(a,b);
        //a<=b
        while(a>x||b>x)
        {
            if(b%a>x)
            {
                b%=a;
                swap(a,b);
            }
            else
            {
                int t=(b-x+a-1)/a;
                b-=t*a;
                if(a>=b) swap(a,b);
            }
            if(a==x||b==x||!a||!b) break;
           
        }
        if(a==x||b==x) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::__init();
    int qwq=1; cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*
365 216
149 216
149 67
82 67
15 67
15 52


*/