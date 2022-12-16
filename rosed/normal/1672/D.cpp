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
    int n;
    int a[N],b[N];
    int pre[N],c[N];
    bool vis[N];
    int sum[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;
            bool flag=1;
            for(int i=1;i<=n;++i) vis[i]=0,sum[i]=0;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
            }
            for(int i=1;i<=n;++i) cin>>b[i];
            int t=1;
            for(int i=1;i<=n;++i)
            {
                //cout<<t<<' '<<i<<"!!"<<endl;
                if(a[t]==b[i]&&t<=n) {++t;continue;}
                if(b[i]==b[i-1]&&sum[b[i]]>0)
                {
                    --sum[b[i]];
                }
                else
                {
                    while(t<=n&&a[t]!=b[i])
                    {
                        ++sum[a[t++]];
                    }
                    if(t>n){flag=0;break;}
                    ++t;
                }
            }
            if(flag) cout<<"YES\n";
            else cout<<"NO\n";
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
5
1 2 3 3 2
1 3 3 2 2


1
6
1 1 2 4 2 1
4 1 2 2 1 1

2 4 2 1 1 1
4 1 2 2 1 1


*/