#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-15)
    const int N=3e5+10,inf=2e9,mod=998244353,g=3,gi=332748118;
    int n,m,k;
    int sum=0;
    int a[N],b[N];
    int c[N];
    inline bool check(int n,int m,int *a)
    {
        int minn=0,maxn=0;
        int tot=0;
        for(int i=1;i<=k;++i)
        {
            c[i]=a[i]/n;
            if(c[i]>=2) maxn+=c[i],minn+=2,++tot;
            if(minn<=m&&m<=maxn) return 1;
            if(maxn-tot*2<=m&&m<=maxn)
            {
                if((maxn-m)%2==0||(minn-m)%2==0||maxn!=minn) return 1;
            }
        }
        return 0;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int qwq;cin>>qwq;
        while(qwq--)
        {
            cin>>n>>m>>k;
            sum=0;
            for(int i=1;i<=k;++i)
            {
                cin>>a[i];
                b[i]=a[i];
                sum+=a[i];
            }
            if(sum>=n*m&&(check(n,m,a)||check(m,n,b))) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
1
3 3 2
6 9

1
5 5 3
10 10 20


1
3 3 2
8 8

*/