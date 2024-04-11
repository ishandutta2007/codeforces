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
    vector p(30,vector<int>(n+1));
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
        xsum[i]=xsum[i-1]^a[i];
        for(int k=0;k<30;++k)
        {
            p[k][i]=p[k][i-1]+((a[i]>>k)&1);
        }
    }
    auto check=[&](int l,int r) -> int
    {
        return sum[r]-sum[l-1]-(xsum[r]^xsum[l-1]);
    };
    for(int i=1;i<=m;++i)
    {
        int l,r;
        cin>>l>>r;
        int ans=0,pl=l,pr=l;
        for(int t=l;t<=r;++t)
        {
            int tl=l,tr=t;
            while(tl<=tr)
            {
                int mid=(tl+tr)>>1;
                if(check(mid,t)==check(l,t)) tl=mid+1;
                else tr=mid-1;
            }
            --tl;
            int val=check(tl,t);
            // cout<<val<<' '<<ans<<' '<<tl<<' '<<t<<"!!"<<endl;
            if(val>ans||(val==ans&&t-tl<pr-pl))
            {
                ans=val;
                pr=t,pl=tl;
            }
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