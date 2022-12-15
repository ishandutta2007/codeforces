#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-15)
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n+1);
    a[1]=1;
    a[n]=2;
    for(int i=2;i<n;++i) a[i]=i+1;
    for(int i=1;i<=n;++i) cout<<a[i]<<" \n"[i==n];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // red::__init();
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}
/*
m/i=(-p%i)*inv[i]

inv[i]*i%p=1

*/