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
    int a[N],s[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int skx;
        cin>>skx;
        while(skx--)
        {
            cin>>n;
            bool flag=0,num=0;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
            }
            s[n+1]=0;
            for(int i=n;i>=1;--i)
            {
                s[i]=s[i+1]+a[i];
                if(a[i]!=0) num=1;
                if(s[i]>=0&&num&&i!=1) flag=1;
            }
            if(s[1]!=0||flag) cout<<"NO\n";
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

*/