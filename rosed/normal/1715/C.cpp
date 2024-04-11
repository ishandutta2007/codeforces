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
    const int N=1e6+10,mod=1e9+7,inv2=5e8+4,inf=2e15;
    void __init(int n=2000) {}
    
    inline void main()
    {
        int n,m;
        cin>>n>>m;
        vector<int> a(n+1);
        for(int i=1;i<=n;++i) cin>>a[i];
        vector<int> ans(4*n+1),pre(4*n+1),suf(4*n+1);
        function<void(int,int,int)> build=[&](int l,int r,int p) -> void
        {
            if(l==r)
            {
                ans[p]=l*(n-l+1);
                suf[p]=pre[p]=a[l];
                return;
            }
            build(l,mid,ls(p));
            build(mid+1,r,rs(p));
            ans[p]=ans[ls(p)]+ans[rs(p)];
            if(suf[ls(p)]==pre[rs(p)])
            {
                ans[p]-=mid*(n-mid);
            }
            pre[p]=pre[ls(p)],suf[p]=suf[rs(p)];
        };
        build(1,n,1);
        function<void(int,int,int,int,int)> update=[&](int pos,int l,int r,int p,int k) ->void
        {
            if(l==r)
            {
                ans[p]=l*(n-l+1);
                suf[p]=pre[p]=k;
                return;
            }
            if(pos<=mid) update(pos,l,mid,ls(p),k);
            else update(pos,mid+1,r,rs(p),k);
            ans[p]=ans[ls(p)]+ans[rs(p)];
            if(suf[ls(p)]==pre[rs(p)])
            {
                ans[p]-=mid*(n-mid);
            }
            pre[p]=pre[ls(p)],suf[p]=suf[rs(p)];
        };
        for(int i=1;i<=m;++i)
        {
            int x,y;
            cin>>x>>y;
            update(x,1,n,1,y);
            cout<<ans[1]<<'\n';
        }
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