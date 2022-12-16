#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-8)
    const int N=1e6+10,inf=2e9,mod=998244353,g=3,gi=332748118;
    int n,k,f;
    int pos[N];
    int limit,len;
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
                    a[j+k]=x+y;
                    if(a[j+k]>=mod) a[j+k]-=mod;
                    a[j+k+mid]=x-y;
                    if(a[j+k+mid]<0) a[j+k+mid]+=mod;
                }
            }
        }
        if(inv) return a;
        inv=fast(limit,mod-2);
        for(int i=0;i<limit;++i) a[i]=a[i]*inv%mod;
        return a;
    }
    inline vector<int> mul(vector<int> a,vector<int> b,int n,int m)
    {
        limit=1,len=0;
        while(limit<=n+m) limit<<=1,++len;
        for(int i=0;i<limit;++i)
            pos[i]=(pos[i>>1]>>1)|((i&1)<<(len-1));
        a.resize(limit+1),b.resize(limit+1);
        // cout<<n<<' '<<m<<' '<<limit<<"!!"<<endl;
        // for(int i=0;i<=limit;++i)
        // {
        //     cout<<a[i]<<' '<<b[i]<<"???"<<endl;
        // }
        a=ntt(a,1);b=ntt(b,1);
        vector<int> c(limit+1,0);
        for(int i=0;i<=limit;++i)
        {
            c[i]=a[i]*b[i]%mod;
        }
        c=ntt(c,0);
        // for(int i=0;i<=limit;++i) cout<<c[i]<<' ';
        //     cout<<endl;
        return c;
    }
    inline void main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        cin>>n>>k>>f;
        if(f>2*k)
        {
            cout<<0<<'\n';
            return;
        }
        vector<int> F(k+1,1);
        for(int i=1;i<=n;++i)
        {
            vector<int> FF=mul(F,F,k,k);
            if(i==n) F=FF;
            else
            {
                vector<int> F2(k+1,0);
                int sum=0;
                for(int j=2*k;j>=0;--j)
                {
                    if(j<=k)
                    {
                        F2[j]=(sum+FF[j]*(k-j+1))%mod;
                    }
                    sum+=FF[j];
                    sum%=mod;
                }
                swap(F,F2);
            }
        }
        cout<<F[f]<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;
}
/*


*/