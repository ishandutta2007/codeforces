// LUOGU_RID: 94413636
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-9)
const int mod=998244353;
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    bool ok=1;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        if(a[i]>m) ok=0;
        if(i>1&&a[i]>a[i-1]) ok=0;
        if(a[i-1]%a[i]!=0) ok=0;
    }
    if(!ok)
    {
        cout<<0<<'\n';return;
    }
    int ans=1;
    vector<int> tmp;
    auto phi=[&](int x) -> void
    {
        tmp.clear();
        for(int i=2;i*i<=x;++i)
        {
            if(x%i==0)
            {
                tmp.emplace_back(i);
                while(x%i==0) x/=i;
            }
        }
        if(x>1) tmp.emplace_back(x);
    };
    for(int i=2;i<=n;++i)
    {
        phi(a[i-1]/a[i]);
        int sum=0,tot=tmp.size();
        int S=(1<<tot);
        for(int s=0;s<S;++s)
        {
            int num=1,opt=1;
            for(int k=0;k<tot;++k) if((s>>k)&1)
            {
                num=num*tmp[k];
                opt=-opt;
            }
            sum+=opt*((m/a[i])/num);
        }
        sum=(sum%mod+mod)%mod;
        ans=ans*sum%mod;
    }
    cout<<ans<<'\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}