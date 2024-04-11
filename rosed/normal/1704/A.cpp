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
    const int N=5e5+10,mod=1e9+7,inv2=5e8+4,inf=2e9;
    const double pi=acos(-1.0);
    int n,m;
    char s[N],t[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int qwq;cin>>qwq;
        while(qwq--)
        {
            cin>>n>>m;
            cin>>(s+1)>>(t+1);
            reverse(s+1,s+n+1);
            reverse(t+1,t+m+1);
            bool flag=1;
            if(n<m) flag=0;
            for(int i=1;i<m&&flag;++i)
            {
                if(s[i]!=t[i]) flag=0;
            }
            bool f=0;
            for(int i=m;i<=n;++i)
            {
                if(s[i]==t[m]){f=1;break;}
            }
            if(!f) flag=0;
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