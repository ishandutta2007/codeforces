#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-15)
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e18;
    void __init(int n=2000) {}
    inline void main()
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;++i) cin>>a[i];
        int zero=0;
        for(int i=0;i<n;++i)
        {
            int x;cin>>x;
            a[i]=x-a[i];
        }
        sort(a.begin(),a.end());
        priority_queue<int> q;
        int ans=0;
        for(int i=0;i<n;++i)
        {
            if(!q.empty()&&q.top()+a[i]>=0)
            {
                q.pop();
                ++ans;
            }
            else q.push(a[i]);
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
2 3 4
-4 -5
*/