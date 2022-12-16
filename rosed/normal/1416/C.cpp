#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,g=3,gi=332748118,mod=998244353,inf=2e9;
    int n;
    int a[N];
    int b[N][2];
    struct trie
    {
        int son[N*20][2],sum[N*20],tot,rt;
        inline void insert(int x,int k,int &p)
        {
            if(!p) p=++tot;
            ++sum[p];
            if(k<0) return;
            int bit=(x>>k)&1;
            if(bit==1) b[k][1]+=sum[son[p][0]];
            else b[k][0]+=sum[son[p][1]]; 
            insert(x,k-1,son[p][bit]);
        }
    }T;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            T.insert(a[i],29,T.rt);
        }
        int ans=0,sum=0;
        for(int k=29;~k;--k)
        {
            if(b[k][0]>b[k][1]) ans|=(1<<k);
            sum+=min(b[k][0],b[k][1]);
        }
        cout<<sum<<' '<<ans<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;   
}
/*
19
1 32 25 40 18 32 5 23 38 1 35 24 39 26 0 9 26 37 0

65 49

*/