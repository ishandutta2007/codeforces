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
        int n;cin>>n;
        vector<int> a(n+1),c(n+1),pre(n+1),f(n+1),maxn(n+1);
        vector<bool> vis(n+1,0);
        int sum=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            pre[i]=c[a[i]];
            c[a[i]]=i;
            f[i]=i;
        }
        for(int i=1;i<=n;++i) maxn[i]=max(maxn[i-1],c[a[i]]);
        int lst,tl=0;
        for(int i=1;i<n;++i)
        {
            lst=tl;
            if(f[a[i]]>f[a[i+1]]) tl=max(tl,maxn[i]);
            for(int k=lst+1;k<=tl;++k) f[a[k]]=0;
           // cout<<lst<<' '<<tl<<"!!!"<<endl;
        }
        vector<int> u(n+1);
        for(int i=1;i<=tl;++i)
        {
            if(!u[a[i]]) ++sum,u[a[i]]=1;
        }
        cout<<sum<<'\n';
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