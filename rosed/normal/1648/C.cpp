#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=4e5+10,inf=1e9,mod=998244353;
    int n,m,ans,ret,v[N];
    int a[N],b[N];
    int c[N],fac[N],inv[N];
    struct segment_tree
    {
        int ans[N<<2],tag[N<<2];
        inline void build(int l,int r,int p)
        {
            tag[p]=1;
            if(l==r)
            {
                ans[p]=v[l];
                return;
            }
            build(l,mid,ls(p));
            build(mid+1,r,rs(p));
            ans[p]=(ans[ls(p)]+ans[rs(p)])%mod;
        }
        inline void pushdown(int l,int r,int p)
        {
            ans[ls(p)]=ans[ls(p)]*tag[p]%mod;
            ans[rs(p)]=ans[rs(p)]*tag[p]%mod;
            tag[ls(p)]=tag[ls(p)]*tag[p]%mod;
            tag[rs(p)]=tag[rs(p)]*tag[p]%mod;
            tag[p]=1;
        }
        inline void update(int tl,int tr,int l,int r,int p,int k)
        {
            if(tl<=l&&r<=tr)
            {
                ans[p]=(ans[p]*k)%mod;
                tag[p]=(tag[p]*k)%mod;
                return;
            }
            if(tag[p]!=1) pushdown(l,r,p);
            if(tl<=mid) update(tl,tr,l,mid,ls(p),k);
            if(tr>mid) update(tl,tr,mid+1,r,rs(p),k);
            ans[p]=(ans[ls(p)]+ans[rs(p)])%mod;
        }
        inline int query(int tl,int tr,int l,int r,int p)
        {
            if(tl<=l&&r<=tr) return ans[p];
            if(tag[p]!=1) pushdown(l,r,p);
            int sum=0;
            if(tl<=mid) sum+=query(tl,tr,l,mid,ls(p));
            if(tr>mid) sum+=query(tl,tr,mid+1,r,rs(p));
            return sum;
        }
    }T;
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
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n>>m;
        fac[0]=inv[0]=1;
        int len=max(n,m);
        for(int i=1;i<=len;++i) fac[i]=fac[i-1]*i%mod;
        inv[len]=fast(fac[len],mod-2);
        for(int i=len-1;i;--i) inv[i]=inv[i+1]*(i+1)%mod; 
        for(int i=1;i<=n;++i) {cin>>a[i];++c[a[i]];}
        for(int i=1;i<=m;++i) cin>>b[i];
        ret=fac[n-1];
        for(int i=1;i<=200000;++i)
        {
            ret=ret*inv[c[i]]%mod;
        }
        for(int i=1;i<=200000;++i)
        {
            if(c[i]) v[i]=ret*fac[c[i]]%mod*inv[c[i]-1]%mod;
            //if(c[i]) cout<<i<<' '<<ret*fac[c[i]]%mod*inv[c[i]-1]%mod<<' '<<v[i]<<"!!"<<endl;
        }
        T.build(1,200000,1);
        for(int i=1;i<=n&&i<=m;++i)
        {
            if(b[i]>1) ans=(ans+T.query(1,b[i]-1,1,200000,1))%mod;
            //cout<<ans<<"!!"<<endl;
            if(!c[b[i]]) break;
            
            if(b[i]>1) T.update(1,b[i]-1,1,200000,1,fac[c[b[i]]]*inv[c[b[i]]-1]%mod);
            if(b[i]<200000) T.update(b[i]+1,200000,1,200000,1,fac[c[b[i]]]*inv[c[b[i]]-1]%mod);
            --c[b[i]];
            if(c[b[i]]>1) T.update(b[i],b[i],1,200000,1,fac[c[b[i]]]*inv[c[b[i]]-1]%mod);
            if(!c[b[i]]) T.update(b[i],b[i],1,200000,1,0);
            T.update(1,200000,1,200000,1,fac[n-i-1]*inv[n-i]%mod);
            //cout<<fac[c[b[i]]]<<' '<<inv[c[b[i]]-1]<<' '<<fac[n-i-1]<<' '<<inv[n-i]<<"!!!!"<<endl;
            //cout<<T.query(1,1,1,200000,1)<<'\n';
            if(i==n&&m!=n) ++ans;
        }
        cout<<(ans%mod+mod)%mod<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;   
}
/*
4 4
1 2 2 3
2 1 2 1

*/