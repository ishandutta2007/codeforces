#include<bits/stdc++.h>
using namespace std;
char rot(char x)
{
    if (x=='*' || x=='+')
        return x;
    if (x=='>')
        return 'v';
    if (x=='<')
        return '^';
    if (x=='^')
        return '>';
    if (x=='v')
        return '<';
    if (x=='-')
        return '|';
    if (x=='|')
        return '-';
    if (x=='L')
        return 'U';
    if (x=='U')
        return 'R';
    if (x=='R')
        return 'D';
    if (x=='D')
        return 'L';
}
bool can(char x,int r,int dx,int dy)
{
    for (int i=0;i<r;i++)
        x=rot(x);
    if (x=='+')return 1;
    if (dx==0 && dy==-1)
        return (x=='^' || x=='|' || x=='R' || x=='L' || x=='D');
    if (dx==0 && dy==1)
        return (x=='v' || x=='|' || x=='R' || x=='L' || x=='U');
    if (dx==1 && dy==0)
        return (x=='>' || x=='-' || x=='U' || x=='L' || x=='D');
    if (dx==-1 && dy==0)
        return (x=='<' || x=='-' || x=='R' || x=='U' || x=='D');

}
bool vis[1001][1001][4];
int dist[1001][1001][4];
int n,m;
char a[2001][2000];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
void bfs(int y,int x,int r)
{
    vis[y][x][r]=1;
    dist[y][x][r]=0;
    queue<int> q1;
    queue<int> q2;
    queue<int> q3;
    q1.push(x),q2.push(y),q3.push(r);
    while(!q1.empty())
    {
        x=q1.front();
        y=q2.front();
        r=q3.front();
        q1.pop(),q2.pop(),q3.pop();
        if (!vis[y][x][(r+1)%4])
        {
            vis[y][x][(r+1)%4]=1;
            dist[y][x][(r+1)%4]=dist[y][x][r]+1;
            q1.push(x),q2.push(y),q3.push((r+1)%4);
        }
        for (int i=0;i<4;i++)
        {
            int xx=x+dx[i];
            int yy=y+dy[i];
            if (xx<0 || xx>=m || yy<0 || yy>=n)
                continue;
            if (can(a[y][x],r,dx[i],dy[i])==1 && can(a[yy][xx],r,-dx[i],-dy[i])==1 && !vis[yy][xx][r])
            {
                vis[yy][xx][r]=1;
                dist[yy][xx][r]=dist[y][x][r]+1;
                q1.push(xx),q2.push(yy),q3.push(r);
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin>>a[i][j];
    int x1,y1;
    int x2,y2;
    cin>>x1>>y1>>x2>>y2;
    x1--,x2--,y1--,y2--;
    bfs(x1,y1,0);
    int ans=1000000000;
    for (int i=0;i<4;i++)
    {
        if (vis[x2][y2][i])
            ans=min(dist[x2][y2][i],ans);
    }
    if (ans==1000000000)
        cout<<-1<<endl;
    else cout<<ans<<endl;
}