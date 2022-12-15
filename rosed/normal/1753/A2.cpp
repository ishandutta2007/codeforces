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
    typedef array<int,2> pr;
    vector<pr> tmp;
    int sum1=0,sum2=0;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        if(a[i]==1) ++sum1;
        if(a[i]==-1) ++sum2;
    }
    // cout<<sum1<<' '<<sum2<<"!!"<<endl;
    if((sum1+sum2)&1)
    {
        cout<<"-1\n";return;
    }

    int pre=1;
    for(int i=2;i<=n;++i)
    {
        if(((a[i]==1&&sum1>sum2)||(a[i]==-1&&sum1<sum2))&&pre==i-1)
        {
            if(a[i]==1) --sum1,++sum2;
            else --sum2,++sum1;
            continue;
        }
        tmp.emplace_back(pr{pre,i-1});
        pre=i;
    }
    tmp.emplace_back(pr{pre,n});
    cout<<tmp.size()<<'\n';
    for(auto [l,r]:tmp) cout<<l<<' '<<r<<'\n';
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