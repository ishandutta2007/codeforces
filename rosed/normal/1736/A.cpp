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
    int sum1=0,sum2=0;
    for(int i=1;i<=n;++i)
    {
        int x;cin>>x;
        if(a[i]==x) continue;
        if(a[i]) ++sum1;
        else ++sum2;
    }
    cout<<min(abs(sum1-sum2)+1,sum1+sum2)<<'\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;cin>>T;
    while(T--) solve();
    return 0;
}