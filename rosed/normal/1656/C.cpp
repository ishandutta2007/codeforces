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
    int n,m;
    int a[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;
            bool flag0=0,flag1=0;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
                if(a[i]==0) flag0=1;
                if(a[i]==1) flag1=1;
            }
            sort(a+1,a+n+1);
            if(!flag1)
            {
                cout<<"YES\n";
                continue;
            }
            if(flag1&&flag0)
            {
                cout<<"NO\n";
                continue;
            }
            bool flag=0;
            for(int i=1;i<n;++i)
            {
                if(a[i]+1==a[i+1]) flag=1;
            }
            if(flag) cout<<"NO\n";
            else cout<<"YES\n";
        }
    }
}
signed main()
{
    red::main();
    return 0;   
}
/*
4 4
zzzz
z.z.
.zzz
zzzz

*/