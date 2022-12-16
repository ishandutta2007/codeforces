#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,inf=1e9;
    int n,m,sum,dx,dy;
    vector<int> col[N],d[N][2];
    int c[N*2],num;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n>>m;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                int x;cin>>x;
                col[i].push_back(x);
                c[++num]=x;
                
            }
        }
        sort(c+1,c+num+1);
        num=unique(c+1,c+num+1)-c-1;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                int x=col[i][j-1];
                x=lower_bound(c+1,c+num+1,x)-c;
                d[x][0].push_back(i);
                d[x][1].push_back(j);
            }
        }
        for(int x=1;x<=100000;++x)
        {
            dx=0,dy=0;
            sort(d[x][0].begin(),d[x][0].end());
            sort(d[x][1].begin(),d[x][1].end());
            int sum1=d[x][0].size();
            if(sum1)
            {
                dx+=d[x][0][0];
                for(int j=1;j<sum1;++j)
                {
                    sum+=j*d[x][0][j]-dx;
                    dx+=d[x][0][j];
                }
            }
            int sum2=d[x][1].size();
            if(sum2)
            {
                dy+=d[x][1][0];
                for(int j=1;j<sum2;++j)
                {
                    sum+=j*d[x][1][j]-dy;
                    dy+=d[x][1][j];
                }
            }
        }
        cout<<sum<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;   
}