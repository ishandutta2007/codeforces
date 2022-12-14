# include <iostream>
# include <algorithm>
# include <queue>
# include <stdio.h>
using namespace std;
char a[1001][1001];
bool vis[1001][1001];
int tim[1001][1001];
queue<int> q1;
queue<int> q2;
int moves[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int ans;
int n,m;
void bfs(int lim)
{
    while(!q1.empty())
    {
        int x=q1.front();
        int y=q2.front();
        q1.pop();
        q2.pop();
        for (int k=0;k<4;k++)
        {
            int i=x+moves[k][0];
            int j=y+moves[k][1];
            if (i<0 || i>=n || j<0 || j>=m)
                continue;
            if (vis[i][j] || a[i][j]=='T')
                continue;
            vis[i][j]=1;
            tim[i][j]=tim[x][y]+1;
            q1.push(i);
            q2.push(j);
            if (tim[i][j]<=lim && a[i][j]!='S')
                ans+=a[i][j]-'0';
        }
    }
}
int main()
{
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        scanf("%s",&a[i]);
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (a[i][j]=='S')
            {
                q1.push(i);
                q2.push(j);
                vis[i][j]=1;
                bfs(-1);
            }
        }
    }
    int x,y,lim;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (a[i][j]=='E') x=i,y=j,lim=tim[i][j];
            tim[i][j]=0;
            vis[i][j]=0;
        }
    }
    vis[x][y]=1;
    q1.push(x);
    q2.push(y);
    bfs(lim);
    cout<<ans<<endl;
}