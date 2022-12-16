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
    const int N=1e6+10,mod=998244353,inv2=499122177,inf=2e18;
    void __init(int n=2000) {}
    
    inline void main()
    {
        int n,a,b,c,d;
        cin>>n>>a>>b>>c>>d;
        bool ans=0;
        for(int s=0;s<16;++s)
        {
            int aa=a,bb=b,cc=c,dd=d;
            if(s&1) --aa,--dd;
            if(s&2) --aa,--bb;
            if(s&4) --bb,--cc;
            if(s&8) --cc,--dd;
            if(aa>=0&&aa<=n-2&&bb>=0&&bb<=n-2&&cc>=0&&cc<=n-2&&dd>=0&&dd<=n-2) ans=1;
        }
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::__init();
    int qwq=1; cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*

*/