#include <bits/stdc++.h>
using namespace std;
int moves[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int col=1;
int siz[1000001];
char a[1001][1001];
bool has[1000001];
bool vis[1001][1001];
int color[1001][1001];
int n,m;
void bfs(int sx,int sy)
{
    queue<int> q1;
    queue<int> q2;
    q1.push(sx);
    q2.push(sy);
    int sz=0;
    vis[sx][sy]=1;
    while(!q1.empty())
    {
        int x=q1.front();
        int y=q2.front();
        sz++;
        color[x][y]=col;
        q1.pop();q2.pop();
        for (int i=0;i<4;i++)
        {
            int xx=x+moves[i][0];
            int yy=y+moves[i][1];
            if (xx<0 || yy<0 || xx>=n || yy>=m || vis[xx][yy]==1 || a[xx][yy]=='*')
                continue;
            vis[xx][yy]=1;
            q1.push(xx),q2.push(yy);
        }
    }
    siz[col]=sz;
    col++;
}
int main()
{
   scanf("%d%d",&n,&m);
   for (int i=0;i<n;i++)
   {
        scanf("%s",&a[i]);
   }
   for (int i=0;i<n;i++)
   {
       for (int j=0;j<m;j++)
       {
           if (a[i][j]!='*' && !vis[i][j])
            bfs(i,j);
       }
   }
   for (int i=0;i<n;i++)
   {
       for (int j=0;j<m;j++)
       {
           if(a[i][j]=='*')
           {
               int sum=0;
               for (int x=0;x<4;x++)
               {
                   int xx=i+moves[x][0];
                   int yy=j+moves[x][1];
                   if (xx<0 || xx>=n || yy<0 || yy>=m || a[xx][yy]=='*')
                    continue;
                   if (!has[color[xx][yy]])
                   {
                       has[color[xx][yy]]=1;
                       sum+=siz[color[xx][yy]];
                   }
               }
               for (int x=0;x<4;x++)
               {
                   int xx=i+moves[x][0];
                   int yy=j+moves[x][1];
                   if (xx<0 || xx>=n || yy<0 || yy>=m || a[xx][yy]=='*')
                    continue;
                    has[color[xx][yy]]=0;
               }
               printf("%d",(sum+1)%10);
           }
           else
                printf("%c",a[i][j]);
       }
       printf("\n");
   }
}