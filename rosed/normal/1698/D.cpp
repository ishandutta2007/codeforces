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
    const int N=1e6+10,inf=2e9;
    int n,m,ans;
    int a[N];
    bool vis[N];
    map<int,int> q;
    inline void main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int skx;
        cin>>skx;
        while(skx--)
        {
            cin>>n;
            for(int i=1;i<=n;++i) vis[i]=1;
            int l=1,r=n;
            while(l<r)
            {
                int m=mid-l+1;
                int cnt=0;
                cout<<"? "<<l<<' '<<mid<<endl;
                for(int i=0;i<m;++i)
                {
                    int x;cin>>x;
                    if(x>=l&&x<=mid) ++cnt;
                }
                if(cnt&1) r=mid;
                else l=mid+1;
            }
            cout<<"! "<<l<<endl;
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
2.25 10 100

*/