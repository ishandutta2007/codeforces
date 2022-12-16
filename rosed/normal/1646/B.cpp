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
    int n,t1,t2;
    int a[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;
            int sum1=0,sum2=0;
            bool flag=0;
            for(int i=1;i<=n;++i) cin>>a[i];
            sort(a+1,a+n+1);
            sum1=a[1]+a[2],t1=2,sum2=a[n];t2=n;
            while(t1<t2)
            {
                if(sum1<sum2) flag=1;
                sum1+=a[++t1];
                sum2+=a[--t2];
            }
            if(flag) cout<<"YES\n";
            else cout<<"NO\n";
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