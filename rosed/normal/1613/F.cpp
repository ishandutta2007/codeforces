#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-15)
    const int N=1e6+10,mod=998244353,inf=2e15;
    void __init(int n=2000) {}
    namespace NTT
    {
        const int g=3,gi=332748118;
        int limit=1,len;
        int pos[N];
        inline int fast(int x,int k)
        {
            int ret=1;
            while(k)
            {
                if(k&1) ret=ret*x%mod;
                x=x*x%mod;
                k>>=1;
            }
            return ret;
        }
        inline vector<int> ntt(vector<int> a,int inv)
        {
            for(int i=0;i<limit;++i)
                if(i<pos[i]) swap(a[i],a[pos[i]]);
            for(int mid=1;mid<limit;mid<<=1)
            {
                int Wn=fast(inv?g:gi,(mod-1)/(mid<<1));
                for(int r=mid<<1,j=0;j<limit;j+=r)
                {
                    int w=1;
                    for(int k=0;k<mid;++k,w=w*Wn%mod)
                    {
                        int x=a[j+k],y=w*a[j+k+mid]%mod;
                        a[j+k]=(x+y)%mod;
                        a[j+k+mid]=(x-y+mod)%mod;
                    }
                }
            }
            if(inv) return a;
            inv=fast(limit,mod-2);
            for(int i=0;i<limit;++i) a[i]=a[i]*inv%mod;
            return a;
        }
        inline vector<int> deriva(vector<int> a,int n)
        {
            a.resize(n);
            for(int i=1;i<n;++i) a[i-1]=a[i]*i%mod;
            a[n-1]=0;
            return a;
        }
        inline vector<int> integral(vector<int> a,int n)
        {
            a.resize(n);
            for(int i=n-1;i;--i) a[i]=a[i-1]*fast(i,mod-2)%mod;
            a[0]=0;
            return a;
        }
        inline vector<int> add(vector<int> a,vector<int> b,int n,int m)
        {
            limit=max(n,m);
            a.resize(limit),b.resize(limit);
            for(int i=0;i<limit;++i) a[i]=(a[i]+b[i])%mod;
            return a;
        }
        inline vector<int> mul(vector<int> a,vector<int> b,int n=-1,int m=-1)
        {
            if(n==-1) n=a.size();
            if(m==-1) m=b.size();
            limit=1,len=0;
            while(limit<n+m) limit<<=1,++len;
            a.resize(limit,0),b.resize(limit,0);
            for(int i=0;i<limit;++i) pos[i]=(pos[i>>1]>>1)|((i&1)<<(len-1));
            a=ntt(a,1),b=ntt(b,1);
            for(int i=0;i<limit;++i) a[i]=a[i]*b[i]%mod;
            vector<int> c=ntt(a,0);
            c.resize(n+m-1);
            return c;
        }
        inline vector<int> poly_inv(vector<int> a,int n)
        {
            if(n==1)
            {
                vector<int> b(1);
                b[0]=fast(a[0],mod-2);
                return b;
            }
            vector<int> b=poly_inv(a,(n+1)>>1);
            limit=1,len=0;
            while(limit<n+n) limit<<=1,++len;
            for(int i=0;i<limit;++i) pos[i]=(pos[i>>1]>>1)|((i&1)<<(len-1));
            a.resize(limit),b.resize(limit);
            vector<int> c;
            c.resize(limit);
            for(int i=0;i<n;++i) c[i]=a[i];
            for(int i=n;i<limit;++i) c[i]=b[i]=0;
            c=ntt(c,1);b=ntt(b,1);
            for(int i=0;i<limit;++i) b[i]=(2-c[i]*b[i]%mod+mod)%mod*b[i]%mod;
            b=ntt(b,0);
            b.resize(n);
            return b;
        }
        inline vector<int> ln(vector<int> a,int n)
        {
            return integral(mul(deriva(a,n),poly_inv(a,n),n,n),n);
        }
        inline vector<int> exp(vector<int> a,int n)
        {
            if(n==1)
            {
                vector<int> b(1);
                b[0]=1;
                return b;
            }
            vector<int> b=exp(a,(n+1)>>1);
            vector<int> f=ln(b,n);
            f[0]=(a[0]+1-f[0]+mod)%mod;
            for(int i=1;i<n;++i) f[i]=(a[i]-f[i]+mod)%mod;
            b=mul(b,f,n,n);
            b.resize(n);
            return b;
        }
    }
    inline void main()
    {
        auto fast=[&](int x,int k) -> int
        {
            int ret=1;
            while(k)
            {
                if(k&1) ret=ret*x%mod;
                x=x*x%mod;
                k>>=1;
            }
            return ret;
        };
        int n;
        cin>>n;
        vector<int> rd(n+1);
        for(int i=1;i<n;++i)
        {
            int x,y;
            cin>>x>>y;
            ++rd[x],++rd[y];
        }
        vector<int> c(n+1);
        ++rd[1];
        for(int i=1;i<=n;++i) ++c[rd[i]-1];
        vector<int> fac(n+1),inv(n+1);
        fac[0]=inv[0]=1;
        for(int i=1;i<=n;++i) fac[i]=fac[i-1]*i%mod;
        inv[n]=fast(fac[n],mod-2);
        for(int i=n-1;i>=1;--i) inv[i]=inv[i+1]*(i+1)%mod;
        auto C=[&](int n,int m) -> int 
        {
            if(n<m||m<0) return 0;
            return fac[n]*inv[m]%mod*inv[n-m]%mod;
        };
        vector<int> f(1,1);
        for(int i=n;i>=1;--i) if(c[i])
        {
            vector<int> g(c[i]+1);
            int now=1;
            for(int j=0;j<=c[i];++j)
                g[j]=now*C(c[i],j)%mod,now=now*i%mod;
            f=NTT::mul(f,g);
        }
        int ans=0;
        int len=min(n,(int)f.size());
        for(int i=0;i<len;++i)
        {
            if(i&1) ans-=fac[n-i]*f[i];
            else ans+=fac[n-i]*f[i];
            ans%=mod;
        }
        cout<<(ans+mod)%mod<<'\n';
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
1 2 5 10

*/