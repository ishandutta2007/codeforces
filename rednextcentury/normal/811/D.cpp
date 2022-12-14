#include <bits/stdc++.h>

using namespace std;
char a[103][103];
int n,m;
char u,d,l,r;
int xx,yy;
void getUD()
{
    int i=1;
    for (int j=1;j<=m;j++)
    {
        if (i+1<=n && a[i+1][j]!='*')
        {
            cout<<u<<endl;
            fflush(stdout);
            cin>>xx>>yy;
            if (xx==i)
                return;
            else
            {
                swap(u,d);
                return;
            }
        }
        if (j<m && a[i][j+1]!='*')
        {
            cout<<r<<endl;
            fflush(stdout);
            cin>>xx>>yy;
            if (yy==j+1)
                continue;
            else
            {
                swap(r,l);
                cout<<r<<endl;
                fflush(stdout);
                cin>>xx>>yy;
            }
        }
        else
            return;
    }
}
void getRL()
{
    if (yy==1)
    {
        if (xx!=1)
        {
            cout<<u<<endl;
            fflush(stdout);
            cin>>xx>>yy;
        }
        int j=1;
        for (int i=1;i<=n;i++)
        {
            if (j<m && a[i][j+1]!='*')
            {
                cout<<l<<endl;
                fflush(stdout);
                cin>>xx>>yy;
                if (yy==j)
                    return;
                else
                {
                    swap(l,r);
                    return;
                }
            }
            if (i<n && a[i+1][j]!='*')
            {
                cout<<d<<endl;
                fflush(stdout);
                cin>>xx>>yy;
            }
        }
    }
}
bool vis[101][101];
char last[101][101];

void bfs(int x,int y)
{
   queue<int> q1,q2;
   q1.push(x);
   q2.push(y);
   vis[x][y]=1;
   last[x][y]='-';
   while(!q1.empty())
   {
       x=q1.front();
       y=q2.front();
       q1.pop(),q2.pop();
       // U
       if (x-1>=1 && !vis[x-1][y] && a[x-1][y]!='*')
       {
           q1.push(x-1);
           q2.push(y);
           last[x-1][y]='U';
           vis[x-1][y]=1;
       }
       // D
       if (x+1<=n && !vis[x+1][y] && a[x+1][y]!='*')
       {
           q1.push(x+1);
           q2.push(y);
           last[x+1][y]='D';
           vis[x+1][y]=1;
       }
       // R
       if (y+1<=m && !vis[x][y+1] && a[x][y+1]!='*')
       {
           q1.push(x);
           q2.push(y+1);
           last[x][y+1]='R';
           vis[x][y+1]=1;
       }
       // L
       if (y-1>=1 && !vis[x][y-1] && a[x][y-1]!='*')
       {
           q1.push(x);
           q2.push(y-1);
           last[x][y-1]='L';
           vis[x][y-1]=1;
       }
   }
}
void printPath()
{
    int X=-1,Y=-1;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i][j]=='F')
                X=i,Y=j;
    vector<char> v;
    while(last[X][Y]!='-')
    {
        v.push_back(last[X][Y]);
        if (last[X][Y]=='U')
            X++;
        else if (last[X][Y]=='D')
            X--;
        else if (last[X][Y]=='R')
            Y--;
        else if (last[X][Y]=='L')
            Y++;
    }
    reverse(v.begin(),v.end());
    for (int i=0;i<v.size();i++)
    {
        if (v[i]=='U')
        {
            cout<<u<<endl;
            fflush(stdout);
            cin>>xx>>yy;
        }
        if (v[i]=='D')
        {
            cout<<d<<endl;
            fflush(stdout);
            cin>>xx>>yy;
        }
        if (v[i]=='R')
        {
            cout<<r<<endl;
            fflush(stdout);
            cin>>xx>>yy;
        }
        if (v[i]=='L')
        {
            cout<<l<<endl;
            fflush(stdout);
            cin>>xx>>yy;
        }
    }
}
int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            cin>>a[i][j];
    u='U',r='R',d='D',l='L';
    getUD();
    getRL();
    bfs(xx,yy);
    printPath();
}