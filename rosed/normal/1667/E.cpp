#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
//#define mid ((l+r)>>1)
#define eps (1e-15)
    const int N=3e5+10,mod=998244353,inf=2e9;
    int n,m;
    int fac[N],inv[N];
    int dp[N],suf[N],ret[N];
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
    inline int C(int n,int m)
    {
        if(n<m) return 0;
        return fac[n]*inv[m]%mod*inv[n-m]%mod;
    }
    namespace NTT
    {
        const int N=1e6+10,g=3,gi=332748118,mod=998244353;
        int pos[N];
        int limit=1,len;
        inline void ntt(vector<int> &a,int inv)
        {
            //for(int i=0;i<limit;++i) cout<<a[i]<<" \n"[i==limit-1];
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
                        a[j+k]=x+y;
                        if(a[j+k]>=mod) a[j+k]-=mod;
                        a[j+k+mid]=x-y;
                        if(a[j+k+mid]<0) a[j+k+mid]+=mod;
                    }
                }
            }
            if(inv) return;
            inv=fast(limit,mod-2);
            for(int i=0;i<limit;++i) a[i]=a[i]*inv%mod;
        }
        inline vector<int> mul(vector<int> a,vector<int> b)
        {
            int n=a.size(),m=b.size();
            limit=1,len=0;
            while(limit<n+m) limit<<=1,++len;
            for(int i=0;i<limit;++i)
                pos[i]=(pos[i>>1]>>1)|((i&1)<<(len-1));
            a.resize(limit,0),b.resize(limit,0);
            ntt(a,1);ntt(b,1);
            //for(int i=0;i<n;++i) cout<<a[i]<<' '<<b[i]<<'\n';
            for(int i=0;i<limit;++i) a[i]=a[i]*b[i]%mod;
              
            ntt(a,0);
            //for(int i=0;i<limit;++i) cout<<a[i]<<"!!"<<endl;
            //for(int i=n+m-1;i<limit;++i) a[i]=0;
            return a;
        }
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n;m=(n+1)/2;
        fac[0]=inv[0]=1;
        for(int i=1;i<=n;++i) fac[i]=fac[i-1]*i%mod;
        inv[n]=fast(fac[n],mod-2);
        for(int i=n-1;i>=1;--i) inv[i]=inv[i+1]*(i+1)%mod;
        dp[1]=fac[n-1];
        vector<int> a,b,c;
        a.resize(n+1,0),b.resize(n+1,0);
        for(int i=0;i<=n;++i) b[i]=inv[n-i];
        for(int i=2;i<=m;++i) a[i]=fac[i-2];
        //for(int i=0;i<=n;++i) cout<<b[i]<<"!!!"<<endl;
        //reverse(b.begin(),b.end());
        c=NTT::mul(a,b);
        //for(int i=0;i<n;++i) cout<<c[i]<<"!!"<<endl;
        dp[1]=fac[n-1];
        for(int i=2;i<=m;++i)
        {
            dp[i]=c[n+i]*fac[n-i]%mod*(i-1)%mod;
        }
        for(int i=m;i>=1;--i)
        {
            ret[i]=(dp[i]-suf[i+1]*fast(i,mod-2)%mod+mod)%mod;
            suf[i]=(suf[i+1]+ret[i])%mod;
        }
        for(int i=1;i<=n;++i) cout<<ret[i]<<" \n"[i==n];    
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