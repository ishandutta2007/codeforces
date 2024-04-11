#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-15)
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e18;
    void __init(int n=2000) {}
    inline void main()
    {
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        priority_queue<int> q1,q2;
        for(int i=0;i<n;++i) cin>>a[i],q1.push(a[i]);
        for(int i=0;i<n;++i) cin>>b[i],q2.push(b[i]);
        int ans=0;
        while(!q1.empty())
        {
            int x=q1.top(),y=q2.top();
            q1.pop();q2.pop();
            if(x==y) continue;
            if(x>y) q1.push(log10(x)+1),q2.push(y);
            else q2.push(log10(y)+1),q1.push(x);
            ++ans;
        }
        cout<<ans<<'\n';
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
m/i=(-p%i)*inv[i]

inv[i]*i%p=1

*/