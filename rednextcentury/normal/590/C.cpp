#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<int,pair<int,int> > > q;
int moves[][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool vis[1001][1001][3];
int dist[1001][1001][3];
int n,m;
char a[1010][1010];
void calc(int sx,int sy,int p)
{
    dist[sx][sy][p]=0;
    q.push(make_pair(0,make_pair(sx,sy)));
    while(!q.empty())
    {
        int d=-q.top().first;
        int x=q.top().second.first;
        int y=q.top().second.second;
        q.pop();
        if (vis[x][y][p]) continue;
        vis[x][y][p]=1;
        for (int i=0;i<4;i++)
        {
            int xx=x+moves[i][0];
            int yy=y+moves[i][1];
            if (xx<0 || yy<0 || xx>=n || yy>=m)
                continue;
            if (a[xx][yy]=='#')continue;
            if ((a[xx][yy]=='.')&& d+1<dist[xx][yy][p])
            {
                dist[xx][yy][p]=d+1;
                q.push(make_pair(-dist[xx][yy][p],make_pair(xx,yy)));
            }
            else if (a[xx][yy]>='1' && a[xx][yy]<='3')
            {
                if (d<dist[xx][yy][p])
                {
                    dist[xx][yy][p]=d;
                    q.push(make_pair(-dist[xx][yy][p],make_pair(xx,yy)));
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin>>a[i][j],dist[i][j][0]=dist[i][j][1]=dist[i][j][2]=100000000;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if ((a[i][j]!='.' && a[i][j]!='#' )&& !vis[i][j][a[i][j]-'1'])
                calc(i,j,a[i][j]-'1');
        }
    }
    int ans=1000000000;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (a[i][j]=='.')
                ans=min(ans,dist[i][j][0]+dist[i][j][1]+dist[i][j][2]-2);
            else if (a[i][j]!='#')
                ans=min(ans,dist[i][j][0]+dist[i][j][1]+dist[i][j][2]);
        }
    }
    if (ans>1000000)
        cout<<-1<<'\n';
    else
        cout<<ans<<'\n';
}