#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,mod=998244353,inf=2e9;
    int n,m;
    int a[N];
    int q[10];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int skx;
        cin>>skx;
        while(skx--)
        {
            cin>>n;
            for(int i=0;i<10;++i) q[i]=0;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
                a[i]%=10;
                ++q[a[i]];
            }
            bool flag=0;
            for(int i=0;i<10&&!flag;++i)
            {
                for(int j=0;j<10&&!flag;++j)
                {
                    for(int k=0;k<10&&!flag;++k)
                    {
                        if((i+j+k)%10==3)
                        {
                            --q[i];
                            --q[j];
                            --q[k];
                            if(q[i]>=0&&q[j]>=0&&q[k]>=0) flag=1;
                            ++q[i];
                            ++q[j];
                            ++q[k];
                        }
                    }
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
3 1
1 1 0

*/