#include<bits/stdc++.h>
using namespace std;
#define ll long long
pair<int,int> goal[2001][2001];
string ret[2001];
int a[2001][2001];
bool vis[2001][2001];
int dir[][2]={{0,1},{1,0},{0,-1},{-1,0}};
string let = "RDLU";
int n;
int sz=0;
void dfs(int x,int y,bool st=true){
    vis[x][y]=1;
    sz++;
    for (int i=0;i<4;i++){
        int X = x + dir[i][0];
        int Y = y + dir[i][1];
        if (X<0 || X>=n || Y<0 || Y>=n)continue;
        if (vis[X][Y])continue;
        if (a[X][Y]!=a[x][y])continue;
        ret[X][Y]=let[(i+2)%4];
        if (st && ret[x][y]!='X'){
            ret[x][y] = let[i];
        }
        dfs(X,Y,0);
    }
}
int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)ret[i]+='.';
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            scanf("%d%d",&goal[i][j].first,&goal[i][j].second);
            if(goal[i][j].first==-1)
                a[i][j]=-1;
            else {
                int x = goal[i][j].first, y = goal[i][j].second;
                x--,y--;
                a[i][j] = n*x+y;
                ret[x][y]='X';
            }
        }
    }
    bool ok=1;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (vis[i][j])continue;
            if (a[i][j]==-1){
                sz=0;
                dfs(i,j);
                if (sz==1)ok=0;
            } else if (ret[i][j]=='X') {
                if (goal[i][j].first != i+1 || goal[i][j].second!=j+1)ok=0;
                sz=0;
                dfs(i,j);
            }
        }
    }
    for (int i=0;i<n;i++)for (int j=0;j<n;j++)if(!vis[i][j])ok=0;
    if (!ok){
        printf("INVALID\n");
    } else {
        printf("VALID\n");
        for (int i=0;i<n;i++)printf("%s\n", ret[i].c_str());
    }
}