#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
#define lowbit(i) ((i)&(-i))
const int mod=1e9+7,inf=1e9;
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<string> s(n+1);
    vector vis(n+1,vector<int>(m+1));
    int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
    for(int i=1;i<=n;++i)
    {
        cin>>s[i];
        s[i]="@"+s[i];
        for(int j=1;j<=m;++j)
        {
            if(s[i][j]=='#')
            {
                for(int k=0;k<4;++k)
                {
                    int x=i+dx[k],y=j+dy[k];
                    if(x<1||y<1||x>n||y>m) continue;
                    vis[x][y]=1;
                }
            }
        }
    }
    typedef array<int,2> pr;
    deque<pr> q; 
    vector pre(n+1,vector<pr>(m+1));
    for(int i=1;i<=n;++i)
    {
        if(!vis[i][1])
        {
            if(s[i][1]=='.') q.push_back(pr{i,1});
            else q.push_front(pr{i,1});
            vis[i][1]=1;
        }
    }
    int dx2[4]={-1,-1,1,1},dy2[4]={-1,1,1,-1};

    while(!q.empty())
    {
        auto tmp=q.front();
        q.pop_front();
        int x=tmp[0],y=tmp[1];
        if(y==m)
        {
            cout<<"YES\n";
            while(y!=1)
            {
                s[x][y]='#';
                int tx=pre[x][y][0],ty=pre[x][y][1];
                x=tx,y=ty;
            }
            s[x][y]='#';
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=m;++j)
                {
                    cout<<s[i][j];
                }
                cout<<'\n';
            }
            return;
        }
        for(int k=0;k<4;++k)
        {
            int tx=x+dx2[k],ty=y+dy2[k];
            if(tx<1||ty<1||tx>n||ty>m) continue;
            if(vis[tx][ty]) continue;
            vis[tx][ty]=1;
            pre[tx][ty]=pr{x,y};
            if(s[tx][ty]=='.') q.push_back(pr{tx,ty});
            else q.push_front(pr{tx,ty});
        }
    }
    cout<<"NO\n";
}
signed main()
{
    // freopen("data.in","r",stdin);
    //  freopen("red.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;cin>>T;
    while(T--) solve();
    return 0;
}
/*

*/