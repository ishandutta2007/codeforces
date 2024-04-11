#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
int dist[2001][2001];
bool vis[2001][2001];
int mv[][2]={{0,1},{1,0},{-1,0},{0,-1}};
int n,m,k;
char a[2001][2001];
void bfs(int x,int y)
{
    queue<pair<int,int> > q;
    q.push(mp(x,y));;
    vis[x][y]=1;
    dist[x][y]=0;
    while(!q.empty())
    {
        pair<int,int> v = q.front();
        x=v.first;
        y=v.second;
        q.pop();
        for (int i=0;i<4;i++)
        {
            for (int j=1;j<=k;j++)
            {
                int X=x+mv[i][0]*j;
                int Y=y+mv[i][1]*j;
                if (X<=0 || X>n || Y<=0 || Y>m)
                    break;
                if (a[X][Y]=='#')break;
                if (vis[X][Y] && dist[X][Y]<=dist[x][y])break;
                if (vis[X][Y])continue;
                vis[X][Y]=1;
                dist[X][Y]=dist[x][y]+1;
                q.push(mp(X,Y));
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    bfs(x1,y1);
    if (!vis[x2][y2])dist[x2][y2]=-1;
    cout<<dist[x2][y2]<<endl;
}