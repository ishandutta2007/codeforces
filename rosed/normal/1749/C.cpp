#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
#define lowbit(i) ((i)&(-i))
const int mod=1e9+7;
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a.begin()+1,a.end());
    auto check=[&](int m) -> bool
    {
        int l=1,r=n;
        for(int k=m;k>=1;--k)
        {
            while(l<=r&&a[r]>k) --r;
            if(l>r) return 0;
            --r;
            ++l;
        }
        return 1;
    };
    for(int i=n;i>=0;--i)
    {
        if(check(i))
        {
            cout<<i<<'\n';
            return;
        }
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