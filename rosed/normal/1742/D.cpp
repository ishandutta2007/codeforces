#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
#define lowbit(i) ((i)&(-i))
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }

    vector<int> vis(1001);
    int ans=-1;
    for(int i=n;i>=1;--i)
    {
        if(vis[a[i]]&&a[i]!=1) continue;
        vis[a[i]]=i;
        for(int j=1;j<=1000;++j)
        {
            if(vis[j]&&__gcd(a[i],j)==1)
            {
                ans=max(ans,vis[j]+i);
            }
        }
    }
    cout<<ans<<"\n";
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
2*3 2*5 2

*/