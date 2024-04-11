#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define eps (1e-8)
#define lowbit(i) ((i)&(-i))
const int mod=1e9+7;
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1),sum(n+1),xsum(n+1);
    vector<int> nxt(n+2);
    vector<int> pre(n+2);
    nxt[n]=n+1;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
        xsum[i]=xsum[i-1]^a[i];
        if(a[i-1]==0) pre[i]=pre[i-1];
        else pre[i]=i-1;
    }
    for(int i=n-1;i>=1;--i)
    {
        if(a[i+1]==0) nxt[i]=nxt[i+1];
        else nxt[i]=i+1;
    }
    auto check=[&](int l,int r) -> int
    {
        return sum[r]-sum[l-1]-(xsum[r]^xsum[l-1]);
    };
    for(int i=1;i<=m;++i)
    {
        int l,r;
        cin>>l>>r;
        int ans=check(l,r),pl=l,pr=r;
        if(check(r,r)==ans) pl=r,pr=r;
        if(check(l,l)==ans) pl=l,pr=l;
        // cout<<ans<<"!!"<<endl;
        int now=nxt[l];
        while(now<=r)
        {
            int ret=check(now,r);
            if(ret!=ans) break;
            if(r-now<pr-pl) pr=r,pl=now;
            now=nxt[now];
        }
        now=pre[now];
        int tt=r;
        while(now>=l)
        {
            while(tt>=now&&check(now,tt)==ans)
            {
                // cout<<now<<' '<<tt<<"!!!"<<endl;
                if(tt-now<pr-pl) pr=tt,pl=now;
                tt=pre[tt];
                // cout<<tt<<' '<<check(now,tt)<<"!!!!!!"<<endl;
            }
            now=pre[now];
        }
        now=pre[r];
        while(now>=l)
        {
            int ret=check(l,now);
            if(ret!=ans) break;
            if(now-l<pr-pl) pr=now,pl=l;
            now=pre[now];
        }
        cout<<pl<<' '<<pr<<'\n';
        
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;cin>>T;
    while(T--) solve();
    return 0;
}
/*


*/