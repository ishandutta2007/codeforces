#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-15)
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e18;
    void __init(int n=2000) {}
    inline void main()
    {
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;++i) cin>>a[i];
        for(int i=0;i<n;++i) cin>>b[i];
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        vector<int> h(n);
        int p1,p2;
        auto check=[&](int x) -> bool
        {
            p1=0,p2=x;
            multiset<int> q1,q2;
            for(int i=0;i<n;++i) q1.insert(a[i]),q2.insert(b[i]);
            int t=0;
            while(!q1.empty())
            {
                auto it1=prev(q1.end()),it2=prev(q2.end());
                int t1=*it1;
                int t2=*it2;
                if(t1>=t2&&t1>x)
                {
                    auto it=q2.lower_bound(t1-x);
                    if(it==q2.end()||(*it)!=t1-x) return 0;
                    h[t++]=t1;
                    q1.erase(it1);
                    q2.erase(it);
                }
                else if(t2>x)
                {
                    auto it=q1.lower_bound(t2-x);
                    if(it==q1.end()||(*it)!=t2-x) return 0;
                    h[t++]=-(t2-x);
                    q1.erase(it);
                    q2.erase(it2);
                }
                else break;
            }
            while(!q1.empty())
            {
                int t1=*q1.begin();
                auto it=q2.lower_bound(x-t1);
                if(it==q2.end()||(*it)!=x-t1) return 0;
                h[t++]=t1;
                q1.erase(q1.begin());
                q2.erase(it);
            }
            return 1;
        };
        for(int i=0;i<n;++i)
        {
            if(i>0&&b[i]==b[i-1]) continue;
            int x=a[0]+b[i];
            if(check(x))
            {
                cout<<"YES\n";
                int minn=0;
                for(int i=0;i<n;++i) minn=min(minn,h[i]);
                minn=-minn;
                sort(h.begin(),h.end());
                for(int i=0;i<n;++i)
                {
                    int x=h[i]+minn;
                    assert(x>=0&&x<=2e9);
                    cout<<h[i]+minn<<' ';
                }
                cout<<'\n';
                cout<<p1+minn<<' '<<p2+minn<<'\n';
                return;
            }
            x=abs(a[0]-b[i]);
            if(check(x))
            {
                cout<<"YES\n";
                int minn=0;
                for(int i=0;i<n;++i) minn=min(minn,h[i]);
                minn=-minn;
                sort(h.begin(),h.end());
                for(int i=0;i<n;++i)
                {
                    int x=h[i]+minn;
                    assert(x>=0&&x<=2e9);
                    cout<<h[i]+minn<<' ';
                }
                cout<<'\n';
                cout<<p1+minn<<' '<<p2+minn<<'\n';
                return;
            }
        }
        cout<<"NO\n";
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
1 n/2 -> (1,n/2),(1,n/2+1)
3,n/2+1 -> (1,n/2-1),(1,n/2+2);
3,n-3 -> (1,n-6)
4,n-4 -> (1,n-3)

*/