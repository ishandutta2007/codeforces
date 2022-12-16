#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,mod=201314,inf=2e9;
    int n,x,y;
    int a[N];
    bool f[N][4];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n>>x>>y;
            x=x&3,y=y&3;
            f[0][x]=1;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
                a[i]=a[i]&3;
                for(int k=0;k<4;++k)
                {
                    int tmp=k^a[i];
                    f[i][tmp]|=f[i-1][k];
                    tmp=(k+a[i])&3;
                    f[i][tmp]|=f[i-1][k];
                }
                // for(int k=0;k<4;++k)
                // {
                //     cout<<i<<' '<<k<<' '<<f[i][k]<<"!!"<<endl;
                // }
            }
            if(f[n][y]) cout<<"Alice\n";
            else cout<<"Bob\n";
            for(int i=0;i<=n;++i)
                f[i][0]=f[i][1]=f[i][2]=f[i][3]=0;
        }
    }
}
signed main()
{
    red::main();
    return 0;   
}