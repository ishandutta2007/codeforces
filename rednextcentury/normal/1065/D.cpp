#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
struct node
{
    int x;
    int y;
    int num;
    int typ;
    node(int a,int b,int c,int d)
    {
        x=a,y=b,num=c,typ=d;
    }
};
int a[100][100];
bool vis[11][11][111][11];
pair<int,int> dist[11][11][111][11];
int n;
int mv1[][2]={{2,1},{1,2},{2,-1},{-1,2},{1,-2},{-1,-2},{-2,-1},{-2,1}};
int mv2[][2]={{0,1},{1,0},{0,-1},{-1,0}};
int mv3[][2]={{1,1},{1,-1},{-1,1},{-1,-1}};
void bfs()
{
    queue<node> q;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (a[i][j]==1)
            {
                q.push(node(i,j,1,0));
                q.push(node(i,j,1,1));
                q.push(node(i,j,1,2));
                vis[i][j][1][0]=1;
                vis[i][j][1][1]=1;
                vis[i][j][1][2]=1;
                dist[i][j][1][0]={0,0};
                dist[i][j][1][1]={0,0};
                dist[i][j][1][2]={0,0};
            }
        }
    }
    while(!q.empty())
    {
        node v = q.front();
        q.pop();
        if (v.typ==0)
        {
            for (int i=1;i<=n;i++)
            {
                for (int j=0;j<4;j++)
                {
                    int X=v.x+i*mv2[j][0];
                    int Y=v.y+i*mv2[j][1];
                    if (X<0 || X>=n || Y<0 || Y>=n)
                        continue;
                    if (vis[X][Y][v.num+((a[X][Y]==(v.num+1)))][v.typ])
                    {
                        if (dist[v.x][v.y][v.num][v.typ].first+1 == dist[X][Y][v.num+((a[X][Y]==(v.num+1)))][v.typ].first)
                        {
                            dist[X][Y][v.num+((a[X][Y]==(v.num+1)))][v.typ].second=min(dist[X][Y][v.num+((a[X][Y]==(v.num+1)))][v.typ].second,dist[v.x][v.y][v.num][v.typ].second);
                        }
                        continue;
                    }vis[X][Y][v.num+((a[X][Y]==(v.num+1)))][v.typ]=1;
                dist[X][Y][v.num+((a[X][Y]==(v.num+1)))][v.typ] = dist[v.x][v.y][v.num][v.typ];
                dist[X][Y][v.num+((a[X][Y]==(v.num+1)))][v.typ].first++;
                    q.push(node(X,Y,v.num+((a[X][Y]==(v.num+1))),v.typ));
                }
            }
        }
        else if (v.typ==1)
        {
            for (int i=1;i<=n;i++)
            {
                for (int j=0;j<4;j++)
                {
                    int X=v.x+i*mv3[j][0];
                    int Y=v.y+i*mv3[j][1];
                    if (X<0 || X>=n || Y<0 || Y>=n)
                        continue;
                    if (vis[X][Y][v.num+(a[X][Y]==(v.num+1))][v.typ])
                    {
                        if (dist[v.x][v.y][v.num][v.typ].first+1 == dist[X][Y][v.num+((a[X][Y]==(v.num+1)))][v.typ].first)
                        {
                            dist[X][Y][v.num+((a[X][Y]==(v.num+1)))][v.typ].second=min(dist[X][Y][v.num+((a[X][Y]==(v.num+1)))][v.typ].second,dist[v.x][v.y][v.num][v.typ].second);
                        }
                        continue;
                    }
                vis[X][Y][v.num+((a[X][Y]==(v.num+1)))][v.typ]=1;
                dist[X][Y][v.num+((a[X][Y]==(v.num+1)))][v.typ] = dist[v.x][v.y][v.num][v.typ];
                dist[X][Y][v.num+((a[X][Y]==(v.num+1)))][v.typ].first++;
                    q.push(node(X,Y,v.num+((a[X][Y]==(v.num+1))),v.typ));
                }
            }
        }
        else
        {
            for (int j=0;j<8;j++)
            {
                int X=v.x+mv1[j][0];
                int Y=v.y+mv1[j][1];
                if (X<0 || X>=n || Y<0 || Y>=n)
                    continue;
                if (vis[X][Y][v.num+(a[X][Y]==(v.num+1))][v.typ])
                {
                    if (dist[v.x][v.y][v.num][v.typ].first+1 == dist[X][Y][v.num+((a[X][Y]==(v.num+1)))][v.typ].first)
                    {
                        dist[X][Y][v.num+((a[X][Y]==(v.num+1)))][v.typ].second=min(dist[X][Y][v.num+((a[X][Y]==(v.num+1)))][v.typ].second,dist[v.x][v.y][v.num][v.typ].second);
                    }
                    continue;
                }
                dist[X][Y][v.num+((a[X][Y]==(v.num+1)))][v.typ] = dist[v.x][v.y][v.num][v.typ];
                dist[X][Y][v.num+((a[X][Y]==(v.num+1)))][v.typ].first++;
                vis[X][Y][v.num+((a[X][Y]==(v.num+1)))][v.typ]=1;
                    q.push(node(X,Y,v.num+((a[X][Y]==(v.num+1))),v.typ));
            }
        }
        for (int i=0;i<=2;i++)
        {
            if (i!=v.typ)
            {
                if (vis[v.x][v.y][v.num][i])
                {
                    if (dist[v.x][v.y][v.num][v.typ].first+1==dist[v.x][v.y][v.num][i].first)
                        dist[v.x][v.y][v.num][i].second=min(dist[v.x][v.y][v.num][i].second,dist[v.x][v.y][v.num][v.typ].second+1);
                    continue;
                }vis[v.x][v.y][v.num][i]=1;
                dist[v.x][v.y][v.num][i]=dist[v.x][v.y][v.num][v.typ];
                dist[v.x][v.y][v.num][i].first++;
                dist[v.x][v.y][v.num][i].second++;
                q.push(node(v.x,v.y,v.num,i));
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            cin>>a[i][j];
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            for (int k=0;k<n*n;k++)
                for (int x=0;x<3;x++)
                    dist[i][j][k][x]={1e9,1e9};
    bfs();
    pair<int,int> ret={1e9,1e9};
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (a[i][j]==n*n){
                ret=min(ret,dist[i][j][n*n][0]);
                ret=min(ret,dist[i][j][n*n][1]);
                ret=min(ret,dist[i][j][n*n][2]);
            }
        }
    }
    cout<<ret.first<<' '<<ret.second<<endl;
}