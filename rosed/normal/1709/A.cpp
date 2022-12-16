#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,inf=2e9,mod=998244353;
    int n,m;
    int a[4];
    int b[4];
    inline void main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int qwq;cin>>qwq;
        while(qwq--)
        {
            int x;cin>>x;
            cin>>a[1]>>a[2]>>a[3];
            b[1]=b[2]=b[3]=0;
            b[x]=1;
            for(int k=1;k<=4;++k)
            {
                for(int i=1;i<=3;++i)
                {
                    if(b[i]) b[a[i]]=1;
                }
            }
            if(!b[1]||!b[2]||!b[3]) cout<<"NO\n";
            else cout<<"YES\n";
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*


*/