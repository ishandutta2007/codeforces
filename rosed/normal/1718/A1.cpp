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
    const int N=1e6+10,mod=1e9+7,inv2=5e8+4,inf=2e15;
    void __init(int n=2000) {}
    
    inline void main()
    {
        int n;
        cin>>n;
        vector<int> a(n+2),b(n+2);
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            b[i]=b[i-1]^a[i];
        }
        map<int,int> q;
        vector<int> dp(n+1);
        q[0]=0;
        dp[0]=0;
        for(int i=1;i<=n;++i)
        {
            dp[i]=dp[i-1];
            if(q.find(b[i])!=q.end())
            {
                dp[i]=max(dp[i],dp[q[b[i]]]+1);
            }
            q[b[i]]=i;
        }
        cout<<n-dp[n]<<'\n';
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