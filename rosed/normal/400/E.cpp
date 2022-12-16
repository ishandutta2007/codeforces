#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=1e5+10,mod=201314,inf=2e9;
    int n,m,ret;
    int a[N];
    struct node
    {
        int ans[N<<2],pre[N<<2],suf[N<<2];
        inline int dx(int x){return (1+x)*x/2;}
        inline void pushup(int l,int r,int p)
        {
            ans[p]=ans[ls(p)]+ans[rs(p)];
            ans[p]-=dx(suf[ls(p)]);
            ans[p]-=dx(pre[rs(p)]);
            ans[p]+=dx(suf[ls(p)]+pre[rs(p)]);
            pre[p]=(pre[ls(p)]==(mid-l+1)?pre[ls(p)]+pre[rs(p)]:pre[ls(p)]);
            suf[p]=(suf[rs(p)]==(r-mid)?suf[rs(p)]+suf[ls(p)]:suf[rs(p)]);
        }
        inline void update(int pos,int l,int r,int p,int k)
        {
            if(l==r)
            {
                ans[p]=pre[p]=suf[p]=k;
                return;
            }
            if(pos<=mid) update(pos,l,mid,ls(p),k);
            else update(pos,mid+1,r,rs(p),k);
            pushup(l,r,p);
        }
    }T[18];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n>>m;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            for(int k=0;k<=17;++k)
            {
                T[k].update(i,1,n,1,(a[i]>>k)&1);
            }
        }
        for(int i=1;i<=m;++i)
        {
            int x;cin>>x>>a[x];
            ret=0;
            for(int k=0;k<=17;++k)
            {
                T[k].update(x,1,n,1,(a[x]>>k)&1);
                ret+=(1<<k)*T[k].ans[1];
            }
            cout<<ret<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;   
}