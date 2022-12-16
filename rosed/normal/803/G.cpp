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
#define y1 uuuu
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e15;
    void __init(int n=2000) {}
    inline void main()
    {
        int n,k;
        cin>>n>>k;
        vector<int> a(n+1);
        vector<int> pre(n+2,inf),suf(n+2,inf);
        vector f(n+1,vector<int>(20));
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            f[i][0]=a[i];
            pre[i]=min(pre[i-1],a[i]);
        }
        for(int k=1;k<20;++k)
        {
            for(int i=1;i+(1<<k)-1<=n;++i)
            {
                f[i][k]=min(f[i][k-1],f[i+(1<<(k-1))][k-1]);
            }
        }
        auto getmin=[&](int l,int r) -> int
        {
            int k=__lg(r-l+1);
            return min(f[l][k],f[r-(1<<k)+1][k]);
        };
        for(int i=n;i>=1;--i) suf[i]=min(suf[i+1],a[i]);
        int m;cin>>m;
        typedef array<int,4> pr;
        vector<pr> q(m+1);
        vector<int> c;
        c.emplace_back(0);
        for(int i=1;i<=m;++i)
        {
            cin>>q[i][3];
            cin>>q[i][0]>>q[i][1];
            if(q[i][3]==1) cin>>q[i][2];
            c.emplace_back(q[i][0]-1);
            c.emplace_back(q[i][1]);
        }
        sort(c.begin(),c.end());
        c.erase(unique(c.begin(),c.end()),c.end());
        for(int i=1;i<=m;++i)
        {
            q[i][0]=lower_bound(c.begin(),c.end(),q[i][0])-c.begin()+1;
            q[i][1]=lower_bound(c.begin(),c.end(),q[i][1])-c.begin()+1;
           //cout<<q[i][0]<<' '<<q[i][1]<<"!!!"<<endl;
        }
        int num=c.size();
        vector<int> ans(4*num+5),tag(4*num+5);
        auto work=[&](int l,int r) -> int
        {
            int t1=(l-1)/n,t2=(r-1)/n,t=l-t1*n,tt=r%n;
            if(tt==0) tt=n;
            if(t1+1<t2) return pre[n];
            if(t1==t2)
            {
                //cout<<l<<' '<<r<<' '<<t<<' '<<tt<<"!!"<<endl;
                return getmin(t,tt);
            }
            return min(pre[tt],suf[t]);
        };
        function<void(int,int,int)> build=[&](int l,int r,int p) -> void
        {
            if(l==r)
            {
                if(l==1) ans[p]=0;
                else ans[p]=work(c[l-2]+1,c[l-1]);
                //if(l>1) cout<<l<<' '<<c[l-2]+1<<' '<<c[l-1]<<' '<<ans[p]<<"??????"<<endl;
                return;
            }
            build(l,mid,ls(p));
            build(mid+1,r,rs(p));
            ans[p]=min(ans[ls(p)],ans[rs(p)]);
        };
        auto pushdown=[&](int l,int r,int p) -> void
        {
            tag[ls(p)]=tag[rs(p)]=ans[ls(p)]=ans[rs(p)]=tag[p];
            tag[p]=0;
        };
        function<void(int,int,int,int,int,int)> update=[&](int tl,int tr,int l,int r,int p,int k) -> void
        {
            if(tl<=l&&r<=tr)
            {
                ans[p]=k;
                tag[p]=k;
                return;
            }
            if(tag[p]) pushdown(l,r,p);
            if(tl<=mid) update(tl,tr,l,mid,ls(p),k);
            if(tr>mid) update(tl,tr,mid+1,r,rs(p),k);
            ans[p]=min(ans[ls(p)],ans[rs(p)]);
        };
        function<int(int,int,int,int,int)> query=[&](int tl,int tr,int l,int r,int p) -> int
        {
            if(tl<=l&&r<=tr) {return ans[p];}
            if(tag[p]) pushdown(l,r,p);
            int sum=inf;
            if(tl<=mid) sum=min(sum,query(tl,tr,l,mid,ls(p)));
            if(tr>mid) sum=min(sum,query(tl,tr,mid+1,r,rs(p)));
            return sum;
        };
        build(1,num,1);
        for(int i=1;i<=m;++i)
        {
            if(q[i][3]==1) update(q[i][0],q[i][1],1,num,1,q[i][2]);
            else cout<<query(q[i][0],q[i][1],1,num,1)<<'\n';
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