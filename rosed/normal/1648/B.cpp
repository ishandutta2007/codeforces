#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=2e6+10,inf=1e9;
    int n,m;
    int a[N];
    int vis[N];
    int pre[N];
    bool flag=0;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n>>m;flag=1;
            for(int i=1;i<=n;++i) cin>>a[i];
            sort(a+1,a+n+1);
            for(int i=1;i<=n;++i) vis[a[i]]++;
            for(int i=1;i<=2*m;++i) vis[i]+=vis[i-1];
            for(int i=1;i<=m&&flag;++i) if(vis[i]-vis[i-1]>0)
            {
                for(int x=i,k=1;x<=m;x+=i,++k)
                {
                    if((vis[x+i-1]-vis[x-1]>0)&&(vis[k]-vis[k-1]==0))
                    {
                        //cout<<i<<' '<<x+i-1<<' '<<x<<' '<<k<<"!!"<<endl;
                        flag=0;break;
                    }
                }
            }
            for(int i=1;i<=2*m;++i) vis[i]=0;
            if(flag) cout<<"Yes\n";
            else cout<<"No\n";
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
3 5
1 2 5

*/