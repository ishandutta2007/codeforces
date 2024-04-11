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
    const int N=3e5+10,mod=1e9+7,inf=2e9;
    int n,m;
    int a[N],b[N],p[N];
    bool vis[N];
    int ss;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;ss=0;
            for(int i=1;i<=n;++i)
            {
                vis[i]=0;
                cin>>a[i];
                p[a[i]]=i;
            }
            for(int i=1;i<=n;++i)
            {
                cin>>b[i];
            }
            for(int i=1;i<=n;++i)
            {
                if(vis[i]||a[i]==b[i]) continue;
                int sum=0;
                int now=a[i];
                while(!vis[p[now]])
                {
                    vis[p[now]]=1;
                    now=b[p[now]];
                    ++sum;
                }
                ss+=sum/2;
            }
            int ans=0;
            int l=1,r=n;
            while(ss--)
            {
                ans+=2*(r-l);
                ++l,--r;
            }
            cout<<ans<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
6
6
1 5 4 3 2 6
5 3 1 4 6 2
6
3 5 4 6 2 1
3 6 4 5 2 1
1
1
1
6
1 5 4 3 2 6
5 3 1 4 6 2
6
3 5 4 6 2 1
3 6 4 5 2 1
1
1
1

*/