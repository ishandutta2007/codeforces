#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-8)
void solve()
{
    int n;
    cin>>n;
    int sum=(n+1)/2;
    int t1=2,t2=3*n;
    cout<<sum<<'\n';
    while(t1<=t2)
    {
        cout<<t1<<' '<<t2<<'\n';
        t1+=3;
        t2-=3;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}
/*
BBNBAA

BNNBANBAA

*/