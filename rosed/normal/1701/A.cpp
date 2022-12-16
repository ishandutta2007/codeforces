#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=5e5+10,inf=2e9;
    int n,m;
    int a[N];
    inline void main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int qwq; cin>>qwq;
        while(qwq--)
        {
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            if(a==0&&b==0&&c==0&&d==0) cout<<0<<'\n';
            else if(a==1&&b==1&&c==1&&d==1) cout<<2<<'\n';
            else cout<<1<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*


1*2+3+4+5+6+7+8
*/