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
        vector<int> a(n+1),c(n+2),id(n+1);
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            c[i]=a[i];
        }
        int num=n;
        c[++num]=1e9;
        sort(c.begin()+1,c.end());
        c.erase(unique(c.begin()+1,c.end()),c.end());
        vector<int> ans(num<<2|1);
        function<void(int,int,int,int,int)> update=[&](int pos,int l,int r,int p,int k) -> void
        {
            ans[p]+=k;
            if(l==r) return;
            if(pos<=mid) update(pos,l,mid,ls(p),k);
            else update(pos,mid+1,r,rs(p),k);
        };
        function<int(int,int,int,int)> query=[&](int l,int r,int p,int k) -> int
        {
            if(l==r) return l;
            if(ans[ls(p)]>k) return query(l,mid,ls(p),k);
            return query(mid+1,r,rs(p),k-ans[ls(p)]);
        };
        for(int i=1;i<=n;++i)
        {
            a[i]=lower_bound(c.begin()+1,c.end(),a[i])-c.begin();
            update(a[i],1,num,1,1);
        }
        int ret=0;
        for(int i=1;i<n;++i)
        {
            int x=a[i],y=a[i+1];
            if(x>y) swap(x,y);
            update(x,1,num,1,-1);
            update(y,1,num,1,-1);
            int tmp=query(1,num,1,m);
            ret=max(ret,min(2*c[tmp],c[x]));
            if(m>=1)
            {
                tmp=query(1,num,1,m-1);
                ret=max(ret,min(2*c[tmp],c[y]));
            }
            if(m>=2)
            {
                tmp=query(1,num,1,m-2);
                ret=max(ret,min(2*c[tmp],1000000000ll));
            }
            update(x,1,num,1,1);
            update(y,1,num,1,1);
        }
        cout<<ret<<'\n';
        
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::__init();
    int qwq=1; cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*

*/