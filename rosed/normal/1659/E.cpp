#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=4e5+10,mod=998244353,inf=2e9;
    int n,m,k;
    struct node
    {
        int x,y,z;
    }a[N],q[N];
    int f[N];
    bool vis[N];
    inline int find(int k){return f[k]==k?k:f[k]=find(f[k]);}
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n>>m;
        for(int i=1;i<=m;++i)
        {
            cin>>a[i].x>>a[i].y>>a[i].z;
        }
        cin>>k;
        for(int i=1;i<=k;++i)
        {
            cin>>q[i].x>>q[i].y;
            q[i].z=-1;
        }
        for(int b=29;b>=0;--b)
        {
            for(int i=1;i<=n;++i) f[i]=i;
            for(int i=1;i<=m;++i)
            {
                if(((a[i].z>>b)&1)==0) continue;
                int tx=find(a[i].x),ty=find(a[i].y);
                f[tx]=ty;
            }
            for(int i=1;i<=k;++i)
            {
                if(q[i].z!=-1) continue;
                if(find(q[i].x)==find(q[i].y)) q[i].z=0;
            }
        }
        for(int b=29;b>=1;--b)
        {
            for(int i=1;i<=n;++i) f[i]=i,vis[i]=0;
            for(int i=1;i<=m;++i)
            {
                int tmp=(1<<b)|1;
                if((a[i].z&tmp)!=tmp) continue;
                int tx=find(a[i].x),ty=find(a[i].y);
                f[tx]=ty;
            }
            for(int i=1;i<=m;++i)
            {
                if(a[i].z%2==1) continue;
                int tx=find(a[i].x),ty=find(a[i].y);
                vis[tx]=vis[ty]=1;
            }
            for(int i=1;i<=k;++i)
            {
                if(q[i].z!=-1) continue;
                if(vis[find(q[i].x)]) q[i].z=1;
            }
        }
        for(int i=1;i<=k;++i)
        {
            if(q[i].z==-1) q[i].z=2;
            cout<<q[i].z<<'\n';
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
1 2 3 4

*/