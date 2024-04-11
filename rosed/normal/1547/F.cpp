#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-15)
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e15;
    void __init(int n=2000) {}
    inline void main()
    {
        int n;
        cin>>n;
        vector<int> a(n);
        set<int> q,p;
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;++i)
        {
            int j=(i+1)%n;
            if(a[i]!=a[j]) q.insert(i);
        }
        int ans=0;
        while(!q.empty())
        {
            ++ans;
            auto it=q.begin();
            int zero=a[0];
            while(it!=q.end())
            {
                int x=*it;
                if(x!=n-1) a[x]=__gcd(a[x],a[x+1]);
                else a[x]=__gcd(a[x],zero);
                ++it;
            }
            it=q.begin();
            while(it!=q.end())
            {
                int x=*it,l=(x-1+n)%n,r=(x+1)%n;
                if(a[l]!=a[x]) p.insert(l);
                if(a[x]!=a[r]) p.insert(x);
                ++it;
            }
            q=p;
            p.clear();
        }
        cout<<ans<<'\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::__init();
    int qwq=1; cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*

*/