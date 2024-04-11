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
            cin>>n>>m;
            int t1=0,t2=0;
            for(int i=1;i<=m;++i)
            {
                int x,y;
                cin>>x>>y;
                t1=max(x,t1),t2=max(y,t2);
            }
            if(t1+t2>n) cout<<"IMPOSSIBLE\n";
            else
            {
                t1=n-t2;
                while(t1--) cout<<"R";
                while(t2--) cout<<"W";
                cout<<'\n';
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
5
1 2
2 3
3 4
3 5

*/