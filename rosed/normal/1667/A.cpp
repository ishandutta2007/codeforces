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
    const int N=3e5+10,mod=998244353,inf=2e9;
    int n,m;
    int a[N];
    int b[N],c[N],pre[N],suf[N];
    int ans=inf*inf;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;++i)
        {
            int ret=0,sum=0;
            for(int j=i-1;j>=1;--j)
            {
                int tmp=sum/a[j];
                if(tmp*a[j]<=sum) ++tmp;
                ret+=tmp;
                sum=tmp*a[j];
                //cout<<ret<<' '<<sum<<"!!"<<endl;
            }
            sum=0;
            for(int j=i+1;j<=n;++j)
            {
                int tmp=sum/a[j];
                if(tmp*a[j]<=sum) ++tmp;
                ret+=tmp;
                sum=tmp*a[j];
                //cout<<ret<<' '<<sum<<"!!"<<endl;
            }
           // cout<<"----"<<endl;
            ans=min(ans,ret);
        } 
        cout<<ans<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
1
1 2 3 4

*/