#include<bits/stdc++.h>
using namespace std;
int L[109][109][256][2];
int F[109][109][256][2];
vector<int> v[291];
vector<char> l[213];
void dfs(int x, int y, char c, int w)
{
    F[x][y][c][w]=1;
    if(w==0)
    {
        L[x][y][c][w] = 0;
        for (int i=0; i<v[x].size(); i++)
        {
            if(l[x][i] < c) continue;
            if(!F[v[x][i]][y][l[x][i]][1-w]) dfs(v[x][i],y,l[x][i],1-w);
            L[x][y][c][w] = max(L[x][y][c][w], 1 - L[v[x][i]][y][l[x][i]][1-w]);
        }
    }
    if(w==1)
    {
        L[x][y][c][w] = 0;
        for (int i=0; i<v[y].size(); i++)
        {
            if(l[y][i] < c) continue;
            if(!F[x][v[y][i]][l[y][i]][1-w]) dfs(x,v[y][i],l[y][i],1-w);
            L[x][y][c][w] = max(L[x][y][c][w], 1 - L[x][v[y][i]][l[y][i]][1-w]);
        }
    }
}
main()
{
    int n,m;
    cin >> n >> m;
    for (int i=0; i < m; i++)
    {
        int a,b;
        char c;
        cin >>a >> b >> c;
        v[a].push_back(b);
        l[a].push_back(c);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j<=n; j++)
    for (char x ='a'; x <='a'; x++)
    {
        if(F[i][j][x][0]==0) dfs(i,j,x,0);
        if(F[i][j][x][1]==0) dfs(i,j,x,1);
    }
    for (int i = 1; i <=n ;i++)
    {
        for (int j = 1 ; j <=n; j++)
        {
            if(L[i][j]['a'][0]) cout<<"A";
            else cout<<"B";
        }
        cout << endl;
    }
}