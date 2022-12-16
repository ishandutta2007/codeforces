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
    const int N=5e5+10,mod=1e9+7,inf=2e9;
    int n;
    char s[N];
    int f[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n;
        cin>>(s+1);
        f[1]=1;
        int maxn=0;
        for(int i=2;i<=n;++i)
        {
            f[i]=f[i-1]+1;
            if(i%2==0)
            {
                bool flag=1;
                for(int j=i/2;j>=1;--j)
                {
                    if(s[i-(i/2-j)]!=s[j]) flag=0;
                }
                if(flag) maxn=i/2-1;
            }
        }
        cout<<n-maxn<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
aab

*/