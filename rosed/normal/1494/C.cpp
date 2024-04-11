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
    const int N=1e6+10,mod=998244353,inv2=499122177,inf=2e18;
    void __init(int n=2000) {}
    
    inline void main()
    {
        int n,m;
        cin>>n>>m;
        vector<int> a,c;
        vector<int> b,d;
        for(int i=1;i<=n;++i)
        {
            int x;cin>>x;
            if(x<0) c.emplace_back(-x);
            else a.emplace_back(x);
        }
        for(int i=1;i<=m;++i)
        {
            int x;cin>>x;
            if(x<0) d.emplace_back(-x);
            else b.emplace_back(x);
        }
        reverse(c.begin(),c.end());
        reverse(d.begin(),d.end());
        auto work=[](vector<int> &a,vector<int> &b) -> int
        {
            int n=a.size(),m=b.size();
            map<int,int> q;
            for(int i=0;i<n;++i) q[a[i]]=1;
            int sum=0,ans=0;
            for(int i=m-1;i>=0;--i)
            {
                int pos=b[i];
                int t1=upper_bound(a.begin(),a.end(),pos)-a.begin()-1;
                
                int l=pos-t1;
                int t2=lower_bound(b.begin(),b.end(),l)-b.begin();
                ans=max(ans,sum+i-t2+1);
                sum+=q[b[i]];
            }
            return ans;
        };
        cout<<work(a,b)+work(c,d)<<'\n';
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