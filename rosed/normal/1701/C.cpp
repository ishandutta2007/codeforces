#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=5e5+10,inf=2e9;
    int n,m;
    int a[N];
    int b[N];
    inline bool check(int x)
    {
        for(int i=1;i<=n;++i) b[i]=0;
        for(int i=1;i<=m;++i)
        {
            ++b[a[i]];
        }
        sort(b+1,b+n+1);
        int t=1;
        for(int i=n;i>=1&&t<=n;--i)
        {
            if(b[i]<=x) return 1;
            while(b[t]+2>x&&t<=n) ++t;
            while(b[i]>x&&t<=n)
            {
                int tmp=min(b[i]-x,(x-b[t])/2);
                b[i]-=tmp;
                b[t]+=tmp*2;
                while(b[t]+2>x&&t<=n) ++t;
            }
        }
        for(int i=1;i<=n;++i) if(b[i]>x) return 0;
        return 1;
    }
    inline void main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int qwq; cin>>qwq;
        while(qwq--)
        {
            cin>>n>>m;
            for(int i=1;i<=m;++i)
            {
                cin>>a[i];
            }
            int l=1,r=2*m;
            while(l<=r)
            {
                if(check(mid)) r=mid-1;
                else l=mid+1;
            }
            cout<<r+1<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
1
2 4
1 1 1 1

*/