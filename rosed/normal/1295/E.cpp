#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-15)
#define y1 uuuu
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e15;
    void __init(int n=2000) {}
    inline void main()
    {
        int n;
        cin>>n;
        vector<int> p(n+1),pos(n+1);
        vector<int> a(n+1);
        for(int i=1;i<=n;++i) cin>>p[i],pos[p[i]]=i;
        for(int i=1;i<=n;++i) cin>>a[p[i]];
        int ret=min(a[p[1]],a[p[n]]);
        int now=0;
        int t=1;
        vector<int> ans(4*n+5),tag(4*n+5);
        auto pushdown=[&](int l,int r,int p) -> void
        {
            ans[ls(p)]+=tag[p];
            ans[rs(p)]+=tag[p];
            tag[ls(p)]+=tag[p];
            tag[rs(p)]+=tag[p];
            tag[p]=0;
        };
        function<void(int,int,int,int,int,int)> update=[&](int tl,int tr,int l,int r,int p,int k) -> void
        {
            if(tl<=l&&r<=tr)
            {
                ans[p]+=k;
                tag[p]+=k;
                return;
            }
            if(tag[p]) pushdown(l,r,p);
            if(tl<=mid) update(tl,tr,l,mid,ls(p),k);
            if(tr>mid) update(tl,tr,mid+1,r,rs(p),k);
            ans[p]=min(ans[ls(p)],ans[rs(p)]);
        };
        typedef array<int,2> pr;
        function<pr(int,int,int,int,int)> query=[&](int tl,int tr,int l,int r,int p) -> pr
        {
            if(tl<=l&&r<=tr) return pr{ans[p],p};
            if(tag[p]) pushdown(l,r,p);
            pr sum={inf,0};
            if(tl<=mid) sum=min(sum,query(tl,tr,l,mid,ls(p)));
            if(tr>mid) sum=min(sum,query(tl,tr,mid+1,r,rs(p)));
            return sum;
        };
        if(pos[1]>1) update(1,pos[1]-1,1,n,1,a[1]);
        for(int i=2;i<=n;++i)
        {
            int w=pos[i];
            update(w,n,1,n,1,a[i]);
        }
        auto tmp=query(1,n-1,1,n,1);
        ret=min(ret,tmp[0]);
        for(int i=2;i<=n;++i)
        {
            update(pos[i],n,1,n,1,-a[i]);
            if(pos[i]>1) update(1,pos[i]-1,1,n,1,a[i]);
            auto tmp=query(1,n-1,1,n,1);
            ret=min(ret,tmp[0]);
        }
        cout<<ret<<'\n';
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