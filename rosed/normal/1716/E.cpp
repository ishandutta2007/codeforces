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
    const int N=3e5+10,mod=998244353,inv2=5e8+4,inf=2e9;
    struct node
    {
        int sum,pre,suf,ans;
        void update(node &t1,node &t2)
        {
            sum=t1.sum+t2.sum;
            pre=max(t1.pre,t1.sum+t2.pre);
            suf=max(t2.suf,t2.sum+t1.suf);
            ans=max(t1.suf+t2.pre,max(t1.ans,t2.ans));
        }
    };
    vector<node> dp[N<<2];
    void build(int l,int r,int p,int k)
    {
        dp[p].resize(r-l+1);
        if(l==r)
        {
            int x;cin>>x;
            dp[p][0]=(node){x,max(0ll,x),max(0ll,x),max(0ll,x)};
            return;
        }
        build(l,mid,ls(p),k-1);
        build(mid+1,r,rs(p),k-1);
        for(int i=0;i<r-l+1;++i)
        {
            if((i>>k)&1)
            {
                dp[p][i].update(dp[rs(p)][i^(1<<k)],dp[ls(p)][i^(1<<k)]);
            }
            else
            {
                dp[p][i].update(dp[ls(p)][i],dp[rs(p)][i]);
            }
        }
    }
    inline void main()
    {
        int n,m;cin>>n;
        m=(1<<n);
        build(1,m,1,n-1);
        int q,tmp=0;cin>>q;
        while(q--)
        {
            int x;cin>>x;
            tmp^=(1<<x);
            cout<<dp[1][tmp].ans<<'\n';
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::main();
    return 0;
}
/*

*/