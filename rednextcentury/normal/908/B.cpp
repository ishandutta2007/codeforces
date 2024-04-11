#include<bits/stdc++.h>
using namespace std;
char a[100][100];
int mv[][2]={{0,0},{1,0},{0,1},{0,-1},{-1,0}};
int b[]={1,2,3,4};
string moves;
    int n,m;
bool check()
{
    int x=-1,y=-1;
    int X=-1,Y=-1;
    for (int i=1;i<=n;i++)
    {
         for (int j=1;j<=m;j++)
         {
             if (a[i][j]=='S')
                x=i,y=j;
             if (a[i][j]=='E')
                X=i,Y=j;
         }
    }
    for (int i=0;i<moves.size();i++)
    {
        int id = b[moves[i]-'0'];
        x+=mv[id][0];
        y+=mv[id][1];
        if (min(x,y)<=0 || x>n || y>m)
            return 0;
        if (a[x][y]=='#')
            return 0;
        if (a[x][y]=='E')
            return 1;
    }
    return 0;
}
int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            cin>>a[i][j];
    cin>>moves;
    int ret=0;
    do
    {
        if (check())ret++;
    }while(next_permutation(b,b+4));

    cout<<ret<<endl;
}