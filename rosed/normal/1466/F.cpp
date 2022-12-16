#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=5e5+10,mod=1e9+7,inf=2e9;
    int n,m;
    int f[N];
    int st[N],top;
    inline int find(int k){return f[k]==k?k:f[k]=find(f[k]);}
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
        for(int i=1;i<=m+1;++i) f[i]=i;
        for(int i=1;i<=n;++i)
        {
            int k;cin>>k;int x,y;
            if(k==2) cin>>x>>y;
            else {cin>>x;y=m+1;}
            x=find(x),y=find(y);
            if(x!=y)
            {
                st[++top]=i;
                f[x]=y;
            }
        }
        cout<<fast(2,top)<<' '<<top<<'\n';
        for(int i=1;i<=top;++i) cout<<st[i]<<' ';
            cout<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
5 5
2 5 4
2 4 3
2 3 2
2 2 1
2 5 1

*/