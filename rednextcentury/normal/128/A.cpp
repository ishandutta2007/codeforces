#include <bits/stdc++.h>
#include <queue>
using namespace std;
char a[10][10];
int vis[100][10][10];
int v[10][10];

bool bfs(int sx,int sy)
{
    queue<int> q1;
    queue<int> num;
    queue<int> q2;
    q1.push(sx);
    q2.push(sy);
    num.push(0);
    v[sx][sy]++;
    while(!q1.empty())
    {
        int x=q1.front();
        q1.pop();
        int y=q2.front();
        q2.pop();
        int now=num.front();
        num.pop();
        if (x==7 && y==7)
            return 1;
        if (!vis[now+1][x][y] && v[x][y]<8)
        {
            v[x][y]++;
            q1.push(x);
            q2.push(y);
            num.push(now+1);
        }
        if (x<7 && !vis[now+1][x+1][y] && v[x+1][y]<4 && !vis[now][x+1][y])
        {
            v[x+1][y]++;
            q1.push(x+1);
            q2.push(y);
            num.push(now+1);
        }
        if (y<7 && !vis[now+1][x][y+1] && !vis[now][x][y+1] && v[x][y+1]<4)
        {
            v[x][y+1]++;
            q1.push(x);
            q2.push(y+1);
            num.push(now+1);
        }
        if (x>0 && !vis[now+1][x-1][y] && !vis[now+1][x][y] && !vis[now][x-1][y] && v[x-1][y]<4)
        {
            v[x-1][y]++;
            q1.push(x-1);
            q2.push(y);
            num.push(now+1);
        }
        if (y>0 && !vis[now+1][x][y-1] && v[x][y-1]<4 && !vis[now][x][y-1])
        {
            v[x][y-1]++;
            q1.push(x);
            q2.push(y-1);
            num.push(now+1);
        }
        if (x>0 && y>0 && !vis[now+1][x-1][y-1] && v[x-1][y-1]<4 && !vis[now][x-1][y-1])
        {
            v[x-1][y-1]++;
            q1.push(x-1);
            q2.push(y-1);
            num.push(now+1);
        }
        if (x>0 && y<7 && !vis[now+1][x-1][y+1] && v[x-1][y+1]<4 && !vis[now][x-1][y+1])
        {
            v[x-1][y+1]++;
            q1.push(x-1);
            q2.push(y+1);
            num.push(now+1);
        }
        if (x<7 && y<7 && !vis[now+1][x+1][y+1] && v[x+1][y+1]<4 && !vis[now][x+1][y+1])
        {
            v[x+1][y+1]++;
            q1.push(x+1);
            q2.push(y+1);
            num.push(now+1);
        }
        if (x<7 && y>0 && !vis[now+1][x+1][y-1] && v[x+1][y-1]<4 && !vis[now][x+1][y-1])
        {
            v[x+1][y-1]++;
            q1.push(x+1);
            q2.push(y-1);
            num.push(now+1);
        }
    }
    return 0;
}
int main()
{
    int n=8;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cin>>a[i][j];
            if (a[i][j]=='S')
                vis[0][i][j]=1;
        }
    }
    for (int x=1;x<100;x++)
    {
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (vis[x-1][i][j])
                    vis[x][i+1][j]=1;
            }
        }
    }
    if(bfs(n-1,0))
        cout<<"WIN"<<endl;
    else
        cout<<"LOSE"<<endl;

}