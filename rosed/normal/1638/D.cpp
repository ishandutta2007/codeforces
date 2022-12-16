#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=1e6+10,mod=1e9+7,inf=2e9;
    int n,m;
    bool vis[1010][1010];
    bool vis2[1010][1010];
    int a[1010][1010];
    int top;
    struct node
    {
        int x,y,z;
    };
    node st[N];
    queue<node> q;
    inline int check(int i,int j)
    {
        if(i<1||j<1||i>n||j>m) return 0;
        int col=0;
        if(!vis[i][j]) col=a[i][j];
        else if(!vis[i+1][j]) col=a[i+1][j];
        else if(!vis[i][j+1]) col=a[i][j+1];
        else if(!vis[i+1][j+1]) col=a[i+1][j+1];
        if((col==a[i][j]||vis[i][j])&&(col==a[i+1][j+1]||vis[i+1][j+1])&&(col==a[i+1][j]||vis[i+1][j])&&(col==a[i][j+1]||vis[i][j+1])) return col;
        return 0;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n>>m;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j) cin>>a[i][j];
        for(int i=1;i<n;++i)
        {
            for(int j=1;j<m;++j)
            {
                if(check(i,j)) q.push((node){i,j,a[i][j]});
            }
        }
        while(!q.empty())
        {
            int x=q.front().x,y=q.front().y;
            if(vis2[x][y]){q.pop(); continue;}
            st[++top]=q.front();
            q.pop();
            vis2[x][y]=1;
           // cout<<x<<' '<<y<<"!!"<<endl;
            vis[x][y]=vis[x+1][y]=vis[x][y+1]=vis[x+1][y+1]=1;
            int tmp;
            if((tmp=check(x-1,y))&&!vis2[x-1][y]) q.push((node){x-1,y,tmp});
            if((tmp=check(x+1,y))&&!vis2[x+1][y]) q.push((node){x+1,y,tmp});
            if((tmp=check(x,y-1))&&!vis2[x][y-1]) q.push((node){x,y-1,tmp});
            if((tmp=check(x,y+1))&&!vis2[x][y+1]) q.push((node){x,y+1,tmp});
            if((tmp=check(x+1,y+1))&&!vis2[x+1][y+1]) q.push((node){x+1,y+1,tmp});

        }
        bool flag=1;
        for(int i=1;i<n;++i)
        {
            for(int j=1;j<m;++j)
            {
                if(!vis[i][j]) flag=0; 
            }
        }
        if(!flag) cout<<"-1\n";
        else
        {
            cout<<top<<'\n';
            while(top)
            {
                cout<<st[top].x<<' '<<st[top].y<<' '<<st[top].z<<'\n';
                --top;
            }
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