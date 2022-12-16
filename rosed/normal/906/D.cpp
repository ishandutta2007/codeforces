#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=2e6+10,inf=2e9;
    int n,m,mod;
    int a[N],phi[N],num;
    inline int oula(int x)
    {
        int ret=1;
        for(int i=2;i*i<=x;++i)
        {
            if(x%i==0)
            {
                ret*=(i-1),x/=i;
                while(x%i==0) x/=i,ret*=i;
            }
        }
        if(x>1) ret*=x-1;
        return ret;
    }
    inline int fast(int x,int k,int mod)
    {
        int ret=1;
        bool flag1=0,flag2=0;
        while(k)
        {
            if(k&1)
            {
                ret=ret*x;
                if(ret>=mod||flag2) flag1=1,ret%=mod;
            }
            x=x*x;
            if(x>=mod) flag2=1,x%=mod;
            k>>=1;
        }
        return ret+flag1*mod;
    }
    inline int dfs(int l,int r,int now)
    {
        if(now-l>=num||now>r) return 1;
        return fast(a[now],dfs(l,r,now+1),phi[now-l]);
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n>>mod;
        for(int i=1;i<=n;++i) cin>>a[i];
        phi[0]=mod;
        while(phi[num]>1)
        {
            ++num;
            phi[num]=oula(phi[num-1]);
        }
        cin>>m;
        for(int i=1;i<=m;++i)
        {
            int l,r;cin>>l>>r;
            cout<<dfs(l,r,l)%mod<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;   
}
/*
10 20
792708224 4633945 600798790 384332600 283309209 762285205 750900274 160512987 390669628 205259431
1
7 10

*/