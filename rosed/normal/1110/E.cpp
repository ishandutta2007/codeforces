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
    const int N=2e5+10,mod=1e9+7,inv2=5e8+4,inf=2e9;
    const double pi=acos(-1.0);
    int n;
    int a[N],b[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n;
        bool flag=1;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;++i)
        {
            cin>>b[i];
        }
        if(a[1]!=b[1]||a[n]!=b[n]) flag=0;
        for(int i=n;i>=1;--i)
        {
            a[i]-=a[i-1];
            b[i]-=b[i-1];
        }
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        
        for(int i=1;i<=n;++i) flag&=(a[i]==b[i]);
        if(flag) cout<<"Yes\n";
        else cout<<"No\n";
        //c[i]=c[i+1]+c[i-1]-c[i];
        //c[i]-c[i-1]=c[i+1]-c[i];
        //d[i]=d[i+1]
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
7 2 4 12
7 -5 2 8
7 -5 8 2
*/