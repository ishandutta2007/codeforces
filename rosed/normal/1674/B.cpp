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
    const int N=1e6+10,mod=1e4+7,inf=2e9;
    int n,m,tot;
    int a[N];
    char s[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>s;
            int tmp=(s[0]-'a')*25+(s[1]-'a'+(s[1]<s[0]));
            cout<<tmp<<'\n';
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