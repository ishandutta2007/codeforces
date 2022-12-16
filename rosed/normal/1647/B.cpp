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
    char s[210][210];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n>>m;
            bool flag=1;
            for(int i=1;i<=n;++i)
            {
                cin>>(s[i]+1);
            }
            for(int i=1;i<n;++i)
            {
                for(int j=1;j<m;++j)
                {
                    int ss=(s[i][j]=='1');
                    ss+=(s[i+1][j]=='1');
                    ss+=(s[i][j+1]=='1');
                    ss+=(s[i+1][j+1]=='1');
                    if(ss==3) flag=0;
                }
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
1
3 3
111
111
001

*/