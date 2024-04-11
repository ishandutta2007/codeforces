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
    const int N=1e6+10,mod=998244353,inv2=499122177,inf=2e18;
    void __init(int n=2000) {}
    
    inline void main()
    {
        int n,m;
        cin>>n>>m;
        int maxn=(1<<n);
        vector s(n,vector<int>(m));
        vector<int> a(maxn),b(maxn);
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                char ch;cin>>ch;
                s[i][j]=ch^48;
            }
        }
        for(int j=0;j<m;++j)
        {
            int tmp=0;
            for(int i=0;i<n;++i)
            {
                tmp|=s[i][j]*(1<<i);
            }
            ++a[tmp];
        }
        for(int i=0;i<maxn;++i)
        {
            b[i]=__builtin_popcount(i);
            b[i]=min(b[i],n-b[i]);
        }
        
        auto fwtxor=[&](vector<int> &a,int inv) -> void
        {
            for(int k=1;2*k<=maxn;k<<=1)
            {
                for(int i=0;i<maxn;i+=2*k)
                {
                    for(int j=0;j<k;++j)
                    {
                        int x=a[i+j],y=a[i+j+k];
                        a[i+j]=inv*(x+y)%mod;
                        a[i+j+k]=inv*(x-y+mod)%mod;
                    }
                }
            }
        };
        fwtxor(a,1);fwtxor(b,1);
        for(int i=0;i<maxn;++i) a[i]=a[i]*b[i]%mod;
        fwtxor(a,inv2);
        int ans=inf;
        for(int i=0;i<maxn;++i) ans=min(ans,a[i]);
        cout<<ans<<'\n';

    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::__init();
    int qwq=1; //cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*

*/