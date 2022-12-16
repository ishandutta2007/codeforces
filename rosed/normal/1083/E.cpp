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
    const int N=3e5+10,mod=998244353,inv2=5e8+4,inf=2e9;
    void _init_(int n=2000) {}
    struct node {double x,y,z;};
    inline void main()
    {
        int n;
        cin>>n;
        vector<node> a(n+1);
        for(int i=1;i<=n;++i)
        {
            int x,y,z;cin>>x>>y>>z;
            a[i].x=x,a[i].y=y,a[i].z=z;
            //cin>>a[i].x>>a[i].y>>a[i].z;
        }
        sort(a.begin()+1,a.end(),[](node &i,node &j){return i.x<j.x;});
        vector<int> dp(n+2),q(n+2);
        int head=0,tail=0;
        auto y=[&](int &i) -> double{return dp[i];};
        auto x=[&](int &i) -> double{return a[i].x;};
        auto slope=[&](int &i,int &j) -> double
        {
            return 1.0*(y(i)-y(j))/(x(i)-x(j));
        };
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            while(head<tail&&slope(q[head],q[head+1])>=1.0*a[i].y) ++head;
            int j=q[head];
            dp[i]=dp[j]+(a[i].x-a[j].x)*a[i].y-a[i].z;
            ans=max(ans,dp[i]);
            while(head<tail&&slope(q[tail],q[tail-1])<=slope(q[tail-1],i)) --tail;
            q[++tail]=i;
        }
        cout<<ans<<'\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::_init_();
    int qwq=1; //cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*

*/