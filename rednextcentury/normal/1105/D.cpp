#include <bits/stdc++.h>
using namespace std;
queue<pair<int,int> > q[10];
int s[11];
int can[11];
int dist[1001][1001];
char a[1001][1001];
bool vis[1001][1001];
int num[100];
int n,m;
int mv[][2]={{0,1},{1,0},{-1,0},{0,-1}};
bool bfs(int id)
{
    bool ret=false;
    can[id]+=s[id];
    while(!q[id].empty())
    {
        pair<int,int> p = q[id].front();
        int x = p.first , y = p.second;
        if (dist[x][y]==can[id])break;
        q[id].pop();
        for (int i=0;i<4;i++)
        {
            int X = x+mv[i][0];
            int Y = y+mv[i][1];
            if (X<0 || X>=n || Y<0 || Y>=m)continue;
            if (vis[X][Y] || a[X][Y]=='#')continue;
            num[id]++;
            dist[X][Y]=dist[x][y]+1;
            vis[X][Y]=1;
            ret=true;
            q[id].push({X,Y});
        }
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int p;
    cin>>n>>m>>p;
    for (int i=1;i<=p;i++)
        cin>>s[i];

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cin>>a[i][j];
            if (a[i][j]>='1' && a[i][j]<='9')
            {
                int id = a[i][j]-'0';
                q[id].push({i,j});
                num[id]++;
                vis[i][j]=1;
            }
        }
    }
    while(1)
    {
        bool ok=false;
        for (int i=1;i<=p;i++)
            ok|=bfs(i);
        if (!ok)break;
    }
    for (int i=1;i<=p;i++)
        cout<<num[i]<<' ';
    cout<<endl;

}