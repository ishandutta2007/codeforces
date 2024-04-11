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
    vector<int> a(n+1),b(n+2);
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    b[1]=a[1];
    for(int i=2;i<=n;++i)
    {
        //gcd(b[i],b[i-1])==a[i-1]
        //b[i]%a[i]==0
        b[i]=a[i-1]*a[i]/__gcd(a[i],a[i-1]);
        if(__gcd(b[i],b[i-1])!=a[i-1])
        {
            cout<<"NO\n";
            return;
        }
    }
    b[n+1]=a[n];
    if(__gcd(b[n],b[n+1])!=a[n])
    {
        cout<<"NO\n";
            return;
    }
    cout<<"YES\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;cin>>T;
    while(T--) solve();
    return 0;
}