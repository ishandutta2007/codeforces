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
    vector<int> a(3);
    cin>>a[0]>>a[1]>>a[2];
    sort(a.begin(),a.end());
    if(a[0]+a[1]==a[2]) cout<<"YES\n";
    else cout<<"NO\n";

}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;cin>>T;
    while(T--) solve();
    return 0;
}