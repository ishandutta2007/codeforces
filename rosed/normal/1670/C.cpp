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
    const int N=5e5+10,mod=1e9+7,inf=2e9;
    int n;
    int a[N],b[N],d[N];
    int posa[N],posb[N];
    int f[N],col[N];
    inline int find(int k){return f[k]==k?k:f[k]=find(f[k]);}
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;
            for(int i=1;i<=n;++i)
            {
                f[i]=i;col[i]=0;
                cin>>a[i];
                posa[a[i]]=i;
            }
            for(int i=1;i<=n;++i)
            {
                cin>>b[i];
                posb[b[i]]=i;
                f[find(i)]=find(posa[b[i]]);
            }
            for(int i=1;i<=n;++i)
            {
                cin>>d[i];
                if(d[i]||a[i]==b[i]) col[find(i)]=1;
            }
            int sum=1;
            for(int i=1;i<=n;++i)
            {
                if(find(i)==i&&col[i]==0) sum=sum*2%mod;
            }
            cout<<sum<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
7
1 2 3 4 5 6 7
2 3 1 7 6 5 4
2 0 1 0 0 0 0

2 3 1 0 0 0 0


*/