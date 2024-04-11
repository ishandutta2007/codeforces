#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
#define lowbit ((i)&(-i))
void solve()
{
    int n;cin>>n;
    vector<int> a(n+1);
    typedef array<int,2> pr;
    priority_queue<pr> q;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        int x=a[i-1]-a[i];
        if(x>0) q.push(pr{x,i});
    }
    vector<int> pos(n+1,n);
    for(int i=n;i>=1;--i)
    {
        if(q.empty()) break;
        int now=q.top()[0],p=q.top()[1];
        q.pop();
        now-=i;
        pos[i]=p;
        if(now>0) q.push(pr{now,p});
    }
    for(int i=1;i<=n;++i) cout<<pos[i]<<" \n"[i==n];
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;cin>>T;
    while(T--) solve();
    return 0;
}