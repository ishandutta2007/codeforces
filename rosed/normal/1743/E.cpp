#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-15)
const int mod=998244353;
const int inf=1e18;
void solve()
{
    int p1,t1,p2,t2,h,s;
    cin>>p1>>t1>>p2>>t2>>h>>s;
    typedef array<int,2> pr;
    vector<pr> a;
    for(int x=0;x<=h;++x)
    {
        int tim=(x+1)*t1;
        int y=min(tim/t2,h);
        if(!y) continue;
        int val=min(p1*(x+1)+p2*y-(x+y)*s,h);
        a.emplace_back(pr{tim,val});
    }
    for(int y=0;y<=h;++y)
    {
        int tim=(y+1)*t2;
        int x=min(tim/t1,h);
        if(!x) continue;
        int val=min(p2*(y+1)+p1*x-(x+y)*s,h);
        a.emplace_back(pr{tim,val});
    }
    vector<int> dp(h+1,inf);
    dp[0]=0;
    for(auto [tim,val]:a)
    {
        for(int i=0;i<val;++i) dp[i]=min(dp[i],tim);
        for(int i=val;i<=h;++i) dp[i]=min(dp[i],dp[i-val]+tim);
    }
    int ans=dp[h];
    auto check=[&](int x) -> int
    {
        return min(h,x/t1)*(p1-s)+min(h,x/t2)*(p2-s);
    };
    for(int i=0;i<h;++i)
    {
        int l=0,r=1e18;
        while(l<=r)
        {
            if(check(mid)>=h-i) r=mid-1;
            else l=mid+1;
        }
        // if(i==0) cout<<r<<"!!"<<endl;
        ans=min(ans,dp[i]+r+1);
    }
    cout<<ans<<'\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // red::__init();
    int T=1; //cin>>T;
    while(T--) solve();
    return 0;
}
/*
14

*/