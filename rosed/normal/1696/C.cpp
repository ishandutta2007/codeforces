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
    int n,m,x,ans;
    int nn,mm;
    int a[N],b[N];
    map<int,bool> q;
    struct node
    {
        int x,y;
    }c[N],d[N];
    inline bool check()
    {
        if(nn!=mm) return 0;
        for(int i=1;i<=nn;++i) if(c[i].x!=d[i].x||c[i].y!=d[i].y) return 0;
        return 1;
    }
    inline void main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int skx;
        cin>>skx;
        while(skx--)
        {
            cin>>n>>x;
            nn=mm=0;
            q.clear();
            for(int y=1;y<=1e9;y*=x) q[y]=1;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
                int sum=1;
                while(a[i]%x==0) a[i]/=x,sum*=x;
                if(a[i]==a[i-1]) c[nn].y+=sum;
                else c[++nn]=(node){a[i],sum};
            }
            cin>>m;
            for(int i=1;i<=m;++i)
            {
                cin>>b[i];
                int sum=1;
                while(b[i]%x==0) b[i]/=x,sum*=x;
                if(b[i]==b[i-1]) d[mm].y+=sum;
                else d[++mm]=(node){b[i],sum};
            }
            if(check()) cout<<"Yes\n";
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
5 2
1 2 2 4 2
4
1 4 4 2

1
8 3
3 9 6 3 12 12 36 12
16
9 3 2 2 2 3 4 12 4 12 4 12 4 12 4 4

*/