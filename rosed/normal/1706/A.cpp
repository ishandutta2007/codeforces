#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,inf=2e9,mod=998244353;
    int n,m;
    bool vis[N];
    char s[N];
    inline void main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int qwq;cin>>qwq;
        while(qwq--)
        {
            cin>>n>>m;
            for(int i=1;i<=m;++i) vis[i]=0;
            for(int i=1;i<=n;++i)
            {
                int x;cin>>x;
                int y=m-x+1;
                if(x>y) swap(x,y);
                if(!vis[x]) vis[x]=1;
                else vis[y]=1;
            }
            for(int i=1;i<=m;++i)
            {
                if(vis[i]) cout<<'A';
                else cout<<'B';
            }
            cout<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*


*/