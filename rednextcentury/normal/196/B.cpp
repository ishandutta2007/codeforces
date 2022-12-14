#include<bits/stdc++.h>
using namespace std;
char a[2000][2000];
pair<int,int> vis[2000][2000];
int mv[][2]={{0,1},{1,0},{0,-1},{-1,0}};
int n,m;
bool bfs(int x,int y)
{
    vis[x][y]=make_pair(x,y);
    queue<int> q1,q2;
    q1.push(x);
    q2.push(y);
    while(!q1.empty())
    {
        x=q1.front(),y=q2.front();
        q1.pop(),q2.pop();
        for (int i=0;i<4;i++)
        {
            int X=(x+mv[i][0]);
            int Y=(y+mv[i][1]);
            if (a[(X+2000*n)%n][(Y+2000*m)%m]=='#')continue;
            if (vis[(X+2000*n)%n][(Y+2000*m)%m]!=make_pair(-1,-1) && vis[(X+2000*n)%n][(Y+2000*m)%m]!=make_pair(X,Y))
                return 1;
            if (vis[(X+2000*n)%n][(Y+2000*m)%m]==make_pair(-1,-1))
            {
                vis[(X+2000*n)%n][(Y+2000*m)%m]=make_pair(X,Y);
                q1.push(X);
                q2.push(Y);
            }
        }
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    int X,Y;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cin>>a[i][j];
            if (a[i][j]=='S')
                X=i,Y=j;
            vis[i][j]=make_pair(-1,-1);
        }
    }
    bool is=bfs(X,Y);
    if (is)cout<<"Yes\n";
    else cout<<"No\n";
}