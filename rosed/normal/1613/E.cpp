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
    const int N=1e6+10,mod=1e9+7,inf=2e15;
    void __init(int n=2000) {}
    inline void main()
    {
        int n,m;
        cin>>n>>m;
        vector<string> a(n);
        vector ok(n,vector<bool>(m));
        int stx=-1,sty=-1;
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
            for(int j=0;j<m;++j)
            {
                if(a[i][j]=='L')
                {
                    stx=i,sty=j;
                }
            }
        }
        vector vis(n,vector<bool>(m));
        ok[stx][sty]=1;
        int dx[4]={0,-1,0,1},dy[4]={1,0,-1,0};
        typedef array<int,2> pr;
        queue<pr> q;
        q.push(pr{stx,sty});
        vis[stx][sty]=1;
        function<void(int,int)> dfs=[&](int x,int y) -> void
        {
            int sum=0;
            bool flag=0;
            for(int k=0;k<4;++k)
            {
                int tx=x+dx[k],ty=y+dy[k];
                if(tx<0||ty<0||tx>=n||ty>=m) continue;
                if(a[tx][ty]=='#') continue;
                if(ok[tx][ty]) flag=1;
                else ++sum;
            }
            if(sum<=1&&flag) ok[x][y]=1;
            for(int k=0;k<4;++k)
            {
                int tx=x+dx[k],ty=y+dy[k];
                if(tx<0||ty<0||tx>=n||ty>=m) continue;
                if(a[tx][ty]=='#'||ok[tx][ty]) continue;
                if(ok[x][y])
                {
                    q.push(pr{tx,ty});
                }
            }
        };
        while(!q.empty())
        {
            auto tmp=q.front();
            q.pop();
            dfs(tmp[0],tmp[1]);
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(a[i][j]!='.') cout<<a[i][j];
                else if(ok[i][j]) cout<<'+';
                else cout<<'.';
            }
            cout<<'\n';
        }
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
1 2 5 10

*/