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
        int n;cin>>n;
        vector<int> b(n+2);
        int sum1=0,sum2=0,ans1=0,ans2=0;
        for(int i=1;i<=n;++i) cin>>b[i];
        for(int i=1;i<=n;++i)
        {
            sum1-=(b[i]-b[i-1]-1);
            ++sum1;
            ans1=max(ans1,sum1);
            //cout<<sum1<<"!!!"<<'\n';
        }
        b[n+1]=2*n+1;
        for(int i=n;i>=1;--i)
        {
            sum2-=(b[i+1]-b[i]-1);
            ++sum2;
            ans2=max(ans2,sum2);
        }
        //cout<<ans1<<' '<<ans2<<"!!!"<<endl;
        int tl=ans1;
        int tr=n-ans2;
        cout<<tr-tl+1<<'\n';
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