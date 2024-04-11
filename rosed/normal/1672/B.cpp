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
    char s[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>(s+1);
            n=strlen(s+1);
            int sum=0;
            bool flag=1;
            for(int i=1;i<=n;++i)
            {
                if(s[i]=='A') ++sum;
                else
                {
                    --sum;
                    if(sum<0) flag=0;
                }
            }
            if(s[n]!='B') flag=0;
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
1
5
1 2
2 3
3 4
3 5

*/