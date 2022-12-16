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
    const int N=2e5+10,mod=998244353,inf=2e9;
    int n,ans;
    char s[N];
    int tr[N<<2][3];
    inline void update(int x,int k,int id)
    {
        for(int i=x;i<=2*n+1;i+=lowbit(i)) tr[i][id]+=k;
    }
    inline int query(int x,int id)
    {
        int sum=0;
        for(int i=x;i;i-=lowbit(i)) sum+=tr[i][id];
        return sum;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;ans=0;
            cin>>(s+1);
            for(int i=1;i<=2*n+1;++i) tr[i][0]=tr[i][1]=tr[i][2]=0;
            update(n+1,1,0);
            int sum=0;
            for(int i=1;i<=n;++i)
            {
                sum+=(s[i]=='+'?1:-1);
                int b=(sum%3+3)%3;
                ans+=query(2*n+1,b)-query(sum+n,b);
                update(sum+n+1,1,b);
            }
            cout<<ans<<'\n';
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