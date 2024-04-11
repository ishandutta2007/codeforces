#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,mod=201314,inf=2e9;
    int n,m,k;
    vector<int> eg[N];
    int c[N],s[N],b[N];
    int f[N];
    int g[510][510];
    inline int find(int k){return f[k]==k?k:f[k]=find(f[k]);}
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n>>m>>k;
        for(int i=1;i<=k;++i)
        {
            cin>>c[i];
            s[i]=s[i-1]+c[i];
            for(int j=s[i-1]+1;j<=s[i];++j) b[j]=i;
        }
        for(int i=1;i<=n;++i) f[i]=i;
        memset(g,0x3f,sizeof(g));
        for(int i=1;i<=k;++i) g[i][i]=0;
        for(int i=1;i<=m;++i)
        {
            int x,y,z;cin>>x>>y>>z;
            int tx=find(x),ty=find(y);
            if(!z) f[tx]=ty;
            x=b[x],y=b[y];
            if(x!=y) g[x][y]=g[y][x]=min(g[x][y],z);
        }
        bool flag=1;
        for(int i=1;i<=n;++i)
        {
            if(b[i]==b[i-1]) flag&=(find(i)==find(i-1));
        }
        if(!flag)
        {
            cout<<"No\n";
        }
        else
        {
            cout<<"Yes\n";
            n=k;
            for(int k=1;k<=n;++k)
            {
                for(int i=1;i<=n;++i)
                {
                    for(int j=1;j<=n;++j)
                    {
                        g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
                    }
                }
            }
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=n;++j)
                {
                    if(g[i][j]>1e9) g[i][j]=-1;
                    cout<<g[i][j]<<' ';
                }
                cout<<'\n';
            }
        }
    }
}
signed main()
{
    red::main();
    return 0;   
}