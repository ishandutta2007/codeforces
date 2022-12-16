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
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e15;
    void __init(int n=2000) {}
    int n,m;
    struct matrix
    {
        int g[110][110];
        void init(int x)
        {
            for(int i=0;i<n;++i)
                for(int j=0;j<n;++j) g[i][j]=0;
            if(x) for(int i=0;i<n;++i) g[i][i]=1;
        }
        matrix operator * (const matrix &t) const
        {
            matrix ret;
            ret.init(0);
            for(int i=0;i<n;++i)
            {
                for(int j=0;j<n;++j)
                {
                    for(int k=0;k<n;++k)
                    {
                        ret.g[i][j]=(ret.g[i][j]+g[i][k]*t.g[k][j]%mod)%mod;
                    }
                }
            }
            return ret;
        }
        matrix operator ^ (int k) const
        {
            matrix ret,x=*this;
            ret.init(1);
            while(k)
            {
                if(k&1) ret=ret*x;
                x=x*x;
                k>>=1;
            }
            return ret;
        }
    }A,tran;
    inline void main()
    {
        
        cin>>n>>m;
        vector<int> a(n);
        
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
            A.g[0][i]=1;
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                int x=a[i]^a[j];
                int s=0;
                while(x) s+=(x&1),x>>=1;
                if(s%3==0) tran.g[i][j]=1;
            }
            //cout<<'\n';
        }
        tran=tran^(m-1);
        A=A*tran;
        int ans=0;
        for(int i=0;i<n;++i) ans=(ans+A.g[0][i])%mod;
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