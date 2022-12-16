#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-15)
    const int N=5e5+10,mod=998244353,inf=2e9;
    int n,m;
    char s[N],t[N];
    vector<int> a[6],b[6],ff,g;
    int ans[N];
    int f[N*6],idx;
    inline int find(int k)
    {
        return f[k]==k?k:f[k]=find(f[k]);
    }
    const int gi=332748118;
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
            int Wn=fast(inv?3:gi,(mod-1)/(mid<<1));
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
    inline vector<int> add(vector<int> a,vector<int> b,int n,int m)
    {
        limit=max(n,m);
        a.resize(limit),b.resize(limit);
        for(int i=0;i<limit;++i) a[i]=(a[i]+b[i])%mod;
        return a;
    }
    inline vector<int> mul(vector<int> a,vector<int> b,int n,int m)
    {
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
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>(s)>>(t);
        n=strlen(s),m=strlen(t);
        for(int i=0;i<n;++i)
        {
            for(int k=0;k<6;++k)
            {
                a[k].emplace_back((s[i]-'a')==k);
            }
        }
        for(int i=0;i<m;++i)
        {
            for(int k=0;k<6;++k)
            {
                b[k].emplace_back((t[i]-'a')==k);
            }
        }
        for(int k=0;k<6;++k) reverse(b[k].begin(),b[k].end());
        while(limit<n+m) limit<<=1,++len;
        for(int k=0;k<6;++k)
        {
            a[k].resize(limit,0),b[k].resize(limit,0);
        }
        for(int i=0;i<limit;++i) pos[i]=(pos[i>>1]>>1)|((i&1)<<(len-1));
        for(int k=0;k<6;++k)
        {
            a[k]=ntt(a[k],1);
            b[k]=ntt(b[k],1);
        }
        ff.resize(limit),g.resize(limit);
        for(int i=0;i<n-m+1;++i)
        {
            for(int k=0;k<6;++k) f[i*6+k+1]=i*6+k+1;
        }
        for(int t1=0;t1<6;++t1)
        {
            for(int t2=t1+1;t2<6;++t2)
            {
                int x=t1,y=t2;
                for(int i=0;i<limit;++i) ff[i]=a[x][i]*b[y][i]%mod;
                ff=ntt(ff,0);
                swap(x,y);
                for(int i=0;i<limit;++i) g[i]=a[x][i]*b[y][i]%mod;
                g=ntt(g,0);
                for(int i=0;i<n-m+1;++i)
                {
                    if(ff[i+m-1]|g[i+m-1])
                    {
                        if(find(i*6+x+1)!=find(i*6+y+1))
                        {
                            f[find(i*6+x+1)]=find(i*6+y+1);
                            ++ans[i];
                        }
                    }
                }
            }
        }
        for(int i=0;i<n-m+1;++i) cout<<ans[i]<<' ';
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
abcd
bcda

*/