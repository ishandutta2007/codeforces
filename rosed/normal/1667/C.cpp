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
    int n;
    struct node
    {
        int x,y;
    }st[N];
    bool vis[N];
    int top;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n;
        if(n<=2)
        {
            cout<<1<<'\n';
            cout<<"1 1"<<'\n';
            return;
        }
        int x=1;
        for(;;++x)
        {
            if(x>=2*(n-x)-1) break;
        }
        cout<<x<<'\n';
        while(n%3!=2)
        {
            cout<<n<<' '<<n<<'\n';
            --n;
            --x;
        }
        int y=x;
        int t1=0,t2=0;
        while(y--)
        {
            cout<<t1+1<<' '<<t2+1<<'\n';
            t1+=1,t1%=x;
            t2+=2,t2%=x;
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